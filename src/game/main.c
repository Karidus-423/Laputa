#include <math.h>
#include <raylib.h>
#include <stdio.h>

int main(void) {
    int window_width = 900;
    int window_height = 500;

    InitWindow(window_width, window_height, "Laputa");
    SetTargetFPS(60);

    Vector3 origin = {0.0f, 0.0f, 0.0f};
    Vector3 sphere_pos = {0.0f, 2.0f, 0.0f};

    Camera3D camera = {0};
    camera.position = (Vector3){15.0f, 5.0f, 0.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.projection = CAMERA_PERSPECTIVE;

    while (WindowShouldClose() == false) {
        float delta = GetFrameTime();
        BeginDrawing();
        ClearBackground(GRAY);
        UpdateCamera(&camera, CAMERA_ORBITAL);
        BeginMode3D(camera);

        DrawSphere(sphere_pos, 1.0f, RED);
        DrawPlane(origin, (Vector2){10.0f, 10.0f}, BLUE);

        if (IsKeyDown(KEY_W) == true) {
            sphere_pos.x += 8.5f * delta;
        }
        if (IsKeyDown(KEY_S) == true) {
            sphere_pos.x -= 8.5f * delta;
        }
        if (IsKeyDown(KEY_A) == true) {
            sphere_pos.z += 8.5f * delta;
        }
        if (IsKeyDown(KEY_D) == true) {
            sphere_pos.z -= 8.5f * delta;
        }
        if (IsKeyPressed(KEY_SPACE) && sphere_pos.y != 10.0f) {
            sphere_pos.y += 10.0f * -cosf(100.0f * delta);
        } else if (sphere_pos.y > 5.0f) {
            sphere_pos.y -= sinf(5.0f * delta);
        }

        EndMode3D();
        EndDrawing();
    }

    CloseWindow();
}
