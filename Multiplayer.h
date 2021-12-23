//
// Created by James Whitever on 21/12/2021.
//

#ifndef MASTER_MIND_MULTIPLAYER_H
#define MASTER_MIND_MULTIPLAYER_H

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
 * Selects the player that begins guessing
 *
 * @return The player that begins guessing
 */
static int selectStartingPlayer();

/**
 * Creates the keycode from user input
 */
static void createKeycode(int player);

/**
 * Prints the key code (for debugging purposes)
 */
static void printKeycode();

/**
 * Checks if the input given by the user is a valid color
 *
 * @param toValidateGuess
 * @return 0 for a not valid color and 1 for a valid color
 */
static int colorValidator(int toValidateGuess);

/**
 * Reads the guess from user input
 */
static void readUserInput();

/**
 * Checks if the colors are correct in the right place
 *
 * @param i loop iteration
 * @return 0 for a incorrect guess and 1 for a correct guess
 */
static int isGuessCorrect(int i);

/**
 * Checks if the colors are correct
 *
 * @param i loop iteration
 * @return 0 for a partial incorrect guess and 1 for a partial correct guess
 */
static int areGuessColorsCorrect(int i);

/**
 * Entry point for the multiplayer
 */
void PlayMultiplayer();

#endif //MASTER_MIND_MULTIPLAYER_H
