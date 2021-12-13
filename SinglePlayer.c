//
// Created by James Whitever on 13/12/2021.
//

#include "SinglePlayer.h"
#include "helpers.h"
#include "constants.h"
#include <stdio.h>

int generateKeycode() {
    for (int i = 0; i < sizeof keycode; ++i) {
        keycode[i] = randomizerMax(sizeof COLORS);
    }
}

void PlaySinglePlayer() {
    generateKeycode();

    for (int i = 0; i < sizeof keycode; ++i) {
        printf("%i", keycode[i]);
    }
}