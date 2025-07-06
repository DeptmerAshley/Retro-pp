#ifndef SNAKE_H
#define SNAKE_H

#include <raylib.h>
#include "common/game.h"
#include <cstdlib>
#include <deque>
#include <raymath.h>

class Snake : public Game {
 public:

    Snake(const Theme& theme);

    int cellSize = 30;
    int cellCount = 25;

 protected:
    void update() override;
    void render() override;

 private:

    float moveDelay = 0.1f;
    float moveTimer = 0.0f; 

    class Food {
     public:
        Food(int size, int screenWidth, int screenHeight) :
            size(size), screenWidth(screenWidth), screenHeight(screenHeight) {
                Image image = LoadImage("assets/snakeApple.png");
                texture = LoadTextureFromImage(image);
                UnloadImage(image);
                Respawn();
        }

        void Respawn();
        void Draw(Color color) const;
        Vector2 getPosition() const;
        int getSize() const;

        Vector2 position;
        int size;
        int screenWidth, screenHeight;
        Texture2D texture;

        ~Food()
        {
            UnloadTexture(texture);
        }
    };

    Food food;

    class SnakeBody {
    public:
        std::deque<Vector2> body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9} };
        Vector2 direction = {1,0};
        Vector2 nextDirection = {1, 0};
        void Draw(int cellSize, const Theme& theme);
        void update(bool newSeg);
        Vector2 snakeHead;
    };

    SnakeBody snakeBody;
};


#endif