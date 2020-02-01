# libX16 - utility library for using CC65 with the Commander X16

## libX16 functions

### vload()
```c
unsigned vload(const char* filename, uint32_t addr);
```

Load data from a binary file to the specified VRAM address.  
- addr - 20-bit VRAM address (includes bank #)
- Returns the number of bytes read, or 0 on failure

## Test code
- vload_test.cpp builds `vload_test.prg` which loads data from TEST.BIN into VRAM in VERA banks 0 and 1 with validation.
- file_test.cpp builds `file_test.prg` which loads data from TEST.BIN into RAM bank 1 with validation.