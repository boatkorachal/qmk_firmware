// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _QWERTY,
    _LSPACE,
    _RSPACE,
    _BSPACE,
    _NAVCLN,
    _BTMLFT,
    _FNARROW,
    _MAC,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LSPACE,
  RSPACE,
  BSPACE,
};


#define __NAVCLN LT(_NAVCLN, KC_SCLN)
#define __BTMLFT MO(_BTMLFT)
#define __FNARROW MO(_FNARROW)
#define __MAC MO(_MAC)

#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_GRV LCTL_T(KC_GRV)
#define CTL_SFT LCTL_T(KC_LSFT)

#define PRVTAB SGUI(KC_LBRC)
#define NXTTAB SGUI(KC_RBRC)
#define PRVWIN SGUI(KC_GRV)
#define NXTWIN G(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_5x12(
KC_GRV  , KC_1   , KC_2   , KC_3   , KC_4  , KC_5  , KC_6  , KC_7  , KC_8     , KC_9   , KC_0    , KC_BSPC ,
KC_TAB  , KC_Q   , KC_W   , KC_E   , KC_R  , KC_T  , KC_Y  , KC_U  , KC_I     , KC_O   , KC_P    , KC_BSPC ,
CTL_ESC , KC_A   , KC_S   , KC_D   , KC_F  , KC_G  , KC_H  , KC_J  , KC_K     , KC_L   , __NAVCLN, KC_QUOT ,
KC_LSFT , KC_Z   , KC_X   , KC_C   , KC_V  , KC_B  , KC_N  , KC_M  , KC_COMM  , KC_DOT , KC_SLSH , SC_SENT ,
__BTMLFT, KC_LCTL, KC_LALT, KC_LCMD, LSPACE, KC_SPC, KC_SPC, RSPACE, __FNARROW, XXXXXXX, __MAC   , XXXXXXX
),

[_LSPACE] = LAYOUT_ortho_5x12(
_______   , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_DEL  ,
NXTWIN    , G(KC_1) , G(KC_2) , G(KC_3) , G(KC_4) , G(KC_5) , G(KC_6) , G(KC_7) , G(KC_8) , G(KC_9) , G(KC_0) , KC_DEL  ,
_______   , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , _______ ,
_______   , KC_F11  , KC_F12  , PRVTAB  , NXTTAB  , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
_______   , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
),

[_RSPACE] = LAYOUT_ortho_5x12(
_______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    , KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , _______  ,
KC_TILD  , KC_EXLM  , KC_AT    , KC_HASH  , KC_DLR   , KC_PERC  , KC_CIRC  , KC_AMPR  , KC_ASTR  , KC_MINS  , KC_EQL   , _______  ,
KC_GRV   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     , KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_BSLS  ,
_______  , KC_LCBR  , KC_RCBR  , KC_LPRN  , KC_RPRN  , KC_TILD  , KC_DOT   , KC_UNDS  , KC_PLUS  , KC_LBRC  , KC_RBRC  , _______  ,
_______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______
),

[_BSPACE] =  LAYOUT_ortho_5x12(
_______, RM_ON  , RM_NEXT , RM_HUEU , RM_SATU , RM_VALU, RM_SPDU , _______ , _______, _______ , _______, QK_BOOT ,
_______, RM_OFF , RM_PREV , RM_HUED , RM_SATD , RM_VALD, RM_SPDD , _______ , _______, _______ , _______, _______ ,
_______, RM_TOGG, _______ , _______ , _______ , _______, _______ , _______ , _______, _______ , _______, _______ ,
_______, _______, _______ , _______ , _______ , _______, _______ , _______ , _______, _______ , _______, _______ ,
_______, _______, _______ , _______ , _______ , _______, _______ , _______ , _______, _______ , _______, _______
),

[_NAVCLN] =  LAYOUT_ortho_5x12(
_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
_______ , _______ , _______ , _______ , _______ , _______ , PRVWIN  , PRVTAB  , NXTTAB  , NXTWIN  , _______ , _______ ,
_______ , _______ , _______ , _______ , _______ , _______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , _______ , _______ ,
_______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_PGDN , KC_PGUP , _______ , _______ , _______ ,
_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
),
[_BTMLFT] = LAYOUT_ortho_5x12(
_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_DEL  ,
_______ , _______ , KC_PGUP , KC_UP   , KC_PGDN , _______ , KC_PERC , KC_KP_7 , KC_KP_8 , KC_KP_9 , KC_PAST , KC_DEL  ,
_______ , _______ , KC_LEFT , KC_DOWN , KC_RGHT , _______ , KC_LPRN , KC_KP_4 , KC_KP_5 , KC_KP_6 , KC_PPLS , KC_PEQL ,
CTL_SFT , _______ , _______ , _______ , _______ , _______ , KC_RPRN , KC_KP_1 , KC_KP_2 , KC_KP_3 , KC_PMNS , _______ ,
_______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_KP_0 , KC_PDOT , XXXXXXX , KC_PSLS , _______
),

[_FNARROW] = LAYOUT_ortho_5x12(
_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
_______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , _______ ,
_______ , KC_F11  , KC_F12  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_UP   , _______ ,
_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_LEFT , KC_DOWN , KC_RGHT
),

[_MAC] = LAYOUT_ortho_5x12(
_______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_BRMD , KC_BRMU , KC_KB_VOLUME_DOWN , KC_KB_VOLUME_UP , KC_KB_MUTE ,
_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_MCTL           , KC_LPAD         , _______    ,
_______ , _______ , _______ , _______ , _______ , _______ , _______ , DM_REC2 , DM_RSTP , DM_PLY2           , _______         , _______    ,
KC_CAPS , _______ , _______ , _______ , _______ , _______ , _______ , DM_REC1 , DM_RSTP , DM_PLY1           , _______         , _______    ,
_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______           , _______         , _______
),

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LSPACE:
      if (record->event.pressed) {
        layer_on(_LSPACE);
        update_tri_layer(_LSPACE, _RSPACE, _BSPACE);
      } else {
        layer_off(_LSPACE);
        update_tri_layer(_LSPACE, _RSPACE, _BSPACE);
      }
      return false;
      break;
    case RSPACE:
      if (record->event.pressed) {
        layer_on(_RSPACE);
        update_tri_layer(_LSPACE, _RSPACE, _BSPACE);
      } else {
        layer_off(_RSPACE);
        update_tri_layer(_LSPACE, _RSPACE, _BSPACE);
      }
      return false;
      break;
    case BSPACE:
      if (record->event.pressed) {
        layer_on(_BSPACE);
      } else {
        layer_off(_BSPACE);
      }
      return false;
      break;
  }
  return true;
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [_LSPACE] = { ENCODER_CCW_CW(RM_NEXT, RM_PREV), ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
    [_RSPACE] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_BSPACE] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_NAVCLN] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_BTMLFT] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_FNARROW] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_MAC] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) }
};
#endif
