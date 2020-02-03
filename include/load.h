#include <stdint.h>

// Load file to Banked RAM
extern uint16_t load_bank(const char *fileName, uint8_t device, uint8_t bank);

// Load from host (device 8)
extern uint16_t load_bank_host(const char *fileName, uint8_t bank);

// Load from SD (device 1)
extern uint16_t load_bank_sd(const char *fileName, uint8_t bank);

// Load file to specified address
extern uint16_t load_file(const char *fileName, uint8_t device, uint16_t addr);

// Load from host (device 8)
extern uint16_t load_file_host(const char *fileName, uint16_t addr);

// Load from SD (device 1)
extern uint16_t load_file_sd(const char *fileName, uint16_t addr);

