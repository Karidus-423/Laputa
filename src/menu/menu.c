#include "menu.h"
#include "../game/main.h"
#include "raylib.h"

void GameMenu(int *game_state) {
    BeginDrawing();
    ClearBackground(BLUE);
    if (IsKeyPressed(KEY_ONE) == true) {
        *game_state = GAMELOOP;
    }
    if (IsKeyPressed(KEY_TWO) == true) {
        *game_state = MAINMENU;
    }
    if (IsKeyPressed(KEY_FOUR) == true) {
        *game_state = DEATHMENU;
    }
    EndDrawing();
}
void MainMenu(int *game_state) {
    BeginDrawing();
    ClearBackground(GREEN);
    if (IsKeyPressed(KEY_ONE) == true) {
        *game_state = GAMELOOP;
    }
    if (IsKeyPressed(KEY_THREE) == true) {
        *game_state = GAMEMENU;
    }
    if (IsKeyPressed(KEY_FOUR) == true) {
        *game_state = DEATHMENU;
    }
    EndDrawing();
}
void DeathMenu(int *game_state) {
    BeginDrawing();
    ClearBackground(RED);
    if (IsKeyPressed(KEY_ONE) == true) {
        *game_state = GAMELOOP;
    }
    if (IsKeyPressed(KEY_TWO) == true) {
        *game_state = MAINMENU;
    }
    if (IsKeyPressed(KEY_THREE) == true) {
        *game_state = GAMEMENU;
    }
    EndDrawing();
}
