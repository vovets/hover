#include "packet.h"

#include "hal.h"
#include "serial.h"

extern uint8_t packetPoolArena[];
extern MemoryPool packetPool;
extern Semaphore packetPoolSem;

void packetInitPool()
{
    uint8_t i = 0;
    for (uint8_t* buffer = packetPoolArena; i < MAX_PACKETS; ++i, buffer += PACKET_BUFFER_SIZE) {
        chPoolAdd(&packetPool, buffer);
    }
}

Packet* packetAlloc(uint8_t size, uint8_t* data)
{
    chDbgCheck(size <= PACKET_MAX_SIZE, "packetAlloc");
    chSemWait(&packetPoolSem);
    uint8_t* buffer = (uint8_t*)chPoolAlloc(&packetPool);
    Packet* retval = (Packet*)buffer;
    retval->size = size;
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

void packetSendAndFree(Packet* packet)
{
    for (uint8_t i = 0; i < packet->size; ++i) {
        sdPut(&SD1, packet->data[i]);
    }
    packetFree(packet);
}
