#include <stdint.h>
#include <cbm.h>
#include <cx16.h>

unsigned int vload(const char *fileName, uint32_t rawAddr)
{
    unsigned char bank = (unsigned char)(rawAddr >> 16) & 0xf;
    uint16_t addr = (uint16_t)(rawAddr & 0xffff); // baseAddr;

    cbm_k_setlfs(1,8,0);
    cbm_k_setnam(fileName);
    // Note: cbm_k_load() flag overloaded to specify the VERA bank + 2
    return (cbm_k_load(2+bank,addr) - addr);
}