//
// Created by James Whitever on 21/12/2021.
//

#include "Multiplayer.h"
#include "stdio.h"
#include "helpers.h"
#include "constants.h"
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

static int colorValidator(int toValidateGuess) {
    for (int i = 0; i < COLORS_LENGTH; ++i) {
        if (toValidateGuess == COLORS[i]) return 1;
    }

    return 0;
}

static void createKeycode(int player) {
    char input;

    printf("Player %c it is your time to create a keycode.\n\n", playerName[player]);

    for (int i = 0; i < keycodeLen; ++i) {
        printf("Insert the position %i of the keycode:\n", i);
        scanf(" %c", &input);

        input = toUppercase(input);

        if (colorValidator(input) == 0) {
            printf("Invalid color. Please insert a valid color.\n\n");

            i--;

            continue;
        }

        keycode[i] = input;
    }
}

static void printKeycode() {
    printf("keycode: ");

    for (int i = 0; i < keycodeLen; ++i) {
        printf("%c ", keycode[i]);
    }

    printf("\n\n");
}

static void readUserInput() {
    for (int i = 0; i < keycodeLen; ++i) {
        printf("Insert your guess for the position %i: \n", i);
        scanf(" %c", &guess[i]);

        guess[i] = toUppercase(guess[i]);

        if (colorValidator(guess[i]) == 0) {
            printf("Invalid color. Insert a new color. \n\n");

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

static void evaluateGuess(int player) {
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

    if (correctGuesses == keycodeLen) {
        setTotalPoints(player, totalPoints[player] += 10);

        return;
    }

    if (correctGuesses >= keycodeLen / 2) {
        setTotalPoints(player, totalPoints[player] += 5);

        return;
    }

    if (correctGuessColors >= keycodeLen / 2)
        setTotalPoints(player, totalPoints[player] += 2);
}

void PlayMultiplayer() {
    keycodeLen = sizeof keycode / sizeof(char);

    int decoderPlayer = selectPlayer() - 1;
    int encoderPlayer;

    if (decoderPlayer == 0) {
        encoderPlayer = decoderPlayer + 1;
    } else {
        encoderPlayer = decoderPlayer - 1;
    }

    createKeycode(encoderPlayer);
    clear();
    printKeycode();
    readUserInput();
    clear();
    evaluateGuess(decoderPlayer);
    printStatistics();
}