#include <stdio.h>
#include "MainMenu.h"
#include "Settings.h"
#include "SinglePlayer.h"
#include "helpers.h"

int main() {
    int menuChoice;

    printf("*** WELCOME TO THE MASTER MIND *** \n");

    do {
        printMainMenu();

        menuChoice = pickFromMainMenu();

        switch (menuChoice) {
            case 1:
                clear();
                PlaySinglePlayer();

                break;

            case 2:
//            PlayMultiPlayer();

                break;

            case 3:
//                Statistics();

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
