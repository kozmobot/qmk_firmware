/* Copyright 2017 Wunder
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
#include "xd75.h"

// Fillers to make layering more clear
#define _______ KC_TRNS

// Layer shorthand
#define _QW 0
#define _FN 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | DEL    | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | \      |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ENTER  | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------+--------+--------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | RSHIFT | HOME   | UP     | END    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | LALT   | PAUSE  | FN     | SPACE  | SPACE  | F12    | F7     | F5     | F10    | F9     | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = { /* QWERTY */
  { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_MINS, KC_GRV,  KC_EQL,  KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    _______ },
  { KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_HOME, KC_DEL,  KC_PGUP, KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_ENT  },
  { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_END,  KC_UP,   KC_PGDN, KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT },
  { KC_LCTL, KC_LGUI, KC_LALT, MO(_FN), KC_SPC, KC_SPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC, KC_SPC, MO(_FN), KC_RALT, KC_RGUI, KC_RCTL },
 },

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | RESET  | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | `      | SELECT | CALC   | MYCOMP | MAIL   |        |        |        | [      | ]      | PSC    | SCRLC  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CAPS   | PREV   | PLAY   | NEXT   | STOP   |        |        |        | {      | }      | PAUSE  | NUML   |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | VOL-   | MUTE   | VOL+   | APP    |        |        |        |        |        | PGUP   | PGDN   |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = { /* FUNCTION */
  { RESET ,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______ },
  { KC_QUOT, KC_MSEL, KC_CALC, _______, KC_MAIL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { RESET,   _______, _______, MO(_FN), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
 }
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
