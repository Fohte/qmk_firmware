#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "pubg.h"

#define DVORAK 0
#define MOVE 1
#define NUM_HOME 2
#define SYMBOL 3
#define PUBG 4
#define PUBG2 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Dvorak
[DVORAK] = KEYMAP(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO,
    KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_LBRC,
    KC_LCTL, KC_A, KC_O, KC_E, KC_U, KC_I,
    KC_LSFT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_BSLS,
    KC_NO, KC_NO, KC_LALT, MO(NUM_HOME), KC_LGUI,
    KC_NO, KC_NO,
    KC_NO,
    KC_SPC, KC_BSPC, LALT(KC_SPACE),

    RESET, KC_6, KC_7, KC_8, KC_9, KC_0, TG(PUBG),
    KC_RBRC, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH,
    KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS,
    KC_EQL, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_RSFT,
    KC_RGUI, MO(SYMBOL), KC_RALT, KC_NO, KC_NO,
    KC_NO, KC_NO,
    KC_NO,
    MO(MOVE), KC_ESC, KC_ENT
),

// Cursor Moving
[MOVE] = KEYMAP(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,

    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
),

// Number and Fuction keys
[NUM_HOME] = KEYMAP(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS,
    KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,

    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11, KC_F12,
    KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,
    KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
),

// Number and Fuction keys
[SYMBOL] = KEYMAP(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, S(KC_QUOT), S(KC_COMM), S(KC_DOT), KC_LBRC, S(KC_LBRC), KC_TRNS,
    KC_TRNS, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),
    KC_TRNS, S(KC_SCLN), KC_TRNS, KC_TRNS, KC_BSLS, S(KC_BSLS), KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,

    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, S(KC_RBRC), KC_RBRC, KC_GRV, S(KC_GRV), KC_TRNS, KC_TRNS,
    S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_TRNS,
    KC_TRNS, S(KC_EQL), KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
),

[PUBG] = KEYMAP(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO,
    KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_PGUP,
    KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_PGDN,
    KC_V, KC_NO, KC_LALT, MO(PUBG2), KC_M,
    KC_NO, PUBG_MED_KIT,
    PUBG_FIRST_AID_KIT,
    KC_SPC, KC_BSPC, PUBG_BANDAGE,

    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TG(PUBG),
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO,
    KC_NO,
    KC_NO, KC_NO, KC_NO
),

[PUBG2] = KEYMAP(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, LCTL(KC_1), LCTL(KC_2), KC_NO, PUBG_AUTO_RUN, KC_NO, KC_NO,
    KC_NO, LCTL(KC_3), LCTL(KC_4), KC_NO, KC_V, KC_NO,
    KC_NO, LCTL(KC_5), LCTL(KC_6), KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO,
    KC_NO,
    KC_NO, KC_NO, KC_NO,

    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO,
    KC_NO,
    KC_NO, KC_NO, KC_NO
),
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
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_led_all_set(3);
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case DVORAK:
            ergodox_right_led_1_on();
            break;
        case MOVE:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case NUM_HOME:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case PUBG:
        case PUBG2:
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

};
