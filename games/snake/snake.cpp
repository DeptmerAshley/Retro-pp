#include "snake.h"
#include <raylib.h>

Snake::Snake(const Theme& theme) :
    Game(theme), food(30, 750, 750) {}

void Snake::update() {
    return;
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
    }
}

