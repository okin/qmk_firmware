/* Copyright 2020 Niko Wenselowski
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

#define _LAYER_R 1
#define _LAYER_L 2
#define _LAYER_FUNC 3

#define LT3_TAB LT(_LAYER_FUNC, KC_TAB)


// Tap Dance declarations
enum {
    TD_SLASH_QMARK,
    TD_UML_A,
    TD_UML_U,
    TD_UML_O,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SLASH_QMARK] = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_MINS),
    [TD_UML_A] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_QUOT),
    [TD_UML_O] = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_SCLN),
    [TD_UML_U] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_LBRC),
};

#define UML_A TD(TD_UML_A)
#define UML_O TD(TD_UML_O)
#define UML_U TD(TD_UML_U)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base Layer
   * ,-------------------------------------------------------------------------.
   * | Esc |  Q  |  W  |  E  |  R  |  T  |  Y  | U/Ü |  I  | O/Ö |  P  |Bspace |
   * |-------------------------------------------------------------------------+
   * |Tab/L3| A/Ä |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  | + * |Enter |
   * |-------------------------------------------------------------------------+
   * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | # ' |
   * |-------------------------------------------------------------------------+
   * | Ctrl| Gui | Alt | App |  L2  |   Space   |  L1  |AltGr|     |     |Right|
   * `-------------------------------------------------------------------------'
   */
  LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    UML_U,   KC_I,    UML_O,   KC_P,    KC_BSPC,
    LT3_TAB, UML_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_RBRC, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  TD(TD_SLASH_QMARK), KC_BSLS,
    KC_LCTL, KC_LGUI, KC_LALT, KC_APP, MO(_LAYER_L),  KC_SPC  , MO(_LAYER_R), KC_RALT, XXXXXXX, XXXXXXX, KC_RCTL
  ),

  /* FN Layer 1
   * ,-------------------------------------------------------------------------.
   * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  | Delete|
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |  -  |  =  |  [  |  ]  |  \   |
   * |-------------------------------------------------------------------------+
   * |       | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |Capsl|      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */
  LAYOUT( /* Right */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DELETE,
    _______, RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,
    _______, _______, _______, KC_CAPS, _______,     _______,      _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),

  /* FN Layer 2
   * ,-------------------------------------------------------------------------.
   * |  ~  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  | Delete|
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |  _  |  +  |  { |  }   |  |   |
   * |-------------------------------------------------------------------------+
   * |       | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |Capsl|      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */
  LAYOUT( /* Left */
    KC_TILDE, KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_DELETE,
    _______, _______, _______, _______, _______, _______, _______, KC_UNDERSCORE, KC_PLUS, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_PIPE,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    _______, _______, _______, KC_CAPS, _______,     _______,      _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),

  /* FN Layer 3
   * ,-------------------------------------------------------------------------.
   * | Esc |Prev| Play | Next|     |     |     | PgUp|  Up | PgDn|     | Delete|
   * |-------------------------------------------------------------------------+
   * |      | Vol-| Vol+| Mute|     |     | Home| Left| Down|Right| Ins |      |
   * |-------------------------------------------------------------------------+
   * |       |     |     |     |     |     |     | End |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |     |     |     |     |
   * `-------------------------------------------------------------------------'
   */
  LAYOUT( /* Tab */
    KC_ESC,  KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, XXXXXXX, KC_PGUP, KC_UP, KC_PGDN, XXXXXXX, KC_DELETE,
    _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS, _______,
    _______, _______, _______, _______, _______, _______, XXXXXXX, KC_END, XXXXXXX, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
  ),
};

const rgblight_segment_t PROGMEM layer_r_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, HSV_CYAN}
);
const rgblight_segment_t PROGMEM layer_l_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM layer_func_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, HSV_GREEN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_func_rgb,
    layer_r_rgb,    // Overrides previous layer
    layer_l_rgb     // Overrides previous layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, _LAYER_R));
    rgblight_set_layer_state(2, layer_state_cmp(state, _LAYER_L));
    rgblight_set_layer_state(0, layer_state_cmp(state, _LAYER_FUNC));
    return state;
}
