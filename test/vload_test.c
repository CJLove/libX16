// Sample program loading binary data into RAM at A000, bank 1
#include <cx16.h>
#include <stdio.h>
#include <stdint.h>
#include <cbm.h>

int main()
{
    const char *fileName = "test.bin";
    unsigned result = 0;
    unsigned size = 0;
    unsigned addr = 0xa000;
    unsigned char *dest = (unsigned char*)addr;
    int i = 0;

    // Set bank 1
    VIA1.pra = 1;
#if 1
    // Use cc65 kernal wrappers directly
    cbm_k_setlfs(1,8,0);
    cbm_k_setnam(fileName);
    size = (cbm_k_load(0,addr) - addr);
#else
    // Use cbm_load()
    size = cbm_load(fileName,8,dest);
#endif
    if (size) {
        printf("Loaded %d bytes\n",size);

        printf("Testing bank 1 @ 0x%x:\n",addr);
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

        VIA1.pra = 2;
        printf("Dumping bank 2 @ 0x%x:\n",addr);
        for (i = 0; i < size; i++) {
            unsigned char data = *(dest+i);
            printf("%02x ",data);
        }
        printf("\n");    

    }
    return result;
}