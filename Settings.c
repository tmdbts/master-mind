//
// Created by James Whitever on 11/12/2021.
//

#include "Settings.h"
#include <stdio.h>
#include "helpers.h"

void printSettingsMenu() {
    clear();
    printf("\n");
    printf("+---+--------------------------+ \n");
    printf("|           Settings           | \n");
    printf("+---+--------------------------+ \n");
    printf("| 1 | Change player one's name | \n");
    printf("+---+--------------------------+ \n");
    printf("| 2 | Change player one's name | \n");
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
        printf("\nInvalid option. \n");

        settingsMenuPick = pickFromSettingsMenu();
    }

    return settingsMenuPick;
}

int isPlayerNameValid(char inputName) {
    if (inputName <= 65 || inputName >= 90 && inputName <= 97 || inputName >= 122) {
        return 0;
    }

    return 1;
}

char toUppercase(char value) {
    return value <= 65 || value >= 90 ? value - 32 : value;
}

char readPlayerName(int playerNumber) {
    char nameInput;

    if (playerNumber == 1) printf("Insert a name for the player one. \n");

    if (playerNumber == 2) printf("Insert a name for the player one. \n");

    scanf(" %c", &nameInput);

    if (isPlayerNameValid(nameInput) == 0) {
        printf("Invalid Name. \n");

        nameInput = readPlayerName(playerNumber);
    }

    nameInput = toUppercase(nameInput);

    return nameInput;
}

void setMaxTries() {
    printf("Insert the number of max tries per game. \n");

    scanf("%i", &maxTries);

    printf("You now have %i tries per game.", maxTries);
}

void setMaxSessionGames() {
    printf("Insert the number of max tries per game. \n");

    scanf("%i", &maxSessionGames);

    printf("You now have %i games per session.", maxSessionGames);
}

void Settings() {
    int settingMenuInput;

    do {
        printSettingsMenu();

        settingMenuInput = pickFromSettingsMenu();

        switch (settingMenuInput) {
            case 1:
                playerName1 = readPlayerName(1);
                printf("The name of the player one is now %c.", playerName1);

                break;

            case 2:
                playerName2 = readPlayerName(2);
                printf("The name of the player two is now %c.", playerName2);

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