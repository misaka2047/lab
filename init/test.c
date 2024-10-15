#include "printk.h"
# include "../arch/riscv/include/defs.h"
void test() {
    int i = 0;
    printk("sstatus: ");
    printk("%d\n", csr_read(sstatus));
    while (1) {
        if ((++i) % 100000000 == 0) {
            printk("kernel is running!\n");
            i = 0;
        }
    }
}