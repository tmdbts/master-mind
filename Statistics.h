//
// Created by James Whitever on 16/12/2021.
//

#ifndef MASTER_MIND_STATISTICS_H
#define MASTER_MIND_STATISTICS_H

static int totalPoints[2] = {0, 0};

static int averagePoints[2] = {0, 0};

static int totalPlayedGames = 0;

static int playedGames[2] = {0, 0};

static int wonGames[2] = {0, 0};

static int bestResult[2][3] = {{0, 0, 0}, {0, 0, 0}};

static int worseResult[2][3] = {{0, 0, 0}, {0, 0, 0}};

void printStatistics();

void setTotalPoints(int player, int value);

void setAveragePoints(int player, int value);

void setTotalGames();

void setPlayedGames(int player, int value);

void setWonGames(int player, int value);

void setBestResult(int player, int target, int value);

void setWorseResult(int player, int target, int value);

#endif //MASTER_MIND_STATISTICS_H
