#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_DEL,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
        KC_ESC,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
        KC_LGUI,    KC_LALT,    KC_LCTL,    MO(1),      KC_SPC,     QK_BOOT,    QK_BOOT,    KC_ENT,     MO(2),      KC_RCTL,    KC_RALT,    KC_RGUI
    ),
    [1] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
        _______,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_PIPE,
        _______,    KC_EQL,     KC_MINS,    KC_PLUS,    KC_LCBR,    KC_RCBR,    KC_LBRC,    KC_RBRC,    KC_SCLN,    KC_COLN,    KC_BSLS,    _______,
        _______,    _______,    _______,    XXXXXXX,    _______,    XXXXXXX,    XXXXXXX,    _______,    XXXXXXX,    _______,    _______,    _______
    ),
    [2] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
        _______,    UG_TOGG,    UG_HUEU,    UG_SATU,    UG_VALU,    XXXXXXX,    XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   XXXXXXX,
        _______,    UG_NEXT,    UG_HUED,    UG_SATD,    UG_VALD,    XXXXXXX,    XXXXXXX,    KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     XXXXXXX,
        RGB_M_T,    _______,    _______,    XXXXXXX,    _______,    XXXXXXX,    XXXXXXX,    _______,    XXXXXXX,    _______,    _______,    _______
    )
};
