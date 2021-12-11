//
// Created by James Whitever on 11/12/2021.
//

#include "Settings.h"
#include <stdio.h>

void printSettingsMenu() {
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

    printf("Select an option from the menu: ");
    scanf("%i", &settingsMenuPick);

    if (settingsMenuPick < 0 || settingsMenuPick > 4) {
        printf("\nInvalid option. \n");

        settingsMenuPick = pickFromSettingsMenu();
    }

    return settingsMenuPick;
}

void Settings();

int isPlayerNameValid(char inputName) {
    if (inputName <= 65 || inputName >= 90 && inputName <= 97 || inputName >= 122) {
        return 0;
    }

    return 1;
}

int toUppercase(char value) {
    if (value <= 65 || value >= 90) {
        return value - 32;
    }
    
    return 0;
}

void setPlayerOneName();

void setPlayerTwoName();

void setMaxTries();