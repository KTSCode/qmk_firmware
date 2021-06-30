#include "rev3.h"

void eeconfig_init_kb(void) {
#ifdef BACKLIGHT_ENABLE
    backlight_enable();
    backlight_level(5);
#endif
#ifdef RGBLIGHT_ENABLE
    rgblight_enable(); // Enable RGB by default
    rgblight_sethsv(0, 255, 255);  // Set default HSV - red hue, full saturation, full brightness
#ifdef RGBLIGHT_ANIMATIONS
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 2); // set to RGB_RAINBOW_SWIRL by default
#endif
#endif

    eeconfig_update_kb(0);
    eeconfig_init_user();
}
//void matrix_init_kb(void) {

//     // green led on
//     DDRD |= (1<<5);
//     PORTD &= ~(1<<5);
//
//    // // orange led on
//    // DDRB |= (1<<0);
//    // PORTB &= ~(1<<0);
//
//	matrix_init_user();
//};
