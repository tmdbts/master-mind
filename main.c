#include <stdio.h>
#include "MainMenu.h"
#include "Settings.h"
#include "SinglePlayer.h"
#include "helpers.h"
#include "Multiplayer.h"
#include "Statistics.h"

int main() {
    int menuChoice;

    clear();

    printf("*** WELCOME TO THE MASTER MIND *** \n");

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

    return 0;
}
