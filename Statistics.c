//
// Created by James Whitever on 16/12/2021.
//

#include "Statistics.h"
#include <stdio.h>

void setTotalPoints(int player, int value) {
    totalPoints[player] = value;
}

void printStatistics() {
    printf("\n\n");
//    printf("+---+----------------------------+ \n");
//    printf("|           Statistics           | \n");
//    printf("+---+----------------------------+ \n");
//    printf("| 1 | %i | \n");
//    printf("+---+----------------------------+ \n");
//    printf("| 2 | Change player one's name | \n");
//    printf("+---+----------------------------+ \n");
//    printf("| 3 |                Max tries | \n");
//    printf("+---+----------------------------+ \n");
//    printf("| 4 |    Max games per session | \n");
//    printf("+---+----------------------------+ \n");
//    printf("| 0 |            Exit settings | \n");
//    printf("+---+----------------------------+ \n");
//    printf("\n");
    printf("Player 1:\n");
    printf("Points: %i\n", totalPoints[0]);
    printf("Player 2:\n");
    printf("Points: %i \n", totalPoints[1]);
}