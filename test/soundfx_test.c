#include "ym2151.h"
#include "soundfx.h"
#include <conio.h>
#include <cx16.h>
#include <stdio.h>
#include <unistd.h>

struct soundFx_t sampleFx = {
    0,0,
    0x10,   // Channel 5
    {
        YM_OP_CTRL+YM_CH_5, YM_RL_ENABLE|YM_CON_ALL_PL,
        YM_KS_AR+YM_CH_5, 0xf1,
        YM_AMS_EN_D1R+YM_CH_5, 0xa0,
        YM_D1L_RR+YM_CH_5, 0xff,
        YM_KC+YM_CH_5, YM_KC_OCT5|0xe,
        YM_KEY_ON, YM_CH_5|YM_SN_ALL,
        FX_DELAY_REG,1,
        YM_KC+YM_CH_5, YM_KC_OCT6|0x1,
        YM_KEY_ON, YM_CH_5|YM_SN_ALL,
        FX_DELAY_REG,1,
        YM_KC+YM_CH_5, YM_KC_OCT6|0x4,
        YM_KEY_ON, YM_CH_5|YM_SN_ALL,
        FX_DELAY_REG,1,
        YM_KC+YM_CH_5, YM_KC_OCT6|0x5,
        YM_KEY_ON, YM_CH_5|YM_SN_ALL,
        FX_DELAY_REG,1,
        YM_KC+YM_CH_5, YM_KC_OCT6|0x8,
        YM_KEY_ON, YM_CH_5|YM_SN_ALL,
        FX_DELAY_REG,1,
        YM_KC+YM_CH_5, YM_KC_OCT6|0xa,
        YM_KEY_ON, YM_CH_5|YM_SN_ALL,
        FX_DELAY_REG,1,
        YM_KC+YM_CH_5, YM_KC_OCT6|0xd,
        YM_KEY_ON, YM_CH_5|YM_SN_ALL,
        FX_DELAY_REG,1,
        YM_KC+YM_CH_5, YM_KC_OCT6|0xe,
        YM_KEY_ON, YM_CH_5|YM_SN_ALL,
        FX_DELAY_REG,1,
        YM_KC+YM_CH_5, YM_KC_OCT7|0x1,
        YM_KEY_ON, YM_CH_5|YM_SN_ALL,
        FX_DELAY_REG,1,
        YM_KC+YM_CH_5, YM_KC_OCT7|0x4,
        YM_KEY_ON, YM_CH_5|YM_SN_ALL,
        FX_DELAY_REG,1,
        YM_KC+YM_CH_5, YM_KC_OCT7|0x5,
        YM_KEY_ON, YM_CH_5|YM_SN_ALL,
        FX_DELAY_REG,1,
        YM_KC+YM_CH_5, YM_KC_OCT7|0x8,
        YM_KEY_ON, YM_CH_5|YM_SN_ALL,
        FX_DELAY_REG,1,
        YM_KC+YM_CH_5, YM_KC_OCT7|0xa,
        YM_KEY_ON, YM_CH_5|YM_SN_ALL,
        FX_DELAY_REG,1,
        YM_KC+YM_CH_5, YM_KC_OCT7|0xd,
        YM_KEY_ON, YM_CH_5|YM_SN_ALL,
        FX_DELAY_REG,1,
        YM_KC+YM_CH_5, YM_KC_OCT7|0xe,
        YM_KEY_ON, YM_CH_5|YM_SN_ALL,
        FX_DELAY_REG,1,
        YM_KEY_ON, YM_CH_5,
        FX_DONE_REG, 0,
    }
};

int main()
{
    uint8_t mask = 0;

    printf("Hit 'p' to play effect, 's' to preempt, 'q' to quit\n");
    while(1) {
        waitvsync();
        if (kbhit()) {
            char c = cgetc();
            if (c == 'q') {
                break;
            } else if (c == 'p') {
                mask |= 1;
            } else if (c == 's') {
                stopFx(&sampleFx);
                mask &= ~1;
            }
        }

        if (mask & 1) {
            if (playFx(&sampleFx)) {
                mask &= ~1;
            }
        }
    }
    return 0;
}