//
// Created by James Whitever on 13/12/2021.
//

#ifndef PROJECT_SINGLE_PLAYER_H
#define PROJECT_SINGLE_PLAYER_H

static char keycode[4];

static char guess[4];

static int keycodeLen;

static int selectPlayer();

static void generateKeycode();

static void printKeycode();

static int guessValidator(int toValidateGuess);

static void readUserInput();

static int isGuessCorrect(int i);

static int areGuessColorsCorrect(int i);

static void evaluateGuess(int player);

void PlaySinglePlayer();

#endif //PROJECT_SINGLE_PLAYER_H
