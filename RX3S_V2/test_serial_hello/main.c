#include "ch.h"
#include "hal.h"
#include "chstreams.h"
#include "cobs.h"

#define ARRAYSZ(a) (sizeof(a) / sizeof(a[0]))

static Thread* recv_thread;
static Thread* send_thread;
static Thread* test_thread;

static WORKING_AREA(waRecvThread, 32);

__attribute__((noreturn))
static msg_t RecvThread(void *arg) {
	while (TRUE) {
//		chDbgAssert(0 == 1, "RecvThread(), #1", "test assert");
		msg_t msg = sdGet(&SD1);
		chDbgAssert(msg >= RDY_OK , "RecvThread(), #1", "queue error");
		msg = chMsgSend(send_thread, msg);
		chDbgAssert(msg == RDY_OK, "RecvThread(), #2", "msg send error");
	}
	chThdExit(0);
}    

static WORKING_AREA(waSendThread, 32);

__attribute__((noreturn))
static msg_t SendThread(void* arg) {
	while (TRUE) {
		Thread* thread = chMsgWait();
		chDbgAssert(thread == recv_thread, "SendThread(), #1",
				"message from unexpected thread");
		msg_t msg = chMsgGet(thread);
		sdPut(&SD1, msg);
		chMsgRelease(thread, RDY_OK);
	}
	chThdExit(0);
}

enum { MaxPacketSize = 254 };

static size_t sent_packets = 0;

void sendPacket(const uint8_t* packet, size_t size);

void sendPacket(const uint8_t* packet, size_t size)
{
    const uint8_t* end = packet + size;
    /* if (!sent_packets) { */
    /* 	sdPut(&SD1, 0); */
    /* } */
    /* for (; packet < end; ++packet) { */
    /* 	sdPut(&SD1, *packet); */
    /* } */
    for (uint8_t i = 0; i < 3; ++i) {
	msg_t msg = packet[i];
	sdPut(&SD1, msg);
	chThdSleepMilliseconds(1000);
    }
    /* sdPut(&SD1, 0); */
    /* ++sent_packets; */
}

void sendTestPackets()
{
    uint8_t message_buffer[MaxPacketSize];
    uint8_t encode_buffer[MaxPacketSize];
    for (uint8_t size = 1; size <= MaxPacketSize; ++size) {
	for (uint8_t n = 0; n < size; ++n) {
	    uint8_t byte = n % 7;
	    message_buffer[n] = byte;
	}
	/* size_t encoded_size = cobs_encode(message_buffer, size, encode_buffer); */
	/* chDbgAssert(encoded_size == size, "sendTestPackets(), #1", "encoding error"); */
	/* sendPacket(encode_buffer, encoded_size); */
	sendPacket(message_buffer, size);
    }
}

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
	    /* palTogglePad(IOPORT2, PORTB_LED1); */
	    /* sendHello(); */
        /* chThdSleepMilliseconds(2000); */
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
	/* sdStart(&SD1, &serialConfig); */
	//	recv_thread = chThdCreateStatic(waRecvThread, sizeof(waRecvThread), NORMALPRIO, RecvThread, NULL);
	//	send_thread = chThdCreateStatic(waSendThread, sizeof(waSendThread), NORMALPRIO, SendThread, NULL);
	test_thread = chThdCreateStatic(waTestThread, sizeof(waTestThread), NORMALPRIO, TestThread, NULL);

	/* chThdSetPriority(IDLEPRIO); */
	while (TRUE) {
	    /* palSetPad(IOPORT2, PORTB_LED1); */
        chThdSleepMilliseconds(500);
        /* palClearPad(IOPORT2, PORTB_LED1); */
	    /* chThdYield(); */
	}
}
