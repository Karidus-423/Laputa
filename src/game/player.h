#ifndef PLAYER_H
#define PLAYER_H

#include "camera.h"
#include <stdbool.h>

struct Player {
    bool alive;
    Camera3D player_Camera;
    Vector3 player_Position;
    float player_Speed;
    float player_Acceleration;
};

struct Player InitPlayer();
void PlayerState(struct Player player);

#endif
