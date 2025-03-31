#include "utils.h"
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>

void PlayerUpdate(Player_t *player) {
  Camera3D *cam = &player->cam;
  CameraUpdate(&player->cam, player->accel, player->debug);

  if (IsKeyPressed(KEY_I)) {
    Ray shoot;
    shoot.position = cam->position;
    shoot.direction =
        Vector3Normalize(Vector3Subtract(cam->target, cam->position));
    DrawLine3D(shoot.position, shoot.direction, RED);
  }

  if (IsKeyPressed(KEY_Z)) {
    player->cam.target = Vector3Zero();
  }
}
