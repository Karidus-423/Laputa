#include "utils.h"

void PlayerUpdate(Player_t *player, bool free_cam) {
  CameraUpdate(&player->cam, player->accel, free_cam);
}
