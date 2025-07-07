#include "snake.h"
#include "raylib.h"

Snake::Snake(const Theme& theme)
    : Game(theme),
      food(cellSize, cellCount * cellSize, cellCount * cellSize) {
    food.Load();
    food.Respawn(snakeBody.body);
    headTex = LoadTexture("assets/snakeHead.png");
    bodyTex = LoadTexture("assets/snakeBody.png");
}

float Snake::getMoveDelay() const {
    return moveDelay;
}

void Snake::setMoveDelay(float delay) {
    if (delay > 0.0f) {
        moveDelay = delay;
    }
}

void Snake::update(float deltaTime) {
    handleInput(); // always respond to input

    moveTimer += deltaTime;
    if (moveTimer >= moveDelay) {
        moveTimer = 0.0f;

        snakeBody.direction = snakeBody.nextDirection;
        Vector2 nextHead = Vector2Add(snakeBody.body.front(), snakeBody.direction);

        // Wall collision
        if (nextHead.x < 0 || nextHead.y < 0 ||
            nextHead.x >= cellCount || nextHead.y >= cellCount) {
            CloseWindow();
        }

        // Self collision
        for (auto i = snakeBody.body.begin() + 1; i != snakeBody.body.end(); ++i) {
            if (Vector2Equals(nextHead, *i)) {
                CloseWindow();
            }
        }

        bool growing = Vector2Equals(nextHead, food.getPosition());

        if (growing) {
            food.Respawn(snakeBody.body);
            score++;
        }

        snakeBody.update(growing);
    }
}

void Snake::handleInput() {
    if (IsKeyDown(KEY_UP) && snakeBody.direction.y != 1) {
        snakeBody.nextDirection = {0, -1};
    }
    if (IsKeyDown(KEY_DOWN) && snakeBody.direction.y != -1) {
        snakeBody.nextDirection = {0, 1};
    }
    if (IsKeyDown(KEY_LEFT) && snakeBody.direction.x != 1) {
        snakeBody.nextDirection = {-1, 0};
    }
    if (IsKeyDown(KEY_RIGHT) && snakeBody.direction.x != -1) {
        snakeBody.nextDirection = {1, 0};
    }
}

void Snake::render() {
    DrawRectangleLinesEx(
        Rectangle{
            (float)offset - 5,
            (float)offset - 5,
            (float)cellSize * cellCount + 10,
            (float)cellSize * cellCount + 10
        },
        5,
        WHITE
    );

    DrawText("Snake++", offset, offset - 40, 30, WHITE);
    DrawText("Score:", cellSize * cellCount - (offset + 45), offset - 40, 30, WHITE);
    DrawText(TextFormat("%i", score), cellSize * cellCount - (offset - 75), offset - 40, 30, WHITE);

    food.Draw(theme.snakeFood);
    // snakeBody.Draw(cellSize, theme);
    Draw();
}

void Snake::Unload() {
    UnloadTexture(headTex);
    UnloadTexture(bodyTex);
}

void Snake::Draw() {
    const auto& segments = snakeBody.getBody();
    Vector2 direction = snakeBody.getDirection();

    if (segments.empty())
        return;

    // Get rotation based on direction
    float rotation = 0.0f;
    if (direction.x == 1) rotation = 0.0f;         // right
    else if (direction.x == -1) rotation = 180.0f; // left
    else if (direction.y == 1) rotation = 90.0f;   // down
    else if (direction.y == -1) rotation = 270.0f; // up

    // Draw body (excluding head)
    for (size_t i = 1; i < segments.size(); ++i) {
        Vector2 pos = segments[i];
        Rectangle dest = {
            offset + pos.x * cellSize + cellSize / 2.0f,
            offset + pos.y * cellSize + cellSize / 2.0f,
            (float)cellSize,
            (float)cellSize
        };

        DrawTexturePro(
            bodyTex,
            {0, 0, (float)bodyTex.width, (float)bodyTex.height},
            dest,
            {(float)cellSize / 2, (float)cellSize / 2},
            0.0f,
            WHITE
        );
    }

    // Draw head (rotated)
    Vector2 headPos = segments[0];
    Rectangle headDest = {
        offset + headPos.x * cellSize + cellSize / 2.0f,
        offset + headPos.y * cellSize + cellSize / 2.0f,
        (float)cellSize,
        (float)cellSize
    };

    DrawTexturePro(
        headTex,
        {0, 0, (float)headTex.width, (float)headTex.height},
        headDest,
        {(float)cellSize / 2, (float)cellSize / 2},
        rotation,
        WHITE
    );

}