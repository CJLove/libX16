#include <stdint.h>
#include <cbm.h>
#include <cx16.h>

#define SD_DEV      1
#define HOST_DEV    8

unsigned int vload(const char *fileName, unsigned char device, uint32_t rawAddr)
{
    unsigned char bank = (unsigned char)(rawAddr >> 16) & 0xf;
    uint16_t addr = (uint16_t)(rawAddr & 0xffff); // baseAddr;

    cbm_k_setlfs(1,device,0);
    cbm_k_setnam(fileName);
    // Note: cbm_k_load() flag overloaded to specify the VERA bank + 2
    return (cbm_k_load(2+bank,addr) - addr);
}

unsigned int vload_host(const char *fileName, uint32_t rawAddr)
{
    return vload(fileName,HOST_DEV,rawAddr);
}

unsigned int vload_sd(const char *fileName, uint32_t rawAddr)
{
    return vload(fileName,SD_DEV,rawAddr);
}