#include "level-utils.h"
#include "utils.h"
#include <raylib.h>
#include <raymath.h>
#include <stdbool.h>
#include <stdio.h>

World_t world = {
    .gravity = 9.81f,
};

int main() {
  Window_t win = {
      .height = 1000,
      .width = 1400,
  };

  InitWindow(win.width, win.height, "Laputa");
  SetTargetFPS(60);

  Camera3D player_cam = {
      .projection = CAMERA_PERSPECTIVE,
      .fovy = 45.0f,
      .target = (Vector3){0.0f, 1.0f, 1.0f},
      .position = (Vector3){0.0f, 1.0f, 10.0f},
      .up = (Vector3){0.0f, 1.0f, 0.0f},
  };

  Camera3D debug_cam = {
      .projection = CAMERA_PERSPECTIVE,
      .fovy = 45.0f,
      .target = (Vector3){0.0f, 0.0f, 0.0f},
      .position = (Vector3){0.0f, 10.0f, 10.0f},
      .up = (Vector3){0.0f, 1.0f, 0.0f},
  };

  Player_t p_main = {
      .cam = player_cam,
      .accel = 12,
  };

  Player_t p_debug = {
      .cam = debug_cam,
      .pos = (Vector3){0, 0, 0},
      .accel = 25,
  };

  Player_t *curr_player = &p_main;

  Debug_t d_opts = {
      .free = false,
      .debug_menu = false,
  };

  Level_t *selected_level = NULL;

  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_Y)) {
      d_opts.free = !d_opts.free;
      curr_player = d_opts.free ? &p_debug : &p_main;
      printf("%s\n", d_opts.free ? "DEBUG CAM" : "PLAYER CAM");
    }

    if (IsKeyPressed(KEY_Z)) {
      curr_player->cam.target = Vector3Zero();
    }

    PlayerUpdate(curr_player, d_opts.free);

    BeginDrawing();
    ClearBackground(BONE);
    DrawFPS(0, 0);
    BeginMode3D(curr_player->cam);

    DrawGrid(20, 1.0f);

    if (selected_level == NULL) {
      selected_level = LoadLevel(LEVEL_DEBUG);
    }

    if (selected_level->loaded == true) {
      DrawLevel(selected_level);
    }

    EndMode3D();
    EndDrawing();
  }

  if (selected_level != NULL) {
    UnloadLevel(selected_level);
  }

  CloseWindow();
}
