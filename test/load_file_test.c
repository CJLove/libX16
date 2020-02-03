// Sample program loading binary data into RAM at $9000
#include <cx16.h>
#include <stdio.h>
#include <stdint.h>
#include "load.h"

int main()
{
    const char *fileName = "test.bin";
    uint16_t result = 0;
    uint16_t size = 0;
    uint16_t addr = 0x9000;
    unsigned char *dest = (unsigned char*)addr;
    int i = 0;

    size = load_file_host(fileName,addr);

    if (size) {
        printf("Loaded %d bytes\n",size);

        printf("Testing RAM @ 0x%x:\n",addr);
        for (i = 0; i < size; i++) {
            unsigned char expected = (i % 2) ? 0xff : 0x00;
            unsigned char data = *(dest+i);
            printf("%02x ",data);
            // Validate memory content
            if (data != expected) {
                printf("\nUnexpected value at position %d",i);
                result = 1;
            }
        }
        if (result) {
            printf("\nFAILED\n");
        } else {
            printf("\nPASSED\n");
        }  

    }
    return result;
}