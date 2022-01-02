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
#include "Settings.h"

static int selectPlayer() {
    int input;

    printf("Which player is playing? (1 or 2)\n");
    scanf("%i", &input);

    if (input != 1 && input != 2) {
        printf("Invalid player. Select player 1 or 2.\n\n");

        input = selectPlayer();
    }

    return input;
}

static void generateKeycode() {
    int intKeyCode[keycodeLen];

    srand(time(NULL));

    for (int i = 0; i < keycodeLen; ++i) {
        intKeyCode[i] = randomizerMax(6);
        keycode[i] = COLORS[intKeyCode[i]];
    }
}

static void printKeycode() {
    printf("keycode: ");

    for (int i = 0; i < keycodeLen; ++i) {
        printf("%c ", keycode[i]);
    }

    printf("\n\n");
}

static int guessValidator(int toValidateGuess) {
    for (int i = 0; i < COLORS_LENGTH; ++i) {
        if (toValidateGuess == COLORS[i]) return 1;
    }

    return 0;
}

static void readUserInput() {
    for (int i = 0; i < keycodeLen; ++i) {
        printf("%sInsert your guess for the position %i: \n", TERMINAL_COLOR_DEFAULT, i);
        scanf(" %c", &guess[i]);

        guess[i] = toUppercase(guess[i]);

        if (guessValidator(guess[i]) == 0) {
            printf("%sInvalid color. Insert a new color. \n\n", TERMINAL_COLOR_RED);

            i--;
        }
    }
}

static int isGuessCorrect(int i) {
    if (guess[i] == keycode[i]) return 1;

    return 0;
}

static int areGuessColorsCorrect(int i) {
    for (int j = 0; j < keycodeLen; ++j) {
        if (guess[i] == keycode[j]) return 1;
    }

    return 0;
}

static int evaluateGuess(int player) {
    int correctGuesses = 0;
    int correctGuessColors = 0;

    for (int i = 0; i < keycodeLen; ++i) {
        if (isGuessCorrect(i) == 1) {
            correctGuesses++;

            continue;
        }

        if (areGuessColorsCorrect(i) == 1) {
            correctGuessColors++;
        }
    }

    evaluateScore(player, correctGuesses, correctGuessColors);

    if (correctGuesses == keycodeLen) {
        setTotalPoints(player, totalPoints[player] += 10);
        setWonGames(player, ++wonGames[player]);

        return 1;
    }

    if (correctGuesses >= keycodeLen / 2) {
        setTotalPoints(player, totalPoints[player] += 5);

        return 0;
    }

    if (correctGuessColors >= keycodeLen / 2) {
        setTotalPoints(player, totalPoints[player] += 2);
    }

    return 0;
}

void PlaySinglePlayer() {
    keycodeLen = sizeof keycode / sizeof(char);
    int hasWon = 0;
    tries = 0;

    clear();

    int player = selectPlayer() - 1;


    setPlayedGames(player, ++playedGames[player]);
    updateStatistics();
    clear();

    printf("Playing as %c \n\n", playerName[player]);

    generateKeycode();
//    printKeycode();

    while (tries < maxTries && hasWon == 0) {
        tries++;

        readUserInput();
        hasWon = evaluateGuess(player);

        clear();

        if (tries < maxTries && hasWon == 0) {
            int triesLeft = maxTries - tries;

            printf("%sThe combination is incorrect. Try again. \n", TERMINAL_COLOR_YELLOW);
            printf("%sYou have %i tries left. \n\n", TERMINAL_COLOR_YELLOW, triesLeft);
        }
    }

    if (tries == 5 && hasWon == 0) {
        printf("You have run out of tries. \n");
    }

    setTotalTries(player, totalTries[player] + tries);
}