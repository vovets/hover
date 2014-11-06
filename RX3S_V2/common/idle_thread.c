#include "ch.h"

void idle_thread(void) {
    chRegSetThreadName("idle");
    while (TRUE) {
        port_wait_for_interrupt();
        IDLE_LOOP_HOOK();
    }
}
