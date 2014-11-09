#include "ch.h"
#include "hal.h"
#include "idle_thread.h"

#include "serial.h"


static Thread* test_thread;

void sendPacket(const uint8_t* packet, size_t size);

void sendPacket(const uint8_t* packet, size_t size)
{
    for (uint8_t i = 0; i < size; ++i) {
        sdPut(&SD1, packet[i]);
    }
}

void sendHello(void);

void sendHello()
{
    uint8_t message_buffer[] = "Hello!\n";
    sendPacket(message_buffer, 7);
}

static SerialConfig serialConfig = {
    UBRR_F(115200),
    USART_CHAR_SIZE_8
};

static WORKING_AREA(waTestThread, 32);

__attribute__((noreturn))
static msg_t TestThread(void* arg) {
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
	sdStart(&SD1, &serialConfig);
	test_thread = chThdCreateStatic(waTestThread, sizeof(waTestThread), NORMALPRIO, TestThread, NULL);

	chThdSetPriority(IDLEPRIO);
    idle_thread();
}
