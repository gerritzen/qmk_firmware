#include QMK_KEYBOARD_H

enum custom_layers {
  _QWERTY,
  _L1,
  _L2
};

// Act as Shift on hold and as CapsLock on tap
#define SFT_CPS LSFT_T(KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *  ,-----------------------------------------------------------. ,--------------.
 *  |Esc | Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  |Bspc| | 7  | 8  | 9  |
 *  |-----------------------------------------------------------| |--------------|
 *  | Tab  | A  | S  | D  | F  | G  | H  | J  | K  | L  | Enter | | 4  | 5  | 6  |
 *  |-----------------------------------------------------------| |--------------|
 *  | Shift  | Z  | X  | C  | V  | B  | N  | M  | ,  | .  |  L2 | | 1  | 2  | 3  |
 *  |-----------------------------------------------------------| |--------------|
 *  | Ctrl |Gui | Alt  |  Space  |    Space   | RAlt |RCtrl| L1 | | 0  | .  |Entr|
 *  `-----------------------------------------------------------' `--------------'
 */

[_QWERTY] = LAYOUT(
QK_GESC, KC_Q,    KC_W,    KC_E,     KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,     KC_P7, KC_P8,   KC_P9,
KC_TAB,  KC_A,    KC_S,    KC_D,     KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,        KC_ENT,           KC_P4, KC_P5,   KC_P6,
SFT_CPS, KC_Z,    KC_X,    KC_C,     KC_V,   KC_B,    KC_N,    KC_M,             KC_COMM, KC_DOT,  MO(_L2),     KC_P1, KC_P2,   KC_P3,
KC_LCTL, KC_LGUI, KC_LALT,       KC_SPC,            KC_SPC,                      KC_RALT, KC_RCTL, MO(_L1),     KC_0, KC_PDOT, KC_PENT
),

/* L1
 *  ,-----------------------------------------------------------. ,--------------.
 *  |  ~ | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  |Del | |NMLK|    | /  |
 *  |-----------------------------------------------------------| |--------------|
 *  |      | F1 | F2 | F3 | F4 | F5 | F6 |    | [  | ]  |  \    | |  - |  = | *  |
 *  |-----------------------------------------------------------| |--------------|
 *  |        | F7 | F8 | F9 |F10 |F11 |F12 | ,  | .  | /  |     | |    |    | -  |
 *  |-----------------------------------------------------------| |--------------|
 *  |      |    |      |         |            |  ;   |  ' |     | |    |    | +  |
 *  `-----------------------------------------------------------' `--------------'
 */

[_L1] = LAYOUT(
KC_GRAVE,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL, KC_NUM,  _______, KC_PSLS,
_______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, _______, KC_LBRC, KC_RBRC,          KC_BSLS, KC_MINS,  KC_EQL, KC_PAST,
_______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_COMM,          KC_DOT , KC_SLSH, _______, _______, _______, KC_PMNS,
_______, _______, _______,          _______,            _______,                 KC_SCLN, KC_QUOT, _______, _______, _______, KC_PPLS
),

/* L2
 *  ,-----------------------------------------------------------. ,--------------.
 *  |RST |    |    |    |    |    |    |    |    |    |Ins |Del | |Home|PgUp|    |
 *  |-----------------------------------------------------------| |--------------|
 *  |      |Prev|Play|Next|    |    |    |VolD|Mute|VolU|       | |End |PgDn|    |
 *  |-----------------------------------------------------------| |--------------|
 *  |        |    |    |    |    |    |    |    |    |    |     | |    | up |    |
 *  |-----------------------------------------------------------| |--------------|
 *  |EEPRST|    |      |         |            |      |    |     | |left|down| rt |
 *  `-----------------------------------------------------------' `--------------'
 */

[_L2] = LAYOUT(
QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,   KC_DEL,     KC_HOME, KC_PGUP, _______,
_______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, KC_VOLD, KC_MUTE, KC_VOLU,          _______,     KC_END,  KC_PGDN, _______,
_______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,     _______,   KC_UP, _______,
EE_CLR,  _______, _______,          _______,            _______,                 _______, _______, _______,     KC_LEFT, KC_DOWN, KC_RIGHT
)
};

void led_set_user(uint8_t usb_led) {
  // Turn LED On/Off for Caps Lock
  if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
    the50_led_on();
  } else {
    the50_led_off();
  }
}
