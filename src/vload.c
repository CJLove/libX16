#include <stdint.h>
#include <cbm.h>
#include <cx16.h>
#include "device.h"



uint16_t vload(const char *fileName, uint8_t device, uint32_t rawAddr)
{
    uint8_t bank = (uint8_t)(rawAddr >> 16) & 0xf;
    uint16_t addr = (uint16_t)(rawAddr & 0xffff); // baseAddr;

    cbm_k_setlfs(1,device,0);
    cbm_k_setnam(fileName);
    // Note: cbm_k_load() flag overloaded to specify the VERA bank + 2
    return (cbm_k_load(2+bank,addr) - addr);
}

uint16_t vload_host(const char *fileName, uint32_t rawAddr)
{
    return vload(fileName,HOST_DEV,rawAddr);
}

uint16_t vload_sd(const char *fileName, uint32_t rawAddr)
{
    return vload(fileName,SD_DEV,rawAddr);
}