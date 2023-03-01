#include "lcvt4.h"
enum custom_keycodes {
    FAV = SAFE_RANGE,
    LEFT_KNOB_CLW,
    LEFT_KNOB_ANTICLW,
    RIGHT_KNOB_CLW,
    RIGHT_KNOB_ANTICLW,

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /*FOR ADDING TO FAVOURITES*/
        case FAV:
            if (record->event.pressed) {
                register_code(KC_A);
                register_code(KC_J);
            } else {
                unregister_code(KC_A);
                unregister_code(KC_J);
            }
            break;
        case LEFT_KNOB_CLW:
            tap_code(KC_MS_U);
            break;

        case LEFT_KNOB_ANTICLW:
            tap_code(KC_MS_D);

            break;

            /*FOR RIGHT ENCODERS */
        case RIGHT_KNOB_CLW:
            tap_code(KC_MS_R);
            break;
        case RIGHT_KNOB_ANTICLW:
            tap_code(KC_MS_L);
            break;
    }

    return true;
};

void matrix_scan_user(void) {}

/*THE ENCODERS OUTPUT WILL ALWAYS COUNT AS A HOLD
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_Q:
            return 0;
        case KC_W:
            return 0;
        case KC_O:
            return 0;
        case KC_P:
            return 0;
        default:
            return TAPPING_TERM;
    }
}*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    KEYMAP(LT(2, KC_V), KC_1, KC_S, KC_A, KC_D, KC_F, KC_Z, KC_X),
    KEYMAP(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    KEYMAP(KC_V, KC_1, KC_A, KC_F5, KC_F2, KC_Z, KC_V, KC_ESC),

};

/*CHANGE BETWEEN PLAYING MODES*/
const uint16_t PROGMEM test_combo1[] = {KC_C, KC_2, KC_M, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(test_combo1, TG(1)),

};

/*CLEAR INPUT EVERYTIME THE LAYER CHANGES*/
layer_state_t layer_state_set_user(layer_state_t state) {
    clear_keyboard();
    return state;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {ENCODER_CCW_CW(RIGHT_KNOB_CLW, RIGHT_KNOB_ANTICLW), ENCODER_CCW_CW(LEFT_KNOB_CLW, LEFT_KNOB_ANTICLW)},
    [1] = {ENCODER_CCW_CW(RIGHT_KNOB_CLW, RIGHT_KNOB_ANTICLW), ENCODER_CCW_CW(LEFT_KNOB_CLW, LEFT_KNOB_ANTICLW)},
    [2] = {ENCODER_CCW_CW(RIGHT_KNOB_CLW, RIGHT_KNOB_ANTICLW), ENCODER_CCW_CW(LEFT_KNOB_CLW, LEFT_KNOB_ANTICLW)},

};
#endif
