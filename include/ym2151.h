#include <stdint.h>

struct __YM2151 {
    uint8_t reg;
    uint8_t data;
};

#define YMCHIP (*(volatile struct __YM2151 *)0x9fe0)

// Test register
#define YM_TEST     0x1
#define YM_LFO_RESET 0x2

// KeyOn register
#define YM_KEY_ON   0x8
// KeyOn register masks
#define YM_SN_M1    0x8
#define YM_SN_C1    0x10
#define YM_SN_M2    0x20
#define YM_SN_C2    0x40
#define YM_SN_ALL   (YM_SN_M1|YM_SN_C1|YM_SN_M2|YM_SN_C2)

// Channel offsets
#define YM_CH_1     0x0
#define YM_CH_2     0x1
#define YM_CH_3     0x2
#define YM_CH_4     0x3
#define YM_CH_5     0x4
#define YM_CH_6     0x5
#define YM_CH_7     0x6
#define YM_CH_8     0x7

#define YM_NOISE_ON (YM_SN_C2|YM_CH_8)
#define YM_NOISE_OFF (YM_CH_8)

// Noise frequency register
#define YM_NE_NFRQ     0x0F
// Noise frequency masks
#define YM_NE          0x80
#define YM_NFRQ_111_9k 0x01
#define YM_NFRQ_7k     0x10
#define YM_NFRQ_3_5k   0x1F

// Clock A1 resister
#define YM_CLKA1       0x10
// Clock A2 register
#define YM_CLKA2       0x11
// Clock B register
#define YM_CLKB        0x12

// CSM register
#define YM_TIMER_CTRL  0x14
// CSM register masks
#define YM_CSM         0x80
#define YM_F_RESET_A   0x10
#define YM_F_RESET_B   0x20
#define YM_IRQEN_A     0x04
#define YM_IRQEN_B     0x08
#define YM_LOAD_A      0x01
#define YM_LOAD_B      0x02

#define YM_LFRQ        0x18

#define YM_PMD_AMD     0x19

#define YM_CT_W        0x1B
#define YM_CT1         0x40
#define YM_CT2         0x80
#define YM_W_SAWTOOTH  0x00
#define YM_W_SQUARE    0x01
#define YM_W_TRIANGLE  0x02
#define YM_W_NOISE     0x03

// Op Control registers (per channel)
#define YM_OP_CTRL     0x20

// Op Control masks
#define YM_R_ENABLE    0x80
#define YM_L_ENABLE    0x40
#define YM_RL_ENABLE   0xC0
#define YM_FB_OFF      0x00
#define YM_FB_PI_16    0x08
#define YM_FB_PI_8     0x10
#define YM_FB_PI_4     0x18
#define YM_FB_PI_2     0x20
#define YM_FB_PI       0x28
#define YM_FB_2PI      0x30
#define YM_FB_4PI      0x38
#define YM_CON_SERIAL  0x00
#define YM_CON_C1_PL   0x01
#define YM_CON_M1_PL   0x02
#define YM_CON_M2_PL   0x03
#define YM_CON_12_PL   0x04
#define YM_CON_M2CX_PL 0x05
#define YM_CON_M2C2_PL 0x06
#define YM_CON_ALL_PL  0x07

// KeyCode registers (per channel)
#define YM_KC          0x28
// KeyCode masks (octave + keycode)
#define YM_KC_OCT0     0x00
#define YM_KC_OCT1     0x10
#define YM_KC_OCT2     0x20
#define YM_KC_OCT3     0x30
#define YM_KC_OCT4     0x40
#define YM_KC_OCT5     0x50
#define YM_KC_OCT6     0x60
#define YM_KC_OCT7     0x70
#define YM_KC_C_SH     0x00
#define YM_KC_D_FL     YM_KC_C_SH
#define YM_KC_D        0x01
#define YM_KC_D_SH     0x02
#define YM_KC_E_FL     YM_KC_D_SH
#define YM_KC_E        0x04
#define YM_KC_F        0x05
#define YM_KC_F_SH     0x06
#define YM_KC_G_FL     YM_KC_F_SH
#define YM_KC_G        0x08
#define YM_KC_G_SH     0x09
#define YM_KC_A_FL     YM_KC_G_SH
#define YM_KC_A        0x0A
#define YM_KC_A_SH     0x0C
#define YM_KC_B_FL     YM_KC_A_SH
#define YM_KC_B        0x0D
#define YM_KC_C        0x0E
#define YM_KC_LOW_C    YM_KC_OCT1|YM_KC_C
#define YM_KC_MIDDLE_C YM_KC_OCT3|YM_KC_C
#define YM_KC_HIGH_C   YM_KC_OCT5|YM_KC_C

// KeyFraction registers (per channel)
#define YM_KF          0x30

// PMS/AMS registers (per channel)
#define YM_PMS_AMS     0x38

// Decay/multiplier registers (per slot)
#define YM_DT1_MUL     0x40

// Volume registers (per slot)
#define YM_TL_M1       0x60
// Volume register masks
#define YM_TL_C1       0x68
#define YM_TL_M2       0x70
#define YM_TL_C2       0x78

// Keyscale/attack registers (per slot)
#define YM_KS_AR       0x80

// AMS/Decay registers (per slot)
#define YM_AMS_EN_D1R  0xA0
// DeTune/Decay registers (per slot)
#define YM_DT2_D2R     0xC0
// Decay/release registers (per slot)
#define YM_D1L_RR      0xE0

// Macro for setting CX16 portal registers
#define YMREG(registr,value) YMCHIP.reg = registr; YMCHIP.data = value;
