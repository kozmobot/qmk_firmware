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

// Shortcuts
#define S_CAD   LCTL(LALT(KC_DEL))
#define S_LOCK  LGUI(KC_L)
#define S_STOP  LCTL(KC_PAUS)

// Macro keycodes
enum custom_keycodes {
    M_COMM = SAFE_RANGE,
    M_UNCO,
    M_SEAR,
    M_TIDY,
    M_MAIL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | F10    | F5     | STOP   | 6      | 7      | 8      | 9      | 0      | -      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | TAB    | Q      | W      | E      | R      | T      | UNCO   | F9     | COMM   | Y      | U      | I      | O      | P      | \      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | =      | A      | S      | D      | F      | G      | TIDY   | MAIL   | SEAR   | H      | J      | K      | L      | ;      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LSPO   | Z      | X      | C      | V      | B      | HOME   | UP     | END    | N      | M      | ,      | .      | /      | RSPC   |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LCTL   | LGUI   | LOCK   | LALT   | FN     | SPACE  | LEFT   | DOWN   | RGHT   | BSPC   | ENT    | DEL    | F7     | F12    | RCTL   |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = { /* QWERTY */
  { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_F10,  KC_F5,   S_STOP,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    M_UNCO,  KC_F9,   M_COMM,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS },
  { KC_EQL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    M_TIDY,  M_MAIL,  M_SEAR,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT },
  { KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_HOME, KC_UP,   KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC },
  { KC_LCTL, KC_LGUI, S_LOCK,  KC_LALT, MO(_FN), KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, KC_ENT,  KC_DEL,  KC_F7,   KC_F12,  KC_RCTL },
 },

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | RESET  | F1     | F2     | F3     | F4     | F5     |        |        |        | F6     | F7     | F8     | F9     | F10    | F11    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | `      | SELECT | CALC   | MYCOMP | MAIL   |        |        |        |        |        |        | [      | ]      |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CAPS   | PREV   | PLAY   | NEXT   | STOP   |        |        |        |        |        |        | {      | }      |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | VOL-   | MUTE   | VOL+   | APP    |        |        |        |        |        |        | <      | >      |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PSCR   |        |        |        |        |        |        |        |        |        |        |        |        |        | CAD    |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = { /* FUNCTION */
  { RESET ,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11  },
  { KC_GRV,  KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, KC_LBRC, KC_RBRC, _______, _______ },
  { KC_CAPS, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, _______, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, KC_LCBR, KC_RCBR, _______, _______ },
  { _______, KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  _______, RGB_TOG, RGB_MOD, RGB_RMOD,_______, _______, KC_LT,   KC_GT,   _______, _______ },
  { KC_PSCR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, S_CAD   },
 }
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case M_MAIL:
                SEND_STRING("stop saying pickle rick!"); 
                return false; break;
            case M_TIDY:
                SEND_STRING(SS_LCTRL("k")SS_LCTRL("f")); 
                return false; break;
            case M_SEAR:
                SEND_STRING(SS_LCTRL(SS_LSFT("f"))); 
                return false; break;
            case M_COMM:
                SEND_STRING(SS_LCTRL("k")SS_LCTRL("c")); 
                return false; break;
            case M_UNCO:
                SEND_STRING(SS_LCTRL("k")SS_LCTRL("u")); 
                return false; break;
        }
    }
    return true;
};