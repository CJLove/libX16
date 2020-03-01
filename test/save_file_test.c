// Sample program saving binary data from RAM at $9000
#include <cx16.h>
#include <stdio.h>
#include <stdint.h>
#include "save.h"

int main()
{
    const char *fileName = "testsave.bin";
    uint16_t addrStart = 0x9000;
    uint16_t addrEnd = 0x9100;
    uint16_t i = 0;
    uint8_t *dest = (uint8_t*)0x9000;
    uint8_t result = 0;

    // Set RAM contents prior to saving
    for (i = 0; i <= 256; i++) {
        *dest = i;
        dest++;
    }

    // Save RAM to specified file
    result = save_file_host(fileName, addrStart,addrEnd);
    printf("save_file_host(0x%04x-0x%04x) returns %d\n",addrStart,addrEnd,result);

    return 0;
}