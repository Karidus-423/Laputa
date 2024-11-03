#ifndef MAIN_H
#define MAIN_H

#include "../menu/menu.h"
#include "player.h"
#include <math.h>
#include <raylib.h>
#include <stdio.h>

typedef enum GAMESTATE {
    MAINMENU,
    GAMELOOP,
    GAMEMENU,
    DEATHMENU,
} GAME_STATE;

void MainLoop(int *game_state, struct Player player);

#endif
