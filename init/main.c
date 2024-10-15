#include "printk.h"
#include "proc.h"
#include "mm.h"
extern void test();

int start_kernel() {

    printk("2024");
    printk(" ZJU Operating System\n");
    test();
    return 0;
}
