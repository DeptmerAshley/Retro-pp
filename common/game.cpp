#include "game.h"
#include "raylib.h"

Game::Game(const Theme& selectedTheme) : theme(selectedTheme) {
    InitWindow(800, 600, "Snake Game");
    SetTargetFPS(120);
}

Game::~Game() {
    CloseWindow();
}

void Game::run() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(theme.backgroundColor);
        //DrawText("Welcome to the Snake Engine!", 250, 280, 20, DARKGRAY);
        EndDrawing();
    }
}
