//
// Created by James Whitever on 13/12/2021.
//

#include "helpers.h"
#include <stdlib.h>

void clear() {
#ifdef _WIN32
    system("cls");

    return;
#endif

    system("clear");
}

int randomizerMax(int max) {
    return rand() % max;
}

char toUppercase(char value) {
    return value <= 65 || value >= 90 ? value - 32 : value;
}