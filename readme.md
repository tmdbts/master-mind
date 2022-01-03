# MASTER MIND GAME

[![Build Status](https://api.travis-ci.org/joemccann/dillinger.svg?branch=master)](https://github.com/tmdbts-ipp/introducao-a-programcao/tree/master/project)

## Run game

### Releases

Go to the [releases](https://github.com/tmdbts/master-mind/releases/) page and download the game executable

### Windows

To run this game use the executable on the `build/` folder

### Mac or Linux

Run this command on the project folder

```sh
./build/play
```

## Compile source

This game requires [GCC](https://gcc.gnu.org/) to compile.

```sh
gcc MainMenu.c Multiplayer.c Settings.c SinglePlayer.c Statistics.c constants.c helpers.c main.c -o ./build/play
```
