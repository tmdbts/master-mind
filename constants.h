//
// Created by James Whitever on 13/12/2021.
//

#ifndef PROJECT_CONSTANTS_H
#define PROJECT_CONSTANTS_H

/**
 * Stores the available colors
 */
static const char COLORS[] = {'R', 'G', 'B', 'W', 'Y', 'O'};

/**
 * Stores the length of the COLORS array
 */
static const int COLORS_LENGTH = sizeof COLORS / sizeof(char);

/**
 * Stores the ANSI code for the default color
 */
static const char TERMINAL_COLOR_DEFAULT[] = "\x1B[0m";

/**
 * Stores the ANSI code for the color red
 */
static const char TERMINAL_COLOR_RED[] = "\x1B[31m";

/**
 * Stores the ANSI code for the color green
 */
static const char TERMINAL_COLOR_GREEN[] = "\x1B[32m";

/**
 * Stores the ANSI code for the color yellow
 */
static const char TERMINAL_COLOR_YELLOW[] = "\x1B[33m";

/**
 * Stores the ANSI code for the color blue
 */
static const char TERMINAL_COLOR_BLUE[] = "\x1B[34m";

/**
 * Stores the ANSI code for the color magenta
 */
static const char TERMINAL_COLOR_MAGENTA[] = "\x1B[35m";

/**
 * Stores the ANSI code for the color cyan
 */
static const char TERMINAL_COLOR_CYAN[] = "\x1B[36m";

/**
 * Stores the ANSI code for the color white
 */
static const char TERMINAL_COLOR_WHITE[] = "\x1B[37m";

#endif //PROJECT_CONSTANTS_H
