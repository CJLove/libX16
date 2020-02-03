#include <stdint.h>

// Load from specified device
extern uint16_t vload(const char *fileName, uint8_t device, uint32_t addr);

// Load from host (device 8)
extern uint16_t vload_host(const char *fileName, uint32_t addr);

// Load from SD card (device 1)
extern uint16_t vload_sd(const char *fileName, uint32_t addr);
