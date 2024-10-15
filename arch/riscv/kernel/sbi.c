#include "stdint.h"
#include "sbi.h"

#define SBI_SYSTEM_RESET_EID 0x53525354
#define SBI_SET_TIMER_EID 0x54494d45
#define SBI_DEBUG_CONSOLE_WRITE_EID 0x4442434e
#define SBI_DEBUG_CONSOLE_READ_EID 0x4442434e
#define SBI_DEBUG_CONSOLE_WRITE_BYTE_EID 0x4442434e

#define SBI_SYSTEM_RESET_FID 0x0
#define SBI_SET_TIMER_FID 0x0
#define SBI_DEBUG_CONSOLE_WRITE_FID 0x0
#define SBI_DEBUG_CONSOLE_READ_FID 0x1
#define SBI_DEBUG_CONSOLE_WRITE_BYTE_FID 0x2

struct sbiret sbi_ecall(uint64_t eid, uint64_t fid,
                        uint64_t arg0, uint64_t arg1, uint64_t arg2,
                        uint64_t arg3, uint64_t arg4, uint64_t arg5){
    struct sbiret ret;
    register uint64_t a0 asm("a0") = (uint64_t)(arg0);
    register uint64_t a1 asm("a1") = (uint64_t)(arg1);
    register uint64_t a2 asm("a2") = (uint64_t)(arg2);
    register uint64_t a3 asm("a3") = (uint64_t)(arg3);
    register uint64_t a4 asm("a4") = (uint64_t)(arg4);
    register uint64_t a5 asm("a5") = (uint64_t)(arg5);
    register uint64_t a6 asm("a6") = (uint64_t)(fid);
    register uint64_t a7 asm("a7") = (uint64_t)(eid);
    asm volatile (
        "ecall"
        : "+r" (a0), "+r" (a1)
        : "r" (a2), "r" (a3), "r" (a4), "r" (a5), "r" (a6), "r" (a7)
        : "memory"
    );
    ret.error = a0;
    ret.value = a1;
    return ret;
}

struct sbiret sbi_debug_console_write_byte(uint8_t byte) {
    sbi_ecall(SBI_DEBUG_CONSOLE_WRITE_BYTE_EID, SBI_DEBUG_CONSOLE_WRITE_BYTE_FID, byte, 0, 0, 0, 0, 0);
}

struct sbiret sbi_system_reset(uint32_t reset_type, uint32_t reset_reason) {
    return sbi_ecall(SBI_SYSTEM_RESET_EID, SBI_SYSTEM_RESET_FID, reset_type, reset_reason, 0, 0, 0, 0);
}

struct sbiret sbi_set_timer(uint64_t stime_value) {
    return sbi_ecall(SBI_SET_TIMER_EID, SBI_SET_TIMER_FID, stime_value, 0, 0, 0, 0, 0);
}