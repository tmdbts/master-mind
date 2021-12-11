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
    int input;

    printf("Select an option from the menu: ");
    scanf("%d", &input);

    if (input < 0 || input > 3) {
        printf("\nInvalid option. \n");

        input = pickFromMainMenu();
    }

    return input;
}