#ifndef PLAYER_H
#define PLAYER_H

#include "camera.h"

typedef struct Player_State {
    Vector3 Player_position;
    Vector3 Player_rotation;
    Vector3 Player_view;
    Camera3D Player_camera;
} Player_State;

Vector3 PlayerMove(float *delta);
Camera3D PlayerCamera(Vector3 player_pos);
Vector3 PlayerView(Vector2 mouse_pos);

#endif
