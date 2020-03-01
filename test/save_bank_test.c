// Sample program saving binary data from RAM bank 1
#include <cx16.h>
#include <stdio.h>
#include <stdint.h>
#include "save.h"

int main()
{
    const char *fileName = "testbank.bin";
    uint8_t bankStart = 12;
    uint8_t bankEnd = 12;
    uint16_t i = 0;
    uint8_t *dest = (uint8_t*)0xa000;
    uint8_t result = 0;

    // Set RAM bank contents prior to saving
    VIA1.pra = 12;
    for (i = 0; i <= 8192; i++) {
        if ((i % 2 ) == 0)
            *dest = 0xff;
        else
            *dest = 0xaa;        
        dest++;
    }

    // Save RAM to specified file
    result = save_bank_host(fileName, bankStart,bankEnd);
    printf("save_bank_host(%d-%d) returns %d\n",bankStart,bankEnd,result);

    return 0;
}