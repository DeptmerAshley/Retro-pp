#include "game.h"
#include "raylib.h"

Game::Game(const Theme& selectedTheme) : theme(selectedTheme) {
    InitWindow(2 * offset + cellSize*cellCount, 2* offset + cellSize*cellCount, "Snake Game");
    SetTargetFPS(120);

}

Game::~Game() {
    CloseWindow();
}

void Game::run() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        update();
        ClearBackground(theme.backgroundColor);
        DrawRectangleLinesEx(Rectangle{(float)offset-5, (float)offset-5, (float)cellSize*cellCount+10,(float)cellSize*cellCount+10}, 5, WHITE);
        DrawText("Snake++", offset, offset-40, 30, WHITE);
        DrawText("Score: ", cellSize*cellCount-(offset+45), offset-40, 30, WHITE);
        DrawText(TextFormat("%i", score), cellSize*cellCount-(offset-75), offset-40, 30, WHITE);
        render();
        EndDrawing();
    }
}
