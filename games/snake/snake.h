// snake.h
#ifndef SNAKE_H
#define SNAKE_H

#include "game.h"
#include "food.h"       
#include "snakebody.h"  
#include "starFood.h"

class Snake : public Game {
public:
    Snake(const Theme& theme);
    void Unload();

    void update(float deltaTime) override;
    void render() override;

    void setMoveDelay(float delay);
    float getMoveDelay() const;

    Texture2D headTex;
    Texture2D bodyTex;
    float headRot = 0.0f;

private:
    SnakeBody snakeBody;
    Food food;
    starFood star;

    float moveTimer = 0.0f;
    float moveDelay = 0.1f; // Speed: lower = faster
    int score = 0;

    void handleInput();
    void checkCollisions();
    void Draw();
};

#endif
