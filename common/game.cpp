// game.cpp
#include "game.h"

const int cellSize = 30;
const int cellCount = 25;
const int offset = 50;

Game::Game(const Theme& selectedTheme) : theme(selectedTheme) {
    InitWindow(2 * offset + cellSize * cellCount, 
               2 * offset + cellSize * cellCount, 
               "Snake Game");
    SetTargetFPS(120);
}

Game::~Game() {
    CloseWindow();
}

void Game::run() {
    const float fixedTimeStep = 1.0f / 120.0f; // Logic updates 120 times/sec
    float lag = 0.0f;
    float previousTime = GetTime();

    while (!WindowShouldClose()) {
        float currentTime = GetTime();
        float deltaTime = currentTime - previousTime;
        previousTime = currentTime;
        lag += deltaTime;

        while (lag >= fixedTimeStep) {
            update(fixedTimeStep);
            lag -= fixedTimeStep;
        }

        BeginDrawing();
        ClearBackground(theme.backgroundColor);
        //Draw();
        render();
        EndDrawing();
    }

    Unload();
}
