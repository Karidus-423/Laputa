#include <raylib.h>
#include <raymath.h>
#include <rcamera.h>

// TODO: Change to use quaternions.

void CameraUpdate(Camera3D *camera, float accel, bool free) {
  Vector2 mouse_delta = GetMouseDelta();
  float player_speed = accel * GetFrameTime();

  CameraYaw(camera, -mouse_delta.x * 0.002f, false);
  CameraPitch(camera, -mouse_delta.y * 0.002f, true, false, false);

  if (IsKeyDown(KEY_W))
    CameraMoveForward(camera, player_speed, true);
  if (IsKeyDown(KEY_A))
    CameraMoveRight(camera, -player_speed, true);
  if (IsKeyDown(KEY_S))
    CameraMoveForward(camera, -player_speed, true);
  if (IsKeyDown(KEY_D))
    CameraMoveRight(camera, player_speed, true);

  if (free == true) {
    if (IsKeyDown(KEY_SPACE))
      CameraMoveUp(camera, player_speed);
    if (IsKeyDown(KEY_LEFT_CONTROL))
      CameraMoveUp(camera, -player_speed);
  }
}
