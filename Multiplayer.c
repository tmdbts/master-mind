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

    printf("%sPlayer %c it is your time to create a keycode.\n\n", TERMINAL_COLOR_GREEN, playerName[player]);

    for (int i = 0; i < keycodeLen; ++i) {
        printf("%sInsert the position %i of the keycode:\n", TERMINAL_COLOR_DEFAULT, i);
        scanf(" %c", &input);

        input = toUppercase(input);

        if (colorValidator(input) == 0) {
            printf("\n%sInvalid color. Insert a valid color. \n", TERMINAL_COLOR_GREEN);
            printf("%sList of valid colors: [R, G, B, W, Y, O]. \n\n", TERMINAL_COLOR_RED);

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

static void readUserInput(int player) {
    printf("%sPlayer %c it is your time to guess.\n\n", TERMINAL_COLOR_GREEN, playerName[player]);

    for (int i = 0; i < keycodeLen; ++i) {
        printf("%sInsert your guess for the position %i: \n", TERMINAL_COLOR_DEFAULT, i);
        scanf(" %c", &guess[i]);

        guess[i] = toUppercase(guess[i]);

        if (colorValidator(guess[i]) == 0) {
            printf("\n%sInvalid color. Insert a valid color. \n", TERMINAL_COLOR_RED);
            printf("%sList of valid colors: [R, G, B, W, Y, O]. \n\n", TERMINAL_COLOR_RED);

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

    if (correctGuessColors >= keycodeLen / 2)
        setTotalPoints(player, totalPoints[player] += 2);

    return 0;
}

void PlayMultiplayer() {
    keycodeLen = sizeof keycode / sizeof(char);
    int hasWon = 0;
    tries = 0;

    clear();


    int decoderPlayer = selectPlayer() - 1;
    int encoderPlayer;

    if (decoderPlayer == 0) {
        encoderPlayer = decoderPlayer + 1;
    } else {
        encoderPlayer = decoderPlayer - 1;
    }

    setPlayedGames(decoderPlayer, ++playedGames[decoderPlayer]);
    updateStatistics();
    clear();

    createKeycode(encoderPlayer);
    clear();
//    printKeycode();

    while (tries < maxTries && hasWon == 0) {
        tries++;

        readUserInput(decoderPlayer);
        clear();
        hasWon = evaluateGuess(decoderPlayer);

        if (tries < maxTries && hasWon == 0) {
            int triesLeft = maxTries - tries;

            printf("%sThe combination is incorrect. Try again. \n", TERMINAL_COLOR_YELLOW);
            printf("%sYou have %i tries left. \n\n", TERMINAL_COLOR_YELLOW, triesLeft);
        }
    }

    if (tries == maxTries && hasWon == 0) {
        printf("%sYou have run out of tries. \n", TERMINAL_COLOR_YELLOW);
    }

    setTotalTries(decoderPlayer, totalTries[decoderPlayer] + tries);
}