//
// Created by James Whitever on 13/12/2021.
//

#include "helpers.h"
#include <stdlib.h>
#include <time.h>

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

int randomizer(int min, int max) {
    return rand() % max + min;
}

int getIntArrayLength(int array) {
    return sizeof array / sizeof(int);
}

int getCharArrayLength(char array) {
    return sizeof array / sizeof(char);
}

char toUppercase(char value) {
    return value <= 65 || value >= 90 ? value - 32 : value;
}