#include "main.h"
#include "player.h"
#include "raylib.h"

int main(void) {
    int window_width = 900;
    int window_height = 500;

    InitWindow(window_width, window_height, "Laputa");
    SetTargetFPS(60);

    Vector3 origin = {0.0f, 0.0f, 0.0f};
    static Vector3 current_pos = {0};

    while (WindowShouldClose() == false) {
        float delta = GetFrameTime();
        BeginDrawing();
        ClearBackground(GRAY);

        current_pos = PlayerMove(&delta);

        BeginMode3D(PlayerCamera(current_pos));

        DrawPlane(origin, (Vector2){10.0f, 10.0f}, BLUE);

        EndMode3D();

        EndDrawing();
    }

    CloseWindow();
}
