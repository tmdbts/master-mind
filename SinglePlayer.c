//
// Created by James Whitever on 13/12/2021.
//

#include "SinglePlayer.h"
#include "helpers.h"
#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Statistics.h"

int selectPlayer() {
    int input;

    printf("Which player is playing? (1 or 2)\n");
    scanf("%i", &input);

    if (input != 1 && input != 2) {
        printf("Invalid player. Select player 1 or 2.\n\n");

        input = selectPlayer();
    }

    return input;
}

void generateKeycode() {
    int intKeyCode[keycodeLen];

    srand(time(NULL));

    for (int i = 0; i < keycodeLen; ++i) {
        intKeyCode[i] = randomizerMax(6);
        keycode[i] = COLORS[intKeyCode[i]];
    }
}

void printKeycode() {
    printf("keycode: ");

    for (int i = 0; i < keycodeLen; ++i) {
        printf("%c ", keycode[i]);
    }

    printf("\n\n");
}

int guessValidator(int toValidateGuess) {
    for (int i = 0; i < COLORS_LENGTH; ++i) {
        if (toValidateGuess == COLORS[i]) return 1;
    }

    return 0;
}

void readUserInput() {
    for (int i = 0; i < keycodeLen; ++i) {
        printf("Insert your guess for the position %i: \n", i);
        scanf(" %c", &guess[i]);

        guess[i] = toUppercase(guess[i]);

        if (guessValidator(guess[i]) == 0) {
            printf("Invalid color. Insert a new color. \n\n");

            i--;
        }
    }
}

int isGuessCorrect(int i) {
    if (guess[i] == keycode[i]) return 1;

    return 0;
}

int isGuessPartiallyCorrect(int i) {
    for (int j = 0; j < keycodeLen; ++j) {
        if (guess[i] == keycode[j]) return 1;
    }

    return 0;
}

void PlaySinglePlayer() {
    keycodeLen = sizeof keycode / sizeof(char);

    int player = selectPlayer() - 1;

    generateKeycode();

    printKeycode();
    readUserInput();

    for (int i = 0; i < keycodeLen; ++i) {
        if (isGuessCorrect(i) == 1) {
            setTotalPoints(player, totalPoints[player] += 10);

            continue;
        }

        if (isGuessPartiallyCorrect(i) == 1) {
            setTotalPoints(player, totalPoints[player] += 5);
        }
    }
    
    printStatistics();
}