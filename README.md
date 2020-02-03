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

## Test code
- vload_test.c builds `vload_test.prg` which loads data from TEST.BIN into VRAM in VERA banks 0 and 1 with validation.
- load_file_test.c builds `load_file_test.prg` which loads data from TEST.BIN into RAM at 0x9000
- load_bank_test.c builds 'load_bank_test.prg' which loads data from TEST.BIN into Bankd RAM at 0xa000