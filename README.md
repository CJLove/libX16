# libX16 - utility library for using CC65 with the Commander X16

## libX16 functions

### Load VRAM
```c
uint16_t vload(const char* filename, uint8_t device, uint32_t addr);

uint16_t vload_host(const char *filename, uint32_t addr);

uint16_t vload_sd(const char *filename, uint32_t addr);
```

vload() loads data from file on specified device to the specified VRAM address.

vload_host() loads data from the x16 emulator host filesystem to the specified VRAM address.

vload_sd() loads data from the SD device to the specified VRAM address.

- device - specifies the device to load from
- addr - 20-bit VRAM address (includes bank #)
- Returns the number of bytes read, or 0 on failure

### Load RAM Bank
```c
uint16_t load_bank(const char* filename, uint8_t device, uint8_t bank);

uint16_t load_bank_host(const char* filename, uint8_t bank);

uint16_t load_bank_sd(const char* filename, uint8_t bank);
```
load_bank() loads data from file on specified device to the specified bank of RAM (0xa000)

load_bank_host() loads data from the x16 emulator host filesystem to the specified bank

load_bank_sd() loads data from the SD device to the specified bank

- device - specifies the device to load from
- bank - specifies the RAM bank

### Load RAM
```c
uint16_t load_file(const char *filename, uint8_t device, uint16_t addr);

uint16_t load_file_host(const char *filename, uint16_t addr);

uint16_t load_file_sd(const char *filename, uint16_t addr);
```

load_file() loads data from file on specified device to specified address

load_file_host() loads data from the x16 emulator host filesystem to the specified address

load_file_sd() loads data from the SD device to the specified address

- device - specifies the device to load from
- addr - specifies the RAM address

### Save RAM
```c
uint8_t save_file(const char *fileName, uint8_t device, uint16_t addrStart, uint16_t addrEnd);

uint8_t save_file_host(const char *fileName, uint16_t addrStart, uint16_t addrEnd);

uint8_t save_file_sd(const char *fileName, uint16_t addrStart, uint16_t addrEnd);
```

save_file() saves data from the specified address range to a file on the specified device

save_file_host() saves data from the specified address range to a file on the X16 emulator host filesystem

save_file_sd() saves data from the specified address range to a file on the SD device

- device - specifies the device to save to
- addrStart - starting address in memory
- addrEnd - ending address in memory
- Returns 0 for success, non-zero for failure

### Save RAM Bank(s)
**Note:** The following APIs are notional pending actual kernal support for saving RAM bank(s) to file. See https://github.com/commanderx16/x16-rom/issues/136 for the kernal issue. Currently it isn't possible to save RAM banks.

```c
uint8_t save_bank(const char *fileName, uint8_t device, uint8_t bankStart, uint8_t bankEnd);

uint8_t save_bank_host(const char *fileName, uint8_t bankStart, uint8_t bankEnd);

uint8_t save_bank_sd(const char *fileName, uint8_t bankStart, uint8_t bankEnd);
```
save_bank() saves data from the specified banks of RAM to a file on the specified device

save_bank_host() saves data from the specified banks of RAM to a file on the X16 emulator host filesystem

save_bank_sd() saves data from the specified banks of RAM to a file on the SD device

- device - specifies the device to save to
- bankStart - starting bank (0-255)
- bankEnd - ending bank (0-255)
- Returns 0 for success, non-zero for failure

### Sound effects and YM2151 support
```c
#include "ym2151.h"
void YMREG(reg,value);
```
YMREG() is a macro which sets a specified YM2151 register to a specified value. See [here](https://http://www.cx5m.net/fmunit.htm) for register details.

```c
#include "soundfx.h"
struct soundFx_t {
    // Index into the sound effect data
    uint16_t idx;
    // Delay count (0 means to process the next data register/value)
    uint8_t delay;
    // Bitmask specifying which channels are used in case of preemption
    uint8_t channelMask;
    // Sound fx data consisting of 8-bit YM-2151 register and 8-bit value
    // Last register value must be of type FX_DONE_REG
    uint8_t data[];
};

// Start/continue playing a specified sound effect when called periodically from the main loop
// returns 1 when sound effect is complete
int playFx(struct soundFx_t *fx);

// Synchronously play a specified sound effect in its own main loop
void playFxSync(struct soundFx_t *fx);

// Preempt the specified sound effect and reset state information for 
// next use of the effect
int stopFx(struct soundFx_t *fx);
```

### VERA Definitions
The `vera.h` header file adds a number of constant definitions and convenience macros which complement those in [cx16.h](https://github.com/cc65/cc65/blob/master/include/cx16.h) from CC65.

```c
// Get the L1 or L2 Map Base Address from a full VRAM address
uint8_t MAP_BASE_ADDR(uint32_t addr);

// Get the L1 or L2 Tile Base Address from a full VRAM address
uint8_t TILE_BASE_ADDR(uint32_t addr);
```
The `MAP_BASE_ADDR()` and `TILE_BASE_ADDR()` macros handle converting VRAM addresses to 8-bit values suitable for the L1 or L2 base address registers.

```c
// Get the sprite address (low) from a full VRAM address
uint8_t SPRITE_ADDR_L(uint32_t addr);

// Get the sprite address (high) from a full VRAM address
uint8_t SPRITE_ADDR_H(uint32_t addr);
```
The `SPRITE_ADDR_L()` and `SPRITE_ADDR_H()` macros handle converting VRAM addresses to 8-bit values suitable for Sprite address registers. 

```c
// Get sprite X low from 16-bit value
uint8_t SPRITE_X_L(uint16_t value);

// Get sprite X high from 16-bit value
uint8_t SPRITE_X_H(uint16_t value);

// Get sprite Y low from 16-bit value
uint8_t SPRITE_Y_L(uint16_t value);

// Get sprite Y high from 16-bit value
uint8_t SPRITE_Y_H(uint16_t value);
```
These macros handle converting sprite X/Y coordinates in 16-bit values into separate 8-bit values suitable for the Sprite registers for X and Y coordinates.

## Test code
- vload_test.c builds `vload_test.prg` which loads data from TEST.BIN into VRAM in VERA banks 0 and 1 with validation.
- load_file_test.c builds `load_file_test.prg` which loads data from TEST.BIN into RAM at 0x9000
- load_bank_test.c builds `load_bank_test.prg` which loads data from TEST.BIN into Bankd RAM at 0xa000
- save_file_test.c builds `save_file_test.prg` which saves data from 0x9000-0x9100 to TESTSAVE.BIN
- **TBD**: save_bank_test.c builds `save_bank_test.prg` which saves data from RAM bank to TESTBANK.BIN
- soundfx_test.c builds `soundfx_test.prg` which uses `playFx()` and `stopFx()` to play a sound effect