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
**Note:** The following APIs are notional pending actual kernal support for saving RAM bank(s) to file.  Currently it isn't possible to save RAM banks.

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

## Test code
- vload_test.c builds `vload_test.prg` which loads data from TEST.BIN into VRAM in VERA banks 0 and 1 with validation.
- load_file_test.c builds `load_file_test.prg` which loads data from TEST.BIN into RAM at 0x9000
- load_bank_test.c builds `load_bank_test.prg` which loads data from TEST.BIN into Bankd RAM at 0xa000
- save_file_test.c builds `save_file_test.prg` which saves data from 0x9000-0x9100 to TESTSAVE.BIN
- **TBD**: save_bank_test.c builds `save_bank_test.prg` which saves data from RAM bank to TESTBANK.BIN