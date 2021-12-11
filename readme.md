# MASTER MIND GAME

[![Build Status](https://api.travis-ci.org/joemccann/dillinger.svg?branch=master)](https://github.com/tmdbts-ipp/introducao-a-programcao/tree/master/project)

## Game rules

    The game ca be played single player (PC vs Human) or multiplayer (Human vs Human).
    One of the player (encoder player) choses 4 of 6 colors in a sequence.
    The other player (decoder player) has to guess the sequence created by the encoder player.

## Implementation

    [x] - MainMenu
        [x] - Function to print the menu
        [x] - Function to ask for the option

    [] - SinglePlayer
        -> char name

        [] - Randomizer to pick a color

    [] - MultiPlayer
        -> char player1
        -> char player2

        [] - Randomizer to pick the player that choses the colors

    [] - Settings
        [] - Max number of tries
        [] - Max number of games per session

    [] - Stats
        [] - Total played games
        [] - Best results by player (points, right colors and right colors in the right places)
        [] - Worse results by player (points, right colors and right colors in the right places)

    [] - helpers
        ?[] - scan function

## Changes to the worksheet to be discussed with the teacher

    [] - The number of players instead of being a setting it will have an option for multiplayer of single player in the main menu
    [] - The identification of the players will be asked on the beginning of the game

## Run game

### Windows

To run this game use the executable on the `build/` folder

### Mac or Linux

Run this command on the project folder

```sh
./build/game
```

## Compile source

This game requires [GCC](https://gcc.gnu.org/) to compile.

```sh
gcc src.c -o build/game
```
