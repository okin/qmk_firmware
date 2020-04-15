#include QMK_KEYBOARD_H

#define _LAYER_DFLT 0
#define _LAYER_FUNC 1
#define _LAYER_XTRA 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* ISO 6u layout layer 0 (DE Layout shown)
	* ,-----------------------------------------------------------.
	* |Esc|1 !|2 "|3 §|4 $|5 %|6 &|7 /|8 (|9 )|0 =|ß ?|´ `| Bksp  |
	* |-----------------------------------------------------------|
	* | Tab | Q | W | E | R | T | Z | U | I | O | P | Ü |+ *|Enter|
	* |------------------------------------------------------.    |
	* | Fn1  | A | S | D | F | G | H | J | K | L | Ö | Ä |# '|    |
	* |-----------------------------------------------------------|
	* |Sft |< >| Y | X | C | V | B | N | M |, ;|. :|- _|  Shift   |
	* |-----------------------------------------------------------|
	* |Ctrl |GUI|Alt  |         Space         |Alt  |GUI|Fn2|Ctrl |
	* `-----------------------------------------------------------'
	*/

	LAYOUT_60_iso(
		KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
		KC_TAB,	KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,
		MO(_LAYER_FUNC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,
		KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(_LAYER_FUNC), MO(_LAYER_XTRA), KC_RCTL),

	LAYOUT_60_iso(
		KC_GRV, F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
		_______, KC_MPRV, KC_MPLY, KC_MNXT, _______, XXXXXXX, XXXXXXX, KC_PGUP, KC_UP, KC_PGDN, XXXXXXX, _______, _______,
		_______, KC_VOLD, KC_VOLU, KC_MUTE, _______, XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, XXXXXXX, KC_END, XXXXXXX, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______),

	LAYOUT_60_iso(
		_______, M(1), M(2), M(3), M(4), M(5), M(6), M(7), M(8), M(9), M(10), M(11), M(12), _______,
		_______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, VLK_TOG, _______, _______, _______, _______, RESET, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______),
};
