#include "player.h"
#include "raylib.h"
#include "raymath.h"

// Declare the player instance

// Initialize the player instance
struct Player InitPlayer(/*Pass save file position for player*/) {
    struct Player player;
    player.alive = true;
    player.player_Position = (Vector3){0.0f, 0.0f, 0.0f};
    player.player_Speed = 0.0f;
    player.player_Acceleration = 0.0f;

    player.player_Camera.position = (Vector3){10.0f, 10.0f, 10.0f};
    player.player_Camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    player.player_Camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    player.player_Camera.fovy = 45.0f; // Camera field-of-view Y
    player.player_Camera.projection = CAMERA_PERSPECTIVE;

    return player;
}

void PlayerState(struct Player player) {
    if (player.alive == true) {
        UpdateCamera(&player.player_Camera, CAMERA_ORBITAL);
    } else {
        /*Death State*/
        // Mouse is only able to move
        // Two buttons to restart or quit
        return;
    }
}
