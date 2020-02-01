
#include <stdint.h>

// Load from specified device
extern unsigned int vload(const char *fileName, unsigned char device, uint32_t addr);

// Load from host (device 8)
extern unsigned int vload_host(const char *fileName, uint32_t addr);

// Load from SD card (device 1)
extern unsigned int vload_sd(const char *fileName, uint32_t addr);
