#include "snakebody.h"
#include "game.h" // for offset

SnakeBody::SnakeBody() {
    body.push_front({10, 10}); // starting position
    direction = {1, 0};        // move right initially
    nextDirection = direction;
    snakeHead = body.front();
}

void SnakeBody::Draw(int cellSize, const Theme& theme) {
    for (const Vector2& segment : body) {
        Rectangle seg = {
            offset + segment.x * cellSize,
            offset + segment.y * cellSize,
            (float)cellSize,
            (float)cellSize
        };
        DrawRectangleRounded(seg, 0.5f, 6, theme.snakeBody);
    }
    snakeHead = body.front();
}

void SnakeBody::update(bool grow) {
    Vector2 newHead = Vector2Add(body.front(), direction);
    body.push_front(newHead);
    if (!grow) {
        body.pop_back();
    }
    snakeHead = newHead;
}
