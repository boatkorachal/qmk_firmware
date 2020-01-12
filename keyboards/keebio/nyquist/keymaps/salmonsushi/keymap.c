#include QMK_KEYBOARD_H

enum salmonsushi_layers {
  _BASE,
  _LOWER,
  _NAV,
  _POW,
  _NUMBER,
  _FN,
  _DYN,
};

enum salmonsushi_keycodes {
  BASE = SAFE_RANGE
};

#define LOWER MO(_LOWER)
#define NAV MO(_NAV)
#define NAV_CLN LT(_NAV, KC_SCLN)
#define POW MO(_POW)
#define NUMBER MO(_NUMBER)
#define FN MO(_FN)
#define DYN MO(_DYN)

#define CTL_ESC LCTL_T(KC_ESC)
#define SFT_ENT RSFT_T(KC_ENT)
// #define PRVTAB SGUI(KC_LBRC)
// #define NXTTAB SGUI(KC_RBRC)
#define PRVTAB G(A(KC_LEFT))
#define NXTTAB G(A(KC_RGHT))
#define PRVWIN SGUI(KC_GRV)
#define NXTWIN G(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
    KC_GRV   , KC_1     , KC_2     , KC_3     , KC_4  , KC_5    , KC_6    , KC_7   , KC_8     , KC_9     , KC_0     , KC_BSPC  ,
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R  , KC_T    , KC_Y    , KC_U   , KC_I     , KC_O     , KC_P     , KC_BSPC  ,
    CTL_ESC  , KC_A     , KC_S     , KC_D     , KC_F  , KC_G    , KC_H    , KC_J   , KC_K     , KC_L     , NAV_CLN  , KC_QUOT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V  , KC_B    , KC_N    , KC_M   , KC_COMM  , KC_DOT   , KC_SLSH  , SFT_ENT  ,
    NUMBER   , KC_LCTL  , KC_LALT  , KC_LCMD  , POW   , KC_SPC  , KC_SPC  , LOWER  , FN       , XXXXXXX  , DYN      , POW
),

[_LOWER] = LAYOUT(
    _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    , KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , _______  ,
    KC_TILD  , KC_EXLM  , KC_AT    , KC_HASH  , KC_DLR   , KC_PERC  , KC_CIRC  , KC_AMPR  , KC_ASTR  , KC_MINS  , KC_EQL   , _______  ,
    KC_GRV   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     , KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_BSLS  ,
    _______  , KC_LCBR  , KC_RCBR  , KC_LPRN  , KC_RPRN  , KC_TILD  , KC_DOT   , KC_UNDS  , KC_PLUS  , KC_LBRC  , KC_RBRC  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______
),

[_NAV] = LAYOUT(
    _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , PRVWIN   , PRVTAB   , NXTTAB   , NXTWIN   , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______
),

[_POW] = LAYOUT(
    _______    , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  ,
    G(KC_GRV)  , G(KC_1)  , G(KC_2)  , G(KC_3)  , G(KC_4)  , G(KC_5)  , G(KC_6)  , G(KC_7)  , G(KC_8)  , G(KC_9)  , G(KC_0)  , KC_DEL   ,
    _______    , _______  , PRVTAB   , KC_K     , KC_J     , NXTTAB   , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  , _______  ,
    _______    , DM_PLY1  , DM_PLY2  , KC_PGUP  , KC_PGDN  , _______  , _______  , _______  , _______  , _______  , _______  , _______  ,
    _______    , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______
),

[_FN] = LAYOUT(
    _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    , KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , KC_F12   ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , KC_UP    , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , KC_LEFT  , KC_DOWN  , KC_RGHT
),

[_DYN] = LAYOUT(
    RESET    , _______  , _______  , _______  , _______  , _______  , _______  , KC_BRMD  , KC_BRMU  , KC__VOLDOWN  , KC__VOLUP  , KC_POWER  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______      , KC__MUTE   , _______   ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______      , _______    , _______   ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  , DM_REC1  , DM_REC2  , DM_RSTP      , _______    , _______   ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______      , _______    , _______
),

[_NUMBER] = LAYOUT(
    _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , KC_UP    , _______  , _______  , KC_PERC  , KC_KP_7  , KC_KP_8  , KC_KP_9  , KC_PAST  , _______  ,
    _______  , _______  , KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  , KC_LPRN  , KC_KP_4  , KC_KP_5  , KC_KP_6  , KC_PPLS  , KC_PEQL  ,
    _______  , _______  , _______  , _______  , _______  , _______  , KC_RPRN  , KC_KP_1  , KC_KP_2  , KC_KP_3  , KC_PMNS  , _______  ,
    _______  , _______  , _______  , _______  , KC_LOCK  , _______  , _______  , KC_KP_0  , XXXXXXX  , KC_PDOT  , KC_PSLS  , _______
),

};
