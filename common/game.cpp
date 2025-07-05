#include "game.h"
#include "raylib.h"

Color mapBack = {17,124,19,255};

Game::Game() {
    InitWindow(800, 600, "Snake Game");
    SetTargetFPS(120);
}

Game::~Game() {
    CloseWindow();
}

void Game::run() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(mapBack);
        //DrawText("Welcome to the Snake Engine!", 250, 280, 20, DARKGRAY);
        EndDrawing();
    }
}
