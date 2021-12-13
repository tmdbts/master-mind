cmake_minimum_required(VERSION 3.20)
project(project C)

set(CMAKE_C_STANDARD 99)

add_executable(game main.c MainMenu.c Settings.c SinglePlayer.c helpers.c constants.c)
