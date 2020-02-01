# libX16 - utility library for using CC65 with the Commander X16

## libX16 functions

### vload()
```c
unsigned vload(const char* filename, unsigned char device, uint32_t addr);

unsigned vload_host(const char *filename, uint32_t addr);

unsigned vload_sd(const char *filename, uint32_t addr);
```

vload() loads data from file on specified device to the specified VRAM address.

vload_host() loads data from the x16 emulator host filesystem to the specified VRAM address.

vload(sd() loads data from the SD device to the specified VRAM address.

- device - specifies the device to load from
- addr - 20-bit VRAM address (includes bank #)
- Returns the number of bytes read, or 0 on failure

## Test code
- vload_test.c builds `vload_test.prg` which loads data from TEST.BIN into VRAM in VERA banks 0 and 1 with validation.
- file_test.c builds `file_test.prg` which loads data from TEST.BIN into RAM bank 1 with validation.