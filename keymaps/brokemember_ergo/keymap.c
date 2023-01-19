/* Copyright 2021 PLIP Works
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

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3
#define _LAYER4 4
#define _LAYER5 5
#define _LAYER6 6
#define _LAYER7 7




enum adelie_ortho_layers {
  _COLEMAK,
  _EXPERIMENTAL,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ARROWS,
  _NUMBERS,
  _ADJUST
};

enum adelie_ortho_keycodes {
  COLEMAK = SAFE_RANGE,
  EXPERIMENTAL,
  QWERTY,
  BACKLIT,
  EXT_PLV
};

// Main Lower and Raise
#define LOWER   MO(3)
#define RAISE   MO(4)
#define ARROWS  MO(5)
#define NUMBERS MO(6)
#define ADJUST  MO(7)
#define RSPACE  KC_SPC

// Left-hand home row mods
#define GUI_A    LGUI_T(KC_A)
#define ALT_R    LALT_T(KC_R)
#define SFT_S    LSFT_T(KC_S)
#define CTRL_T   LCTL_T(KC_T)
#define CTL_Bk   LCTL_T(KC_BSPC)
#define LSPACE   KC_SPC
#define KC_ESC   KC_ESCAPE

// Right-hand home row mods
#define CTRL_N  RCTL_T(KC_N)
#define SFT_E   RSFT_T(KC_E)
#define ALT_I   LALT_T(KC_I)
#define GUI_O   RGUI_T(KC_O)
#define OS_Meh  OSM(MOD_MEH)

// Tap Dance declarations
enum {
    TD_TAB_ESC,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Tab, twice for Escape
    [TD_TAB_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),
};

// Add tap dance item to your keymap in place of a keycode
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // ...
    TD(TD_TAB_ESC)
    // ...



/* Colemak
 * ,-------------------------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |   =  | Bksp | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |CT_Bks|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   | Enter| Home |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Et_Sft|  Up  | End  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI | Alt  |Arrows| Lower| Space|Space |Raise |OS_Meh| TT(6)|  Esc | Left | Down | Right|
 * `-------------------------------------------------------------------------------------------------'
 */
[0] = LAYOUT_ergo(
    TD(TD_TAB_ESC),  KC_Q,    KC_W,    KC_F,   KC_P,  KC_G,   KC_J,   KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_EQL,    KC_BSPC,    KC_DEL,
    CTL_Bk,  KC_A,    KC_R,    KC_S,   KC_T,  KC_D,   KC_H,   KC_N,   KC_E,    KC_I,    KC_O,    KC_QUOT,   KC_ENT,     KC_HOME,
    KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,   KC_K,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT, KC_UP,      KC_END ,
    KC_LCTL, KC_LGUI, KC_LALT, ARROWS, LOWER, LSPACE, RSPACE, RAISE,  OS_Meh,  TT(6),   KC_ESC,  KC_LEFT,   KC_DOWN,    KC_RGHT
),

/* Experimental
 * ,-------------------------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |   =  | Bksp | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |CT_Bks| GUI-A| Alt-R|Sft-S | Ctl-T|   D  |   H  |Ctl-N |Sft-E |Alt-I |Gui-O |  '   | Enter| Home |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Et_Sft|  Up  | End  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI | Alt  |Arrows| Lower| Space|Space |Raise |OS_Meh| TT(6)|  Esc | Left | Down | Right|
 * `-------------------------------------------------------------------------------------------------'
 */

[1] = LAYOUT_ergo(
    KC_TAB,  KC_Q,    KC_W,    KC_F,   KC_P,   KC_G,   KC_J,   KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_EQL,    KC_BSPC,    KC_DEL,
    CTL_Bk,  GUI_A,   ALT_R,   SFT_S,  CTRL_T, KC_D,   KC_H,   CTRL_N, SFT_E,   ALT_I,   GUI_O,   KC_QUOT,   KC_ENT,     KC_HOME,
    KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_K,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT, KC_UP,      KC_END ,
    KC_LCTL, KC_LGUI, KC_LALT, ARROWS, LOWER,  LSPACE, RSPACE, RAISE,  OS_Meh,  TT(6),   KC_ESC,  KC_LEFT,   KC_DOWN,    KC_RGHT
),


/* Qwerty
 * ,-------------------------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  -   | Bksp | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   | Enter| Home |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |  Up  | End  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI | Alt  |Arrows| Lower| Space|Space |Raise |OS_Meh| TT(6)|  Esc | Left | Down | Right|
 * `-------------------------------------------------------------------------------------------------'
 */

[2] = LAYOUT_ergo(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_MINS, KC_BSPC, KC_DEL,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_HOME,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT, KC_UP,   KC_END ,
    KC_LCTL, KC_LGUI, KC_LALT, ARROWS,  LOWER,   LSPACE,  RSPACE,  RAISE, OS_Meh,  TT(6),   KC_ESC,  KC_LEFT, KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------------—-------.
 * |Esc/~ |  F1  |  F2  |  F3  |  F4  |  N/A |   @  |  (   |   )  |   \  |   /  |   -  |   =  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |  N/A |   $  |   -  |   ?  |   [  |   ]  |   ~  | Enter| Home |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 | F11  | F12  |  N/A |   %  |   !  |   ,  |   .  |   =  |Et_Sft| PgUp | End  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Adjust| Mute | Vol- | Vol+ |  Del | PgDn |Insert|
 * `-----------------------------------------------------------------------------------+------+------'
 */

[3] = LAYOUT_ergo(
    KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,   KC_AT,   KC_LPRN, KC_RPRN, KC_BSLS, KC_SLSH, KC_MINS,   KC_EQL,  KC_DEL,
    KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_NO,   KC_DLR,  KC_MINS, KC_QUES, KC_LBRC, KC_RBRC, KC_GRV,    KC_ENT,  KC_HOME,
    KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_PERC, KC_EXLM, KC_COMM, KC_DOT,  KC_EQL,  KC_SFTENT, KC_PGUP, KC_END ,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ADJUST,  KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,    KC_PGDN, KC_INS
),


/* Raise
 * ,-------------------------------------------------------------------------------------------------.
 * |Esc/~ |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   -  |   =  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|-------------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  ~   | Enter| Home |
 * |------+------+------+------+------+------+------+------+------+------+------+------|-------------|
 * |      |   \  |   /  |   [  |   ]  | N/A  | N/A  |   -  |   ,  |   .  |   =  |      | Vol+ | End  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|-------------|
 * |      |      |      |      |Adjust|      |      |      |      |      |      | Mute | Vol- |Insert|
 * `-------------------------------------------------------------------------------------------------'
 */

[4] = LAYOUT_ergo(
    KC_GESC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_DEL,
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,  KC_ENT,  KC_HOME,
    KC_TRNS, KC_BSLS, KC_SLSH, KC_LBRC, KC_RBRC, KC_NO,   KC_NO,   KC_MINS, KC_COMM, KC_DOT,  KC_EQL,  KC_TRNS, KC_VOLU, KC_END ,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ADJUST,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_INS
),

/* Arrows
 * ,-------------------------------------------------------------------------------------------------.
 * |  Esc |      |      |      |      |      |      |  F2  |  Up  |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|-------------|
 * |      |      |      |      |      |      |  -   | Left | Down | Right|      | Home |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|-------------|
 * |      |      |      |      |      |      |      |Enter |Space | F2   |      | End  |      |      |      
 * |------+------+------+------+------+------+------+------+------+------+------+------|-------------|
 * |      |      |      |      |      |             |      |      |      |      |      |      |      |
 * `-------------------------------------------------------------------------------------------------'
 */

[5] = LAYOUT_ergo(
    KC_ESC,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F2, KC_UP,   KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_HOME, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT,  KC_SPC,  KC_F2,   KC_TRNS, KC_END,  KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* Numbers            
 * ,------------------------------------------------------------------------------------------.------.
 * |      |   7  |   8  |   9  |   *  |  =   |   {  |   }  |  Up  |  N/A |  N/A |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   4  |   5  |   6  |   /  |   $  |  N/A | Left | Down |Right | N/A  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   +  |   %  |      |  N/A |  N/A | N/A  | N/A  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   0  |   .  |Enter |   -  |      |      |TO(0) |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------+------+------'
 */

[6] = LAYOUT_ergo(
    KC_TRNS, KC_7, KC_8,   KC_9,   KC_PAST, KC_EQL,  KC_LCBR, KC_RCBR, KC_UP,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_4, KC_5,   KC_6,   KC_PSLS, KC_DLR,  KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_1, KC_2,   KC_3,   KC_PPLS, KC_PERC, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS, KC_0, KC_DOT, KC_ENT, KC_PMNS, KC_TRNS, KC_TRNS, TO(0),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v          
 * ,------------------------------------------------------------------------------------------.------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Colemk|Experi|Qwerty| TO(0)|      |      | PgUp |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |      | PgDw |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |      |      |      
 * `-----------------------------------------------------------------------------------+------+------'
 */

[7] = LAYOUT_ergo(
    KC_TRNS, RESET,   DEBUG,   RGB_MOD, RGB_TOG, RGB_HUI, RGB_HUD, RGB_SAI,     RGB_SAD,          RGB_VAI,    RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_CAPS, KC_TRNS, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, DF(0), DF(1), DF(2), TO(0),   KC_TRNS, KC_TRNS, KC_PGUP,
    KC_TRNS, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON,     TERM_OFF,         KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,          KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
};
