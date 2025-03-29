#ifndef UTILS
#define UTILS

#include <raylib.h>
#include <stdbool.h>

#define BONE CLITERAL(Color){207, 207, 207, 255} // Black

typedef struct Debug_opts {
  bool free;
  bool debug_menu;
} Debug_t;

typedef struct window_opts {
  int width;
  int height;
} Window_t;

typedef struct player_opts {
  Camera3D cam;
  Vector3 pos;
  float accel;
} Player_t;

typedef struct world_opts {
  float gravity;
} World_t;

typedef struct object_opts {
  Mesh mesh;
  Model model;
  Vector3 center;
  BoundingBox bound_box;
} Object_t;

void CameraUpdate(Camera3D *camera, float accel, bool free);
void PlayerUpdate(Player_t *player, bool free_cam);
void CheckEvents();

#endif
