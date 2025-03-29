#include "utils.h"
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>

void PlayerUpdate(Player_t *player, bool free_cam) {
  Camera3D *cam = &player->cam;
  CameraUpdate(&player->cam, player->accel, free_cam);

  if (IsKeyPressed(KEY_I)) {
    Ray shoot;
    shoot.position = cam->position;
    shoot.direction =
        Vector3Normalize(Vector3Subtract(cam->target, cam->position));
    DrawLine3D(shoot.position, shoot.direction, RED);
  }
}
