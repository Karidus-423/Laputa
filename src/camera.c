#include <raylib.h>
#include <raymath.h>
#include <rcamera.h>

void CameraUpdate(Camera3D *camera, float accel, bool free) {
  Vector2 mouse_delta = GetMouseDelta();
  float cameraMoveSpeed = accel * GetFrameTime();

  /*CameraYaw(camera, -mouse_delta.x * 0.003f, false);*/
  /*CameraPitch(camera, -mouse_delta.y * 0.003f, true, false, false);*/

  if (IsKeyDown(KEY_W))
    CameraMoveForward(camera, cameraMoveSpeed, true);
  if (IsKeyDown(KEY_A))
    CameraMoveRight(camera, -cameraMoveSpeed, true);
  if (IsKeyDown(KEY_S))
    CameraMoveForward(camera, -cameraMoveSpeed, true);
  if (IsKeyDown(KEY_D))
    CameraMoveRight(camera, cameraMoveSpeed, true);

  if (free == true) {
    if (IsKeyDown(KEY_SPACE))
      CameraMoveUp(camera, cameraMoveSpeed);
    if (IsKeyDown(KEY_LEFT_CONTROL))
      CameraMoveUp(camera, -cameraMoveSpeed);
  }
}
