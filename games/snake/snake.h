#ifndef SNAKE_H
#define SNAKE_H

#include <raylib.h>
#include "common/game.h"

class Snake : public Game {
 public:
    Snake(const Theme& theme);

    int cellSize = 30;
    int cellCount = 25;

 protected:
    void update() override;
    void render() override;

 private:
    class Food {
     public:
        Food(int size, int screenWidth, int screenHeight)
    }

};

class Food {
 public:
    Vector2 position = {5, 6};

    void Draw() {
        DrawRectangle(position.x * Snake->cellSize, position.y * cellSize, cellSize, cellSize, {255, 8, 0, 255});
    }
};

#endif