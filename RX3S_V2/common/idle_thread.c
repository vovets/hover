#include "ch.h"

void idleThread(void) {
    chRegSetThreadName("idle");
    while (TRUE) {
        port_wait_for_interrupt();
        IDLE_LOOP_HOOK();
    }
}
