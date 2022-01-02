//
// Created by James Whitever on 16/12/2021.
//

#ifndef MASTER_MIND_STATISTICS_H
#define MASTER_MIND_STATISTICS_H

extern int totalPoints[2];

static float averagePoints[2];

extern int totalPlayedGames;

extern int playedGames[2];

extern int wonGames[2];

/**
 * Stores the best results of each player (lines).
 * It contains the right colors in the right places and only the right colors (columns respectively).
 */
extern int bestResult[2][2];

/**
 * Stores the worse results of each player (lines).
 * It contains the right colors in the right places and only the right colors (columns respectively).
 */
extern int worseResult[2][2];

extern int totalTries[2];

static float averageTries[2];

void setTotalPoints(int player, int value);

void setAveragePoints(int player, float value);

int getTotalPlayedGames();

void setTotalPlayedGames(int value);

void setPlayedGames(int player, int value);

void setWonGames(int player, int value);

void setBestResult(int player, int target, int value);

void setWorseResult(int player, int target, int value);

void setTotalTries(int player, int value);

void updateStatistics();

static void printStaticsMenu();

static void showStats(int player);

static int pickFromStatisticsMenu();

static void evaluateScoreForBest(int player, int fullyRightColors, int rightColors);

static void evaluateScoreForWorse(int player, int fullyRightColors, int rightColors);

void evaluateScore(int player, int fullyRightColors, int rightColors);

void Statistics();

#endif //MASTER_MIND_STATISTICS_H
