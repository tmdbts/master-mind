#include <stdio.h>
#include "MainMenu.h"

int main() {
    int menuChoice;
    printf("*** WELCOME TO THE MASTER MIND *** \n");


    do {
        printMainMenu();
        
        menuChoice = pickFromMainMenu();

        switch (menuChoice) {
            case 1:
//            PlaySinglePlayer();
                printf("1");

                break;

            case 2:
//            PlayMultiPlayer();
                printf("2");

                break;

            case 3:
//            Settings();
                printf("3");

                break;

            default:
                break;
        }
    } while (menuChoice != 0);


    return 0;
}
