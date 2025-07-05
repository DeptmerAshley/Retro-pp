#include "game.h"
#include "raylib.h"

Game::Game(const Theme& selectedTheme) : theme(selectedTheme) {
    InitWindow(cellSize*cellCount, cellSize*cellCount, "Snake Game");
    SetTargetFPS(120);

}

Game::~Game() {
    CloseWindow();
}

void Game::run() {
    while (!WindowShouldClose()) {
        update();
        BeginDrawing();
        ClearBackground(theme.backgroundColor);
        render();
        //DrawText("Welcome to the Snake Engine!", 250, 280, 20, DARKGRAY);
        EndDrawing();
    }
}
