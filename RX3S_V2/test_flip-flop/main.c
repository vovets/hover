#include "ch.h"
#include "hal.h"

#include "idle_thread.h"

static Thread* test_thread;

static WORKING_AREA(waTestThread, 32);

static msg_t TestThread(void* arg);

__attribute__((noreturn))
static msg_t TestThread(void* arg) {
	while (TRUE) {
	    palSetPad(IOPORT2, PORTB_LED1);
        chThdSleepMilliseconds(500);
        palClearPad(IOPORT2, PORTB_LED1);
	    chThdSleepMilliseconds(500);
	}
	chThdExit(0);
}

int main(void) {
	halInit();
	chSysInit();
	palClearPad(IOPORT2, PORTB_LED1);
	test_thread = chThdCreateStatic(waTestThread, sizeof(waTestThread), NORMALPRIO, TestThread, NULL);
	chThdSetPriority(IDLEPRIO);
    idle_thread();
}
