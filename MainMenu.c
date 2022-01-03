//
// Created by James Whitever on 11/12/2021.
//

#include <stdio.h>
#include "MainMenu.h"
#include "Settings.h"
#include "SinglePlayer.h"
#include "Multiplayer.h"
#include "Statistics.h"
#include "constants.h"

void printMainMenu() {
    printf("%s\n", TERMINAL_COLOR_DEFAULT);
    printf("+---+---------------+ \n");
    printf("|     Main Menu     | \n");
    printf("+---+---------------+ \n");
    printf("| 1 |️ Single player | \n");
    printf("+---+---------------+ \n");
    printf("| 2 |   Multiplayer | \n");
    printf("+---+---------------+ \n");
    printf("| 3 |    Statistics | \n");
    printf("+---+---------------+ \n");
    printf("| 4 |      Settings | \n");
    printf("+---+---------------+ \n");
    printf("| 0 |          Exit | \n");
    printf("+---+---------------+ \n");
    printf("\n");
}

int pickFromMainMenu() {
    int mainMenuInput;

    printf("Select an option from the menu: \n");
    scanf("%d", &mainMenuInput);

    if (mainMenuInput < 0 || mainMenuInput > 4) {
        printf("\nInvalid option. \n");

        mainMenuInput = pickFromMainMenu();
    }

    return mainMenuInput;
}

void MainMenu() {
    int menuChoice;

    do {
        printMainMenu();

        menuChoice = pickFromMainMenu();

        switch (menuChoice) {
            case 1:
                if (getTotalPlayedGames() >= maxSessionGames) {
                    printf("You can't play more games. You reached your limit");

                    break;
                }

                PlaySinglePlayer();

                break;

            case 2:
                if (getTotalPlayedGames() >= maxSessionGames) {
                    printf("You can't play more games. You reached your limit. \n\n");

                    break;
                }

                PlayMultiplayer();

                break;

            case 3:
                Statistics();

                break;

            case 4:
                Settings();

                break;

            default:
                break;
        }
    } while (menuChoice != 0);
}