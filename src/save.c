#include <stdint.h>
#include <cbm.h>
#include <cx16.h>
#include "device.h"

// Save file from ram by specified start and end address
uint8_t save_file(const char *fileName, uint8_t device, uint16_t addrStart, uint16_t addrEnd)
{
    cbm_k_setlfs(0,device,0);
    cbm_k_setnam(fileName);
    return cbm_k_save(addrStart,addrEnd);
}

// Save file to host filesystem from ram by specified start and end address
uint8_t save_file_host(const char *fileName, uint16_t addrStart, uint16_t addrEnd)
{
    return save_file(fileName, HOST_DEV, addrStart, addrEnd);
}

// Save file to SD from ram by specified start and end address
uint8_t save_file_sd(const char *fileName, uint16_t addrStart, uint16_t addrEnd)
{
    return save_file(fileName, SD_DEV, addrStart, addrEnd);
}

// Save file from specified ram banks.
uint8_t save_bank(const char *fileName, uint8_t device, uint8_t bankStart, uint8_t bankEnd)
{
    // For now restriction that bankStart == bankEnd
    if (bankStart == bankEnd) {
        // Select the starting bank
        VIA1.pra = bankStart;

        cbm_k_setlfs(0,device,0);
        cbm_k_setnam(fileName);
        return cbm_k_save(0xa000,0xc000);
    }
    // Return error code
    return 1;
}

// Save file to host filesystem from specified ram banks
uint8_t save_bank_host(const char *fileName, uint8_t bankStart, uint8_t bankEnd)
{
    return save_bank(fileName,HOST_DEV,bankStart,bankEnd);
}

// Save file to SD from specified ram banks
uint8_t save_bank_sd(const char *fileName, uint8_t bankStart, uint8_t bankEnd)
{
    return save_bank(fileName,SD_DEV,bankStart,bankEnd);
}