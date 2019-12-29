/* Copyright 2019 jrfhoutx
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum custom_keycodes {
  M0116B = SAFE_RANGE,
};

#define CALTDEL LCTL(LALT(KC_DEL))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /* Keymap BASE: (Base Layer) Default Layer
   * ,---------------------------------------------------------------------------------.
   * |                     |  CALTDEL  |                                               |
   * `---------------------------------------------------------------------------------'
   * ,-----------------------------------------------------------. .-------------------.
   * |Esc| 1 |  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp | |MO(1)| = | /  |  * |
   * |-----------------------------------------------------------| |-------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Enter| | 7  | 8  | 9  | +  |
   * |--------------------------------------------------------|  | |-------------------|
   * |Caps   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| #  |  | | 4  | 5  | 6  | -  |
   * |-----------------------------------------------------------' |-------------------|
   * |Shift|<>|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift| Up | | 1  | 2  | 3  | Ent|
   * |-----------------------------------------------------------' `--------------|    |
   * |Ctrl | Opt | Cmd |       Space        |Cmd |Left|Right|Down| | 0       | .  |    |
   * `-----------------------------------------------------------' `-------------------'
   */
[0] = LAYOUT_m0118_iso( /* Base */
															 CALTDEL,
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_NLCK, KC_PEQL, KC_PSLS, KC_PAST,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_ENT,  KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
		KC_LCAP, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_HASH,          KC_P4,   KC_P5,   KC_P6,	KC_PMNS,
		KC_LSFT, KC_LABK, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_P1,   KC_P2,   KC_P3,   KC_PENT,
		KC_LCTL, KC_LGUI, KC_LALT,                           KC_SPC,                    LT(1, KC_RALT),   KC_LEFT, KC_RGHT, KC_DOWN, KC_P0,            KC_PDOT
),
/* Keymap Layer 1: (Layer 1) Layer 1
   * ,---------------------------------------------------------------------------------.
   * |                      |  Reset  |                                                |
   * `---------------------------------------------------------------------------------'
   * ,-----------------------------------------------------------. .-------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |       | |    |    |    |    |
   * |-----------------------------------------------------------| |-------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     | |    |    |    |    |
   * |--------------------------------------------------------|  | |-------------------|
   * |       |   |   |   |   |   |   |   |   |   |   |   |    |  | |    |    |    |    |
   * |-----------------------------------------------------------' |-------------------|
   * |     |  |   |   |   |   |   |   |   |   |   |   |     |    | |    |    |    |    |
   * |-----------------------------------------------------------' `--------------|    |
   * |     |     |     |     M0116B         |    |    |     |    | |         |    |    |
   * `-----------------------------------------------------------' `-------------------'
   */
[1] = LAYOUT_m0118_iso( /* Layer 1 */
	                                                          RESET,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,                            M0116B,                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS
    ),
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M0116B:
      if (record->event.pressed) {
        // when keycode M0116B is pressed
        SEND_STRING("Golden Delicious - M0116B - The Apple M0116/M0118 Replacement PCB.");
      } else {
        // when keycode M0116B is released
      }
      break;

  }
  return true;
};

void led_set_user(uint8_t usb_led) {

}
