#include "packet.h"

#include <hal.h>
#include <serial.h>
#include <memstreams.h>
#include <chprintf.h>
#include <stdarg.h>

extern uint8_t packetPoolArena[];
extern MemoryPool packetPool;
extern Semaphore packetPoolSem;

void packetPoolInit()
{
    uint8_t i = 0;
    for (uint8_t* buffer = packetPoolArena; i < MAX_PACKETS; ++i, buffer += PACKET_BUFFER_SIZE) {
        chPoolAdd(&packetPool, buffer);
    }
}

Packet* packetAlloc(uint8_t size, uint8_t* data)
{
    chSemWait(&packetPoolSem);
    uint8_t* buffer = (uint8_t*)chPoolAlloc(&packetPool);
    Packet* retval = (Packet*)buffer;
    retval->size = size;
    retval->seq = 0;
    if (data) {
        retval->data = data;
    } else {
        retval->data = buffer + sizeof(Packet);
    }
    return retval;
}

void packetFree(Packet* packet)
{
    chPoolFree(&packetPool, packet);
    chSemSignal(&packetPoolSem);
}

void packetSendAndFree(SerialDriver* sd, Packet* packet)
{
    size_t written = 0;
    do {
        written += sdWrite(sd, packet->data + written, packet->size - written);
    } while (packet->size - written > 0);
    /* for (uint8_t i = 0; i < packet->size; ++i) { */
    /*     sdPut(sd, packet->data[i]); */
    /* } */
    packetFree(packet);
}

void packetPrintf(Packet* packet, const char* fmt, ...)
{
    va_list ap;
    MemoryStream ms;
    BaseSequentialStream *chp;

    /* Memory stream object to be used as a string writer, reserving one
       byte for the final zero.*/
    msObjectInit(&ms, packet->data, PACKET_MAX_SIZE, 0);

    /* Performing the print operation using the common code.*/
    chp = (BaseSequentialStream *)&ms;
    va_start(ap, fmt);
    chvprintf(chp, fmt, ap);
    va_end(ap);

    packet->size = ms.eos;
}
