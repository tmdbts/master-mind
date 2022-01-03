//
// Created by James Whitever on 13/12/2021.
//

#ifndef PROJECT_SINGLE_PLAYER_H
#define PROJECT_SINGLE_PLAYER_H

/**
 * Stores de value for the keycode
 */
static char keycode[4];

/**
 * Stores the value for the guss
 */
static char guess[4];

/**
 * Stores the value for the length of the keycode
 */
static int keycodeLen;

/**
 * Stores the value for the number of tries.
 */
static int tries;

/**
 * Selects the player to play the game
 *
 * @return The player to play the game
 */
static int selectPlayer();

/**
 * Generates the code randomly
 */
static void generateKeycode();

/**
 * Prints the code for debug purposes
 */
static void printKeycode();

/**
 * Validates the guess comparing it to the COLORS array
 *
 * @param toValidateGuess the guess to be validated
 * @return 0 for false and 1 for true
 */
static int guessValidator(int toValidateGuess);

/**
 * Reads the user input from the terminal
 */
static void readUserInput();

/**
 * Checks if the guess is correct comparing it to the keycode array
 *
 * @param i position on the array
 * @return 0 for false and 1 for true
 */
static int isGuessCorrect(int i);

/**
 * Checks if the color in the guess is correct comparing it to the keycode array
 *
 * @param i position on the array
 * @return 0 for false and 1 for true
 */
static int areGuessColorsCorrect(int i);

/**
 * Counts the right colors in the right place and the right colors and sends the data to the statistics
 *
 * @param player the player
 * @return 0 if the guess is not fully correct and 1 if the guess is fully correct
 */
static int evaluateGuess(int player);

/**
 * Main entry for the PlaySinglePlayer
 */
void PlaySinglePlayer();

#endif //PROJECT_SINGLE_PLAYER_H
