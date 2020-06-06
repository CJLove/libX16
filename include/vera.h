//
// Additional definitions for VERA 0.9 and ROM r37 complementing those in CC65's cx16.h
//
#include <stdint.h>

// DC_VIDEO Components
enum {
    SPRITES_ENABLED = 0x40,
    LAYER1_ENABLED  = 0x20,
    LAYER0_ENABLED  = 0x10,
    OUTPUT_DISABLED = 0x00,
    OUTPUT_VGA      = 0x01,
    OUTPUT_NTSC     = 0x02,
    OUTPUT_RGB      = 0x3
};

// DC_SCALE
enum {
    SCALE_1x = 0x80,
    SCALE_2x = 0x40,
    SCALE_4x = 0x20
};

// Lx_CONFIG
enum {
    LAYER_CONFIG_1BPP   = 0x0,
    LAYER_CONFIG_2BPP   = 0x1,
    LAYER_CONFIG_4BPP   = 0x2,
    LAYER_CONFIG_8BPP   = 0x3,
    LAYER_CONFIG_BITMAP = 0x4
};

// Lx_CONFIG - Tile Map Height
enum {
    MAP_HEIGHT_32   = (0x0 << 6),
    MAP_HEIGHT_64   = (0x1 << 6),
    MAP_HEIGHT_128  = (0x2 << 6),
    MAP_HEIGHT_256  = (0x3 << 6)
};

// Lx_CONFIG - Tile Map Width
enum {
    MAP_WIDTH_32    = (0x0 << 4),
    MAP_WIDTH_64    = (0x1 << 4),
    MAP_WIDTH_128   = (0x2 << 4),
    MAP_WIDTH_256   = (0x3 << 4)
};

// Lx_MAPBASE - Get Map Base Address from full VRAM address
#define MAP_BASE_ADDR(addr) (((uint32_t)addr) >> 9)

// Lx_TILEBASE - Get Tile Base Address from full VRAM address
#define TILE_BASE_ADDR(addr) ((((uint32_t)addr) >> 11) << 2)

// Lx_TILEBASE - Tile Width
enum {
    TILE_WIDTH_8    = 0x00,
    TILE_WIDTH_16   = 0x01,
};

// Lx_TILEBASE - Tile Height
enum {
    TILE_HEIGHT_8   = 0x00,
    TILE_HEIGHT_16  = 0x02
};

// Base Sprite attribute addresses for sprite 0 with INCR set to 1
#define SPRITE_ATTR0    0x11fc00
#define SPRITE_ATTR1    0x11fc01
#define SPRITE_ATTR2    0x11fc02
#define SPRITE_ATTR3    0x11fc03
#define SPRITE_ATTR4    0x11fc04
#define SPRITE_ATTR5    0x11fc05
#define SPRITE_ATTR6    0x11fc06
#define SPRITE_ATTR7    0x11fc07

// Sprite Attr0 - Get sprite address low from full VRAM address
#define SPRITE_ADDR_L(addr) (uint8_t)((addr >> 5) & 0xff)

// Sprite Attr1 - Sprite Mode
enum {
    SPRITE_4BPP = (0x0 << 7),
    SPRITE_8BPP = (0x1 << 7)
};

// Sprite Attr1 - Get sprite address high from full VRAM address
#define SPRITE_ADDR_H(addr) (uint8_t)((addr >> 13) & 0xf)

// Sprite Attr2 - Get sprite X low from 16-bit value
#define SPRITE_X_L(addr) ((addr) & 0xff)

// Sprite Attr3 - Get sprite X high from 16-bit value
#define SPRITE_X_H(addr) ((addr) >> 8)

// Sprite Attr4 - Get sprite Y low from 16-bit value
#define SPRITE_Y_L(addr) ((addr) & 0xff)

// Sprite Attr5 - Get sprite Y high from 16-bit value
#define SPRITE_Y_H(addr) ((addr) >> 8)

// Sprite Attr6 - Z-Depth
enum {
    SPRITE_DISABLED         = (0x0 << 2),
    SPRITE_BG_LAYER0        = (0x1 << 2),
    SPRITE_LAYER0_LAYER1    = (0x2 << 2),
    SPRITE_LAYER1           = (0x3 << 2)
};

// Sprite Attr6 - V-flip
enum {
    SPRITE_VERT_FLIP = 0x2
};

// Sprite Attr6 - H-flip
enum {
    SPRITE_HORIZ_FLIP = 0x1
};

// Sprite Attr 7 - Width
enum {
    SPRITE_WIDTH_8  = (0x0 << 4),
    SPRITE_WIDTH_16 = (0x1 << 4),
    SPRITE_WIDTH_32 = (0x2 << 4),
    SPRITE_WIDTH_64 = (0x3 << 4)
};

// Sprite Attr 7 - Sprite Height
enum {
    SPRITE_HEIGHT_8     = (0x0 << 6),
    SPRITE_HEIGHT_16    = (0x1 << 6),
    SPRITE_HEIGHT_32    = (0x2 << 6),
    SPRITE_HEIGHT_64    = (0x3 << 6)
};

// VERA Palette base address
#define VERA_PALETTE_BASE 0x1fa00
