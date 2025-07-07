#ifndef SNAKEBODY_H
#define SNAKEBODY_H

#include "raylib.h"
#include <deque>
#include "theme.h"
#include <raymath.h>

class SnakeBody {
public:
    SnakeBody();

    void Draw(int cellSize, const Theme& theme);
    void update(bool grow);

    std::deque<Vector2> body;
    Vector2 direction;
    Vector2 nextDirection;
    Vector2 snakeHead;
};

#endif
