#include "main.h"
#include "player.h"
#include "raylib.h"
#include "raymath.h"

int main(void) {

    int window_width = 900;
    int window_height = 500;
    InitWindow(window_width, window_height, "Laputa");
    SetTargetFPS(60);

    Vector3 origin = {0.0f, 0.0f, 0.0f};
    static Vector3 current_pos = {0};

    struct Player player = InitPlayer();

    int game_state = GAMELOOP;

    while (WindowShouldClose() == false) {
        switch (game_state) {
        case MAINMENU:
            MainMenu(&game_state);
            break;
        case GAMELOOP:
            MainLoop(&game_state, player);
            break;
        case GAMEMENU:
            GameMenu(&game_state);
            break;
        case DEATHMENU:
            DeathMenu(&game_state);
            break;
        }
    }

    CloseWindow();
}

// GAME LOOP
void MainLoop(int *game_state, struct Player player) {
    BeginDrawing();
    ClearBackground(SKYBLUE);

    /* TODO Remove Death and Main when complete. */
    if (IsKeyPressed(KEY_TWO) == true) {
        *game_state = MAINMENU;
    }
    if (IsKeyPressed(KEY_THREE) == true) {
        *game_state = GAMEMENU;
    }
    if (IsKeyPressed(KEY_FOUR) == true) {
        *game_state = DEATHMENU;
    }

    BeginMode3D(*camera);
    DrawPlane(Vector3Zero(), (Vector2){10.0f, 10.0f}, ORANGE);

    PlayerState(player);

    EndMode3D();

    EndDrawing();
}
