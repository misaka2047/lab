.extern start_kernel

.extern task_init
.extern mm_init

.section .text.init
.globl _start
_start:
    la sp, boot_stack_top
    call mm_init
    call task_init
    la a0, _traps
    csrw stvec, a0
    li a0, 1 << 5
    csrs sie, a0
    rdtime a0
    li t0, 10000000
    add a0, a0, t0
    call sbi_set_timer
    csrs sstatus, 1 << 1
    j start_kernel

.section .stack.entry
.globl boot_stack_bottom
boot_stack_bottom:
    .space 4096
.globl boot_stack_top
boot_stack_top:
