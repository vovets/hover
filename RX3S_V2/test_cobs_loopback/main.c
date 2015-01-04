#include "ch.h"
#include "hal.h"
#include "idle_thread.h"
#include "packet.h"
#include "frame_decoder.h"

#include <string.h>


PACKET_POOL_DEFS;

static SerialConfig serialConfig = {
    UBRR_F(115200),
    USART_CHAR_SIZE_8
};

static FrameDecoder frameDecoder;

static WORKING_AREA(waRecvThread, 64);
static WORKING_AREA(waSendThread, 64);

#define MAILBOX_SIZE 1

static msg_t mailboxBuffer[MAILBOX_SIZE];

MAILBOX_DECL(mailbox, mailboxBuffer, MAILBOX_SIZE);

static void processPacket(Packet* packet)
{
    chMBPost(&mailbox, (msg_t)packet, TIME_INFINITE);
}

static void sendPacket(Packet* packet)
{
    uint8_t firstByte = packet->data[0];
    uint8_t lastByte = packet->data[packet->size - 1];
    uint8_t size = packet->size;
    uint8_t seq = packet->seq;
    packetPrintf(
                 packet,
                 "%03u %03u %03u %03u %u\n",
                 firstByte,
                 lastByte,
                 size,
                 seq,
                 frameDecoder.framingErrors);
    packetSendAndFree(&SD1, packet);
}

__attribute__((noreturn))
static msg_t recvThread(void* arg) {
    Packet* p = packetAlloc(0, NULL);
    packetPrintf(p, "recv started\n");
    packetSendAndFree(&SD1, p);
	for(;;) {
        msg_t b = sdGet(&SD1);
        if (b >= Q_OK) {
            frameDecoderProcessByte(&frameDecoder, b);
        }
	}
}

__attribute__((noreturn))
static msg_t sendThread(void* arg) {
    Packet* p = packetAlloc(0, NULL);
    packetPrintf(p, "send started\n");
    packetSendAndFree(&SD1, p);
    for (;;) {
        Packet* packet;
        chMBFetch(&mailbox, (msg_t*)&packet, TIME_INFINITE);
        sendPacket(packet);
    }
}

int main(void) {
	halInit();
	chSysInit();
	palClearPad(IOPORT2, PORTB_LED1);
    packetPoolInit();
    frameDecoderInit(&frameDecoder, &processPacket);
	sdStart(&SD1, &serialConfig);
	chThdCreateStatic(waRecvThread, sizeof(waRecvThread), NORMALPRIO + 1, recvThread, NULL);
	chThdCreateStatic(waSendThread, sizeof(waSendThread), NORMALPRIO, sendThread, NULL);

	chThdSetPriority(IDLEPRIO);
    idleThread();
}
