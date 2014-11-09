#include "ch.h"
#include "hal.h"
#include "idle_thread.h"
#include "packet.h"

#include <string.h>


PACKET_POOL_DEFS;

void sendHello(void);

void sendHello()
{
    uint8_t hello[] = "Hello,\n";
    uint8_t packets[] = "packets!\n";
    Packet* p = packetAlloc(7, hello);
    packetSend(p);
    p = packetAlloc(9, NULL);
    memcpy(p->data, packets, 9);
    packetSend(p);
}

static SerialConfig serialConfig = {
    UBRR_F(115200),
    USART_CHAR_SIZE_8
};

static WORKING_AREA(waTestThread, 32);

__attribute__((noreturn))
static msg_t testThread(void* arg) {
	while (TRUE) {
	    palSetPad(IOPORT2, PORTB_LED1);
	    sendHello();
        palClearPad(IOPORT2, PORTB_LED1);
	    chThdSleepMilliseconds(500);
	}
	chThdExit(0);
}

int main(void) {
	halInit();
	chSysInit();
	palClearPad(IOPORT2, PORTB_LED1);
    packetInitPool();
	sdStart(&SD1, &serialConfig);
	chThdCreateStatic(waTestThread, sizeof(waTestThread), NORMALPRIO, testThread, NULL);

	chThdSetPriority(IDLEPRIO);
    idleThread();
}
