//
// Created by James Whitever on 11/12/2021.
//

#include "Settings.h"
#include <stdio.h>
#include "helpers.h"
#include "constants.h"

/**
 * Stores the names for the two players
 */
char playerName[2] = {'O', 'T'};

/**
 * Stores the max number of tries
 */
unsigned int maxTries = 5;

/**
 * Stores the max number of games in a single session
 */
unsigned int maxSessionGames = 5;

void printSettingsMenu() {
    printf("%s\n", TERMINAL_COLOR_DEFAULT);
    printf("+---+--------------------------+ \n");
    printf("|           Settings           | \n");
    printf("+---+--------------------------+ \n");
    printf("| 1 | Change player one's name | \n");
    printf("+---+--------------------------+ \n");
    printf("| 2 | Change player two's name | \n");
    printf("+---+--------------------------+ \n");
    printf("| 3 |                Max tries | \n");
    printf("+---+--------------------------+ \n");
    printf("| 4 |    Max games per session | \n");
    printf("+---+--------------------------+ \n");
    printf("| 0 |            Exit settings | \n");
    printf("+---+--------------------------+ \n");
    printf("\n");
}

int pickFromSettingsMenu() {
    int settingsMenuPick;

    printf("Select an option from the menu: \n");
    scanf("%i", &settingsMenuPick);

    if (settingsMenuPick < 0 || settingsMenuPick > 4) {
        printf("%s\nInvalid option. \n", TERMINAL_COLOR_RED);

        settingsMenuPick = pickFromSettingsMenu();
    }

    clear();

    return settingsMenuPick;
}

int isPlayerNameValid(char inputName) {
    if (inputName <= 65 || inputName >= 90 && inputName <= 97 || inputName >= 122) {
        return 0;
    }

    return 1;
}

char readPlayerName(int playerNumber) {
    char nameInput;

    if (playerNumber == 1) printf("%sInsert a name for the player one. \n", TERMINAL_COLOR_DEFAULT);

    if (playerNumber == 2) printf("%sInsert a name for the player two. \n", TERMINAL_COLOR_DEFAULT);

    scanf(" %c", &nameInput);

    if (isPlayerNameValid(nameInput) == 0) {
        printf("%sInvalid Name. \n\n", TERMINAL_COLOR_RED);

        nameInput = readPlayerName(playerNumber);
    }

    nameInput = toUppercase(nameInput);

    return nameInput;
}

void setMaxTries() {
    printf("Insert the number of max tries per game. \n");

    scanf("%i", &maxTries);

    clear();

    printf("%sYou now have %i tries per game. \n", TERMINAL_COLOR_YELLOW, maxTries);
}

void setMaxSessionGames() {
    printf("Insert the number of max tries per game. \n");

    scanf("%i", &maxSessionGames);

    clear();

    printf("%sYou now have %i games per session.\n", TERMINAL_COLOR_YELLOW, maxSessionGames);
}

void Settings() {
    int settingMenuInput;

    clear();

    do {
        printSettingsMenu();

        settingMenuInput = pickFromSettingsMenu();

        switch (settingMenuInput) {
            case 1:
                clear();

                playerName[0] = readPlayerName(1);

                clear();

                printf("%sThe name of the player one is now %c.\n", TERMINAL_COLOR_YELLOW, playerName[0]);

                break;

            case 2:
                clear();

                playerName[1] = readPlayerName(2);

                clear();

                printf("%sThe name of the player two is now %c. \n", TERMINAL_COLOR_YELLOW, playerName[1]);

                break;

            case 3:
                setMaxTries();

                break;

            case 4:
                setMaxSessionGames();

                break;

            default:
                break;
        }
    } while (settingMenuInput != 0);
}