#include <stdint.h>

// Soundfx "register" for delay
#define FX_DELAY_REG   2
// Soundfx "register" for end of fx
#define FX_DONE_REG    4

// Struct for a sound effect
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
extern int playFx(struct soundFx_t *fx);

// Synchronously play a specified sound effect in its own main loop
void playFxSync(struct soundFx_t *fx);

// Preempt the specified sound effect and reset state information for 
// next use of the effect
extern int stopFx(struct soundFx_t *fx);
