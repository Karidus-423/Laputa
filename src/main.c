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
      .height = 1100,
      .width = 1800,
  };

  InitWindow(win.width, win.height, "Laputa");
  SetTargetFPS(60);

  HideCursor();
  SetMousePosition(win.width / 2, win.height / 2);
  DisableCursor();

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
      .pos = (Vector3){0, 0, 0},
      .accel = 12,
      .debug = false,
  };

  Player_t p_debug = {
      .cam = debug_cam,
      .pos = (Vector3){0, 0, 0},
      .accel = 25,
      .debug = true,
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

    CheckEvents(curr_player);

    BeginDrawing();
    //---RENDERING START---//
    ClearBackground(BONE);
    DrawFPS(0, 0);
    //---3D VIEW START---//
    BeginMode3D(curr_player->cam);

    if (selected_level == NULL) {
      selected_level = LoadLevel(LEVEL_DEBUG);
    }
    if (selected_level->loaded == true) {
      DrawLevel(selected_level);
    }

    DrawGrid(10, 2.0f);

    EndMode3D();
    //---3D VIEW END---//
    DrawRing((Vector2){(float)win.width / 2, (float)win.height / 2}, 8, 10, 0,
             360, 30, GRAY);
    //---RENDERING END---//
    // PLEASE WORK---//
    EndDrawing();
  }

  if (selected_level != NULL) {
    UnloadLevel(selected_level);
  }

  CloseWindow();
}

void CheckEvents(Player_t *player) { PlayerUpdate(player); }
