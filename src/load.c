#include <stdint.h>
#include <cbm.h>
#include <cx16.h>
#include "device.h"

// Load file to Banked RAM
uint16_t load_bank(const char *fileName, uint8_t device, uint8_t bank)
{
    uint16_t addr = 0xa000;

    VIA1.pra = bank;
    // Use cc65 kernal wrappers directly
    cbm_k_setlfs(1,device,0);
    cbm_k_setnam(fileName);
    return(cbm_k_load(0,addr) - addr);
}

// Load from host (device 8)
uint16_t load_bank_host(const char *fileName, uint8_t bank)
{
    return load_bank(fileName, HOST_DEV,bank);
}

// Load from SD (device 1)
uint16_t load_bank_sd(const char *fileName, uint8_t bank)
{
    return load_bank(fileName, SD_DEV,bank);
}

// Load file to specified address
uint16_t load_file(const char *fileName, uint8_t device, uint16_t addr)
{
    cbm_k_setlfs(1,device,0);
    cbm_k_setnam(fileName);
    return(cbm_k_load(0,addr) - addr);    
}

// Load from host (device 8)
uint16_t load_file_host(const char *fileName, uint16_t addr)
{
    return load_file(fileName, HOST_DEV, addr);
}

// Load from SD (device 1)
uint16_t load_file_sd(const char *fileName, uint16_t addr)
{
    return load_file(fileName, SD_DEV, addr);
}