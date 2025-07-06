#include "snake.h"
#include <raylib.h>
#include <raymath.h>

Snake::Snake(const Theme& theme) :
    Game(theme), food(30, 750, 750) {}

void Snake::update() {
    this->moveTimer += GetFrameTime();

    if (this->moveTimer >= this->moveDelay) {
        this->moveTimer = 0.0f;
        snakeBody.direction = snakeBody.nextDirection;
        snakeBody.update(false);

        Vector2 foodPos = Vector2Divide(food.getPosition(), {(float)cellSize, (float)cellSize});
        if (Vector2Equals(snakeBody.snakeHead, foodPos)) {
            food.Respawn();
            snakeBody.update(true);
        }

        if (snakeBody.snakeHead.x < 0 || snakeBody.snakeHead.y < 0 ||
            snakeBody.snakeHead.x >= cellCount || snakeBody.snakeHead.y >= cellCount) {
                CloseWindow();
            }

        

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
}


void Snake::render() {
    ClearBackground(theme.backgroundColor);
    food.Draw(theme.snakeFood);
    snakeBody.Draw(cellSize, theme);
}

// Food class

void Snake::Food::Respawn() {
    position.x = (float)(GetRandomValue(0, (screenWidth - size) / size) * size);
    position.y = (float)(GetRandomValue(0, (screenHeight - size) / size) * size);

}

void Snake::Food::Draw(Color color) const {
    //DrawRectangleV(position, {(float)size, (float)size}, color);
    DrawTextureV(texture, position, WHITE);
}

Vector2 Snake::Food::getPosition() const {
    return position;
}

int Snake::Food::getSize() const {
    return size;
}

// SnakeBody class

void Snake::SnakeBody::Draw(int cellSize, const Theme& theme) {
    for(const Vector2& segment : body) {
        Rectangle seg = {
            segment.x * cellSize,
            segment.y * cellSize,
            (float)cellSize,
            (float)cellSize
        };
        DrawRectangleRounded(seg, 0.5f, 6, theme.snakeBody);
        snakeHead = body.front();
    }
}

void Snake::SnakeBody::update(bool newSeg) {
    Vector2 newHead = Vector2Add(body.front(), direction);
    body.push_front(newHead);
    if(newSeg == false)
    {
        body.pop_back();
    }
    snakeHead = newHead;
}