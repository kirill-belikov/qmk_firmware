#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,
        KC_ESC,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,
        KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LCTL,    KC_SPC,     QK_BOOT
    )
};
