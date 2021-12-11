//
// Created by James Whitever on 11/12/2021.
//

#include <stdio.h>
#include "MainMenu.h"

void printMainMenu() {
    printf("\n");
    printf("+---+---------------+ \n");
    printf("|     Main Menu     | \n");
    printf("+---+---------------+ \n");
    printf("| 1 | Single player | \n");
    printf("+---+---------------+ \n");
    printf("| 2 |   Multiplayer | \n");
    printf("+---+---------------+ \n");
    printf("| 3 |      Settings | \n");
    printf("+---+---------------+ \n");
    printf("| 0 |          Exit | \n");
    printf("+---+---------------+ \n");
    printf("\n");
}

int pickFromMainMenu() {
    int mainMenuInput;

    printf("Select an option from the menu: \n");
    scanf("%d", &mainMenuInput);

    if (mainMenuInput < 0 || mainMenuInput > 3) {
        printf("\nInvalid option. \n");

        mainMenuInput = pickFromMainMenu();
    }

    return mainMenuInput;
}