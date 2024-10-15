.section .text.entry

	.extern dummy
	.globl __dummy
__dummy:
	la a0, dummy
	csrw sepc, a0
	sret

.globl _traps
.extern handler_s
.equ reg_size, 0x8
.align 2

_traps:
	
	addi sp, sp, -reg_size*17

	sd ra, 0*reg_size(sp)
	sd t0, 1*reg_size(sp)
	sd t1, 2*reg_size(sp)
	sd t2, 3*reg_size(sp)
	sd a0, 4*reg_size(sp)
	sd a1, 5*reg_size(sp)
	sd a2, 6*reg_size(sp)
	sd a3, 7*reg_size(sp)
	sd a4, 8*reg_size(sp)
	sd a5, 9*reg_size(sp)
	sd a6, 10*reg_size(sp)
	sd a7, 11*reg_size(sp)
	sd t3, 12*reg_size(sp)
	sd t4, 13*reg_size(sp)
	sd t5, 14*reg_size(sp)
	sd t6, 15*reg_size(sp)
	csrr a0, sepc
	sd a0, 16*reg_size(sp)

	csrr a0, scause
	jal handler_s 
	
	ld ra, 0*reg_size(sp)
	ld t0, 1*reg_size(sp)
	ld t1, 2*reg_size(sp)
	ld t2, 3*reg_size(sp)
	ld a0, 4*reg_size(sp)
	ld a1, 5*reg_size(sp)
	ld a2, 6*reg_size(sp)
	ld a3, 7*reg_size(sp)
	ld a4, 8*reg_size(sp)
	ld a5, 9*reg_size(sp)
	ld a6, 10*reg_size(sp)
	ld a7, 11*reg_size(sp)
	ld t3, 12*reg_size(sp)
	ld t4, 13*reg_size(sp)
	ld t5, 14*reg_size(sp)
	ld t6, 16*reg_size(sp)
	csrw sepc, t6
	ld t6, 15*reg_size(sp)
	sret

.global __switch_to
__switch_to:
    sd ra, 32(a0)
    sd sp, 40(a0)
    sd s0, 48(a0)
	sd s1, 56(a0)
	sd s2, 64(a0)
	sd s3, 72(a0)
	sd s4, 80(a0)
	sd s5, 88(a0)
	sd s6, 96(a0)
	sd s7, 104(a0)
	sd s8, 112(a0)
	sd s9, 120(a0)
	sd s10, 128(a0)
	sd s11, 136(a0)

    ld ra, 32(a1)
	ld sp, 40(a1)
	ld s0, 48(a1)
	ld s1, 56(a1)
	ld s2, 64(a1)
	ld s3, 72(a1)
	ld s4, 80(a1)
	ld s5, 88(a1)
	ld s6, 96(a1)
	ld s7, 104(a1)
	ld s8, 112(a1)
	ld s9, 120(a1)
	ld s10, 128(a1)
	ld s11, 136(a1)

    ret