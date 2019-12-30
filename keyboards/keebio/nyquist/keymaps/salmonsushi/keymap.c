#include QMK_KEYBOARD_H

enum salmonsushi_layers {
  _BASE,
  _LOWER,
  _NAV,
  _NUMBER,
  _ARROW,
  _DYN,
};

enum salmonsushi_keycodes {
  BASE = SAFE_RANGE,
};

#define LOWER MO(_LOWER)
#define NAV MO(_NAV)
#define NAV_CLN LT(_NAV, KC_SCLN)
#define NUMBER MO(_NUMBER)
#define ARROW MO(_ARROW)
#define DYN MO(_DYN)

#define CTL_ESC LCTL_T(KC_ESC) // Hold = Ctrl, Tap = Esc
#define SFT_ENT RSFT_T(KC_ENT) // Hold = Shift, Tap = Enter

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT( \
    KC_GRV   , KC_1     , KC_2     , KC_3     , KC_4    , KC_5    , KC_6    , KC_7   , KC_8     , KC_9     , KC_0     , KC_BSPC  ,
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R    , KC_T    , KC_Y    , KC_U   , KC_I     , KC_O     , KC_P     , KC_BSPC  ,
    CTL_ESC  , KC_A     , KC_S     , KC_D     , KC_F    , KC_G    , KC_H    , KC_J   , KC_K     , KC_L     , NAV_CLN  , KC_QUOT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V    , KC_B    , KC_N    , KC_M   , KC_COMM  , KC_DOT   , KC_SLSH  , SFT_ENT  ,
    NUMBER   , KC_LCTL  , KC_LALT  , KC_LCMD  , KC_LCMD , KC_SPC  , KC_SPC  , LOWER  , XXXXXXX  , XXXXXXX  , DYN      , NAV
),

[_LOWER] = LAYOUT( \
    KC_TILD  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    , KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_BSPC  ,
    KC_GRV   , KC_EXLM  , KC_AT    , KC_HASH  , KC_DLR   , KC_PERC  , KC_CIRC  , KC_AMPR  , KC_ASTR  , KC_MINS  , KC_EQL   , KC_BSPC  ,
    _______  , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     , KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_BSLS  ,
    _______  , KC_LCBR  , KC_RCBR  , KC_LPRN  , KC_RPRN  , KC_TILD  , KC_DOT   , KC_UNDS  , KC_PLUS  , KC_LBRC  , KC_RBRC  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______
),

[_NAV] =  LAYOUT( \
  _______  , _______  , _______  , _______  , _______  , _______  , _______       , _______        , _______        , _______    , _______  , KC_DEL   ,
  _______  , _______  , _______  , _______  , _______  , _______  , G(S(KC_GRV))  , G(S(KC_LBRC))  , G(S(KC_RBRC))  , G(KC_GRV)  , _______  , _______  ,
  _______  , _______  , _______  , _______  , _______  , _______  , KC_LEFT       , KC_DOWN        , KC_UP          , KC_RGHT    , _______  , _______  ,
  _______  , _______  , _______  , _______  , _______  , _______  , _______       , _______        , _______        , _______    , _______  , _______  ,
  _______  , _______  , _______  , _______  , _______  , _______  , _______       , _______        , _______        , _______    , _______  , _______
),

[_NUMBER] =  LAYOUT( \
    _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , KC_PSLS  , KC_PAST  , KC_PERC  , KC_DEL  ,
    _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , KC_KP_7  , KC_KP_8  , KC_KP_9  , KC_PMNS  , _______  ,
    _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , KC_KP_4  , KC_KP_5  , KC_KP_6  , KC_PPLS  , _______  ,
    _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , KC_PDOT  , KC_KP_1  , KC_KP_2  , KC_KP_3  , KC_PEQL  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  , KC_KP_0  , KC_KP_0  , KC_PDOT  , XXXXXXX  , _______
),

[_DYN] =  LAYOUT( \
  RESET    , _______  , _______  , _______  , _______  , _______  , _______  , KC_BRMD  , KC_BRMU  , KC__VOLDOWN  , KC__VOLUP  , KC_POWER  ,
  _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______      , _______    , _______   ,
  _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______      , _______    , _______   ,
  _______  , _______  , _______  , _______  , _______  , _______  , DM_REC1  , DM_PLY1  , DM_REC2  , DM_PLY2      , DM_RSTP    , _______   ,
  _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______      , _______    , _______
)

};
