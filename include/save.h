#include <stdint.h>


// Save file from specified ram banks.
// TBD: For now bankStart must equal bankEnd
extern uint8_t save_bank(const char *fileName, uint8_t device, uint8_t bankStart, uint8_t bankEnd);

// Save file to host filesystem from specified ram banks
extern uint8_t save_bank_host(const char *fileName, uint8_t bankStart, uint8_t bankEnd);

// Save file to SD from specified ram banks
extern uint8_t save_bank_sd(const char *fileName, uint8_t bankStart, uint8_t bankEnd);

// Save file from ram by specified start and end address
extern uint8_t save_file(const char *fileName, uint8_t device, uint16_t addrStart, uint16_t addrEnd);

// Save file to host filesystem from ram by specified start and end address
extern uint8_t save_file_host(const char *fileName, uint16_t addrStart, uint16_t addrEnd);

// Save file to SD from ram by specified start and end address
extern uint8_t save_file_sd(const char *fileName, uint16_t addrStart, uint16_t addrEnd);


