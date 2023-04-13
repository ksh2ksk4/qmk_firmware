#include QMK_KEYBOARD_H


enum layer_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};


/**
 * - A(KC_GRV)
 *   - Microsoft 日本語 IME で日本語入力の ON/OFF を切り替える
 *   - https://support.microsoft.com/ja-jp/windows/microsoft-%E6%97%A5%E6%9C%AC%E8%AA%9E-ime-da40471d-6b91-4042-ae8b-713a96476916#ID0EBBL=English_keyboard_(101/102_key)
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* QWERTY
   * ,------------------------------------------------.      ,------------------------------------------------.
   * |   1  |   2  |   3  |   4  |   5  |   6  | Esc  |      |      |   7  |   8  |   9  |   0  |   -  |   =  |
   * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |Lower |      |Raise |   Y  |   U  |   I  |   O  |   P  |   \  |
   * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  | Home |      | End  |   H  |   J  |   K  |   L  |   ;  |   '  |
   * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |      |      |Alt+` |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
   * | Left | Right|      | Alt  | GUI  | Bksp | Del  |      |Enter |Space |   [  |   ]  |   `  |  Up  | Down |
   * `------------------------------------------------'      `------------------------------------------------'
   */
  [_QWERTY] = LAYOUT_ortho_5x14(
    KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_ESC ,     _______  , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL ,
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , LOWER  ,     RAISE    , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
    KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_HOME,     KC_END   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , _______,     A(KC_GRV), KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
    KC_LEFT, KC_RGHT, _______, KC_LALT, KC_LGUI, KC_BSPC, KC_DEL ,     KC_ENT   , KC_SPC , KC_LBRC, KC_RBRC, KC_GRV , KC_UP  , KC_DOWN
  ),
  /* Lower
   * ,------------------------------------------------.      ,------------------------------------------------.
   * |Insert|   ~  |  F1  |  F3  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
   * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
   * |   _  |      |   !  |   @  |   #  |   $  |   %  |      |   ^  |   &  |   *  |   (  |   )  |   {  |   }  |
   * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
   * |   +  |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |   _  |   +  |   {  |   }  |      |      |
   * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
   * |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |  F12 |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |      |
   * `------------------------------------------------'      `------------------------------------------------'
   */
  [_LOWER] = LAYOUT_ortho_5x14(
    KC_INS , KC_TILD, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    KC_UNDS, _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR,
    KC_PLUS, _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, _______,
    _______, _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,     KC_F12 , _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_MUTE
  ),
  /* Raise
   * ,------------------------------------------------.      ,------------------------------------------------.
   * |      |   ~  |  F1  |  F3  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
   * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
   * |   _  |      |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   {  |   }  |
   * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
   * |   +  |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |   -  |   =  |   [  |   ]  |      |      |
   * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
   * |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |  F12 |ISO # |ISO / |      |      |      |      |
   * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |      |
   * `------------------------------------------------'      `------------------------------------------------'
   */
  [_RAISE] = LAYOUT_ortho_5x14(
    _______, KC_TILD, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    KC_UNDS, _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_LCBR, KC_RCBR,
    KC_PLUS, _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, _______, _______,
    _______, _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,     KC_F12 , KC_NUHS, KC_NUBS, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_MUTE
  ),
  [_ADJUST] = LAYOUT_ortho_5x14(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    _______, _______, QK_BOOT  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,     RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_DEL,  _______,
    _______, _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,     AG_SWAP, QWERTY,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
