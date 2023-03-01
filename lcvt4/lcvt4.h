#ifndef KB_H
#define KB_H

#include "quantum.h"

#define KEYMAP(K03, K04, K10, K11, K12, K13, K21, K23)                             \
    {                                                                              \
        {KC_NO, K03, K04, KC_NO}, {K10, K11, K12, K13}, { KC_NO, K21, K23, KC_NO } \
    }

#endif