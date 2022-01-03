//
// Created by James Whitever on 11/12/2021.
//

#ifndef PROJECT_SETTINGS_H
#define PROJECT_SETTINGS_H

/**
 * Stores the names for the two players
 */
extern char playerName[2];

/**
 * Stores the max number of tries
 */
extern unsigned int maxTries;

/**
 * Stores the max number of games in a single session
 */
extern unsigned int maxSessionGames;

/**
 * Prints the settings menu
 */
void printSettingsMenu();

/**
 * Reads the menu choice given by the user
 *
 * @return user's choice
 */
int pickFromSettingsMenu();

/**
 * Checks if the name inserted by the user is a valid name
 *
 * @param inputName name inserted by the user
 * @return 1 for true and 0 for false
 */
int isPlayerNameValid(char inputName);

/**
 * Reads the name from the user
 *
 * @param playerNumber player number
 * @return the player's name
 */
char readPlayerName(int playerNumber);

/**
 * Sets the max tries
 */
void setMaxTries();

/**
 * Sets the max number of games per session
 */
void setMaxSessionGames();

/**
 * Main function for Settings
 */
void Settings();

#endif //PROJECT_SETTINGS_H
