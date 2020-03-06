#include "ym2151.h"
#include "soundfx.h"

// Start or continue playing the specified sound effect when
// called from the main loop
int playFx(struct soundFx_t *fx)
{
    if (fx->delay) {
        fx->delay--;
        return 0;
    }
    else {
        uint8_t idx = fx->idx;
        uint8_t reg = fx->data[idx++];
        uint8_t value = fx->data[idx++];
        fx->idx = idx;
        if (reg == FX_DELAY_REG) {
            fx->delay = value;
            return 0;
        }
        if (reg == FX_DONE_REG) {
            fx->idx = 0;
            fx->delay = 0;
            return 1;
        }
        YMREG(reg, value);
        return 0;
    }
}

int stopFx(struct soundFx_t *fx) {
    int8_t i = 0;
    for (i = 0; i < 8; i++) {
        // If this effect uses this channel then send KEY OFF event
        if (fx->channelMask & (1 << i)) {
            YMREG(YM_KEY_ON,i);
        }
    }
    // Reset state information
    fx->idx = 0;
    fx->delay = 0;  
    return 1;  
}