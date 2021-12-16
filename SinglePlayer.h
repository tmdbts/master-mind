//
// Created by James Whitever on 13/12/2021.
//

#ifndef PROJECT_SINGLE_PLAYER_H
#define PROJECT_SINGLE_PLAYER_H

char keycode[4];

char guess[4];

int keycodeLen;

int selectPlayer();

void generateKeycode();

void printKeycode();

int guessValidator(int toValidateGuess);

void readUserInput();

void PlaySinglePlayer();

int isGuessCorrect(int i);

int isGuessPartiallyCorrect(int i);

#endif //PROJECT_SINGLE_PLAYER_H
