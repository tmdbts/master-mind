//
// Created by James Whitever on 16/12/2021.
//

#include "Statistics.h"
#include <stdio.h>
#include "Settings.h"
#include "helpers.h"

int totalPoints[2] = {0, 0};

static float averagePoints[2] = {0, 0};

int totalPlayedGames = 0;

int playedGames[2] = {0, 0};

int wonGames[2] = {0, 0};

int bestResult[2][2] = {{0, 0},
                        {0, 0}};

int worseResult[2][2] = {{0, 0},
                         {0, 0}};

int totalTries[2] = {0, 0};

static float averageTries[2] = {0, 0};

void setTotalPoints(int player, int value) {
    totalPoints[player] = value;
}

void setAveragePoints(int player, float value) {
    averagePoints[player] = value;
}

int getTotalPlayedGames() {
    return totalPlayedGames;
}

void setTotalPlayedGames(int value) {
    totalPlayedGames = value;
}

void setPlayedGames(int player, int value) {
    playedGames[player] = value;
}

void setWonGames(int player, int value) {
    wonGames[player] = value;
}

void setBestResult(int player, int target, int value) {
    bestResult[player][target] = value;
}

void setWorseResult(int player, int target, int value) {
    worseResult[player][target] = value;
}

static void printStaticsMenu() {
    printf("\n\n");
    printf("+---+----------------------------+ \n");
    printf("|           Statistics           | \n");
    printf("+---+----------------------------+ \n");
    printf("| 1 |             Player one (%c) | \n", playerName[0]);
    printf("+---+----------------------------+ \n");
    printf("| 2 |             Player two (%c) | \n", playerName[1]);
    printf("+---+----------------------------+ \n");
    printf("| 0 |            Exit statistics | \n");
    printf("+---+----------------------------+ \n");
    printf("\n\n");
}

static void showStats(int player) {
    printf("\n\n");
    printf("+--------------------------------------------+ \n");

    if (player == 0)
        printf("|            Statistics player one           | \n");

    if (player == 1)
        printf("|            Statistics player two           | \n");

    printf("+--------------------------------------------+ \n");;
    printf("| Total played games %i                       | \n", totalPlayedGames);
    printf("| Played games %i                             | \n", playedGames[player]);
    printf("| Won Games %i                                | \n", wonGames[player]);
    printf("| Points %3.0f                                 | \n", (float) totalPoints[player]);
    printf("| Average Points %3.2f                       | \n", averagePoints[player]);
    printf("| Best result                                | \n");
    printf("|   Right colors in the right place %i        | \n", bestResult[player][0]);
    printf("|   Right colors in the wrong place %i        | \n", bestResult[player][1]);
    printf("| Worse result                               | \n");
    printf("|   Right colors in the right place %i        | \n", worseResult[player][0]);
    printf("|   Right colors in the wrong place %i        | \n", worseResult[player][1]);
    printf("| Average percentage of tries per game %3.0f %% |\n", averageTries[player]);
    printf("+--------------------------------------------+ \n");
}

static int pickFromStatisticsMenu() {
    int input;

    printf("Select an option from the menu: \n");
    scanf("%d", &input);

    if (input < 0 || input > 2) {
        printf("\nInvalid option. \n");

        input = pickFromStatisticsMenu();
    }

    return input;
}

static void evaluateScoreForBest(int player, int fullyRightColors, int rightColors) {
    if (fullyRightColors > bestResult[player][0]) {
        setBestResult(player, 0, fullyRightColors);
        setBestResult(player, 1, rightColors);

        return;
    }

    if (rightColors > bestResult[player][1] && fullyRightColors >= bestResult[player][0]) {
        setBestResult(player, 0, fullyRightColors);
        setBestResult(player, 1, rightColors);

        return;
    }
}

static void evaluateScoreForWorse(int player, int fullyRightColors, int rightColors) {
    if (totalPlayedGames == 0) {
        setWorseResult(player, 0, fullyRightColors);
        setWorseResult(player, 1, rightColors);

        return;
    }

    if (fullyRightColors < worseResult[player][0]) {
        setWorseResult(player, 0, fullyRightColors);
        setWorseResult(player, 1, rightColors);

        return;
    }

    if (rightColors < bestResult[player][1] && fullyRightColors <= bestResult[player][0]) {
        setWorseResult(player, 0, fullyRightColors);
        setWorseResult(player, 1, rightColors);

        return;
    }
}

void evaluateScore(int player, int fullyRightColors, int rightColors) {
    evaluateScoreForBest(player, fullyRightColors, rightColors);
    evaluateScoreForWorse(player, fullyRightColors, rightColors);
}

void setTotalTries(int player, int value) {
    totalTries[player] = value;
}

void updateStatistics() {
    totalPlayedGames = playedGames[0] + playedGames[1];

    averagePoints[0] = (float) totalPoints[0] / playedGames[0];
    averagePoints[1] = (float) totalPoints[1] / playedGames[1];

    averageTries[0] = (float) (totalTries[0] * 100) / maxTries;
    averageTries[1] = (float) (totalTries[1] * 100) / maxTries;
}

void Statistics() {
    int menuChoice;
    int player;

    updateStatistics();
    clear();

    do {
        printStaticsMenu();
        menuChoice = pickFromStatisticsMenu();
        
        player = menuChoice - 1;

        clear();

        if (player == 0 || player == 1) showStats(player);
    } while (menuChoice != 0);
}