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
    static Vector3 looking_at = {0.0f};

    camera.position = player_pos;
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};

    camera.target = PlayerView(GetMouseDelta());

    return camera;
}

Vector3 PlayerView(Vector2 mouse_pos) {
    static float phi = 0.0f;
    static float theta = 0.0f;
    static float prev_x_pos;
    static float prev_y_pos;

    prev_x_pos = mouse_pos.x;
    prev_y_pos = mouse_pos.y;

    float curr_x_pos = curr_x_pos - prev_x_pos;
    float curr_y_pos = curr_y_pos - prev_y_pos;

    phi += -curr_x_pos * 0.01f;
    theta = Clamp(theta + (-curr_y_pos * 0.01f), -PI / 3, PI / 3);

    Quaternion y_q = QuaternionFromAxisAngle((Vector3){0.0f, 1.0f, 0.0f}, phi);
    Quaternion x_q =
        QuaternionFromAxisAngle((Vector3){1.0f, 0.0f, 0.0f}, theta);

    Quaternion main_q = QuaternionMultiply(y_q, x_q);

    Vector3 looking_at = QuaternionToEuler(main_q);

    return looking_at;
}
