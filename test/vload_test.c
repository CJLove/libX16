// Sample program loading binary data into VERA VRAM banks 0 and 1
#include <cx16.h>
#include <stdio.h>
#include <stdint.h>
#include <cbm.h>
#include "vload.h"

#define VERA_BANK_0 0x04000
#define VERA_BANK_1 0x14000

int test_bank(uint32_t addr)
{
    const char *fileName = "test.bin";
    unsigned result = 0;
    unsigned size = vload_host(fileName,addr);
    if (size) {
        int i = 0;
        for (i = 0; i < size; i++) {
            unsigned char expected = (i % 2) ? 0xff : 0x00;
            unsigned char data = vpeek(addr+i);
            printf ("%02x ",data);
            // Validate memory content
            if (data != expected) {
                printf("\nUnexpected value at position %d",i);
                result = 0;
            }
        }
        printf("\n");
        return 1;
    }
    return 0;
}

int main()
{
    const char *fileName = "test.bin";
    unsigned result = 1;

    printf("Testing VERA bank 0:\n");
    result = test_bank(VERA_BANK_0);

    printf("Testing VERA bank 1:\n");
    result &= test_bank(VERA_BANK_1);

    if (result) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    return result;
}