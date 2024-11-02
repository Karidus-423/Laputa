#include "player.h"
#include <math.h>
#include <raylib.h>
#include <raymath.h>

Vector3 PlayerMove(float *delta) {
    static Vector3 player_pos = {0.0f, 2.0f, 0.0f};
    // DrawSphere(player_pos, 1.0f, RED);
    if (IsKeyDown(KEY_W) == true) {
        player_pos.x += 8.5f * *delta;
    }
    if (IsKeyDown(KEY_S) == true) {
        player_pos.x -= 8.5f * *delta;
    }
    if (IsKeyDown(KEY_A) == true) {
        player_pos.z += 8.5f * *delta;
    }
    if (IsKeyDown(KEY_D) == true) {
        player_pos.z -= 8.5f * *delta;
    }
    if (IsKeyPressed(KEY_SPACE) && player_pos.y != 10.0f) {
        player_pos.y += 10.0f * -cosf(100.0f * *delta);
    } else if (player_pos.y > 5.0f) {
        player_pos.y -= sinf(5.0f * *delta);
    }
    return player_pos;
}

Camera3D PlayerCamera(Vector3 player_pos) {
    Vector2 mouse_pos = GetMouseDelta();

    static Camera3D camera;

    camera.position = player_pos;
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};

    camera.target = PlayerView(GetMouseDelta());

    return camera;
}

Vector3 PlayerView(Vector2 mouse_pos) {
    // Get Vector2 Output Vector3 Target
    Vector3 looking_at;

    return looking_at;
}
