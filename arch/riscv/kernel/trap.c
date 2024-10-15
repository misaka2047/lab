#include "clock.h"
#include "printk.h" 

void handler_s(unsigned long scause, unsigned long sepc) {
    if ((scause >> 63) && (scause & 0x7FFFFFFFFFFFFFFF) == 5) {
        printk("[S] Supervisor Mode Timer Interrupt\n");
        clock_set_next_event();
        return;
    }
}
