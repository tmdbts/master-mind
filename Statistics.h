//
// Created by James Whitever on 16/12/2021.
//

#ifndef MASTER_MIND_STATISTICS_H
#define MASTER_MIND_STATISTICS_H

/**
 * Stores the total points for each player
 */
extern int totalPoints[2];

/**
 * Stores the average points for each player
 */
static float averagePoints[2];

/**
 * Stores the total played games
 */
extern int totalPlayedGames;

/**
 * Stores the played games for each player
 */
extern int playedGames[2];

/**
 * Stores the won games for each player
 */
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

/**
 * Stores the total tries for each player
 */
extern int totalTries[2];

/**
 * Stores the average tries for each player
 */
static float averageTries[2];

/**
 * @param player the player
 * @param value the value to be stored
 */
void setTotalPoints(int player, int value);

void setAveragePoints(int player, float value);

/**
 * @return the total played games
 */
int getTotalPlayedGames();

void setTotalPlayedGames(int value);

/**
 * @param player the player
 * @param value the value to be stored
 */
void setPlayedGames(int player, int value);

/**
 * @param player the player
 * @param value the value to be stored
 */
void setWonGames(int player, int value);

/**
 * @param player the player
 * @param target the target (0 for right colors in the right place and 1 for the right colors in the wrong place
 * @param value the value to be stored
 */
void setBestResult(int player, int target, int value);

/**
 * @param player the player
 * @param target the target (0 for right colors in the right place and 1 for the right colors in the wrong place
 * @param value the value to be stored
 */
void setWorseResult(int player, int target, int value);

/**
 * @param player the player
 * @param value the value to be stored
 */
void setTotalTries(int player, int value);

/**
 * Updates the statistics for both players
 */
void updateStatistics();

/**
 * Prints the menu
 */
static void printStaticsMenu();

/**
 * Prints the status of a player
 *
 * @param player the player for the status to be shown
 */
static void showStats(int player);

/**
 * Reads the menu option from the user
 *
 * @return the chosen menu option
 */
static int pickFromStatisticsMenu();

/**
 * Checks if the score is better than the one stored
 *
 * @param player the player
 * @param fullyRightColors the right colors in the right place
 * @param rightColors the right colors in the wrong place
 */
static void evaluateScoreForBest(int player, int fullyRightColors, int rightColors);

/**
 * Checks if the score is worse than the one stored
 *
 * @param player the player
 * @param fullyRightColors the right colors in the right place
 * @param rightColors the right colors in the wrong place
 */
static void evaluateScoreForWorse(int player, int fullyRightColors, int rightColors);

/**
 * Evaluates for the best and worse scores
 *
 * @param player the player
 * @param fullyRightColors the right colors in the right place
 * @param rightColors the right colors in the wrong place
 */
void evaluateScore(int player, int fullyRightColors, int rightColors);

/**
 * Entry point for the Statistics
 */
void Statistics();

#endif //MASTER_MIND_STATISTICS_H
