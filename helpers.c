//
// Created by James Whitever on 13/12/2021.
//

#include "helpers.h"
#include <stdlib.h>
#include <time.h>

void clear() {
    system("clear");
}

int randomizerMax(int max) {
    srand(time(NULL));

    return rand() % max;
}

int randomizer(int min, int max) {
    srand(time(NULL));

    return rand() % max + min;

}