// Overlay struct defining zero page locations for RAM and ROM banks
#include <stdint.h>

struct _bank_control {
    uint8_t ram_bank;
    uint8_t rom_bank;
};

#define BANK_CTRL (*(volatile struct _bank_control *)0x0000)
