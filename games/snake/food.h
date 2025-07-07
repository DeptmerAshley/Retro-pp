#ifndef FOOD_H
#define FOOD_H

#include "raylib.h"
#include <deque>
#include <raymath.h>

class Food {
public:
    Food(int size, int screenWidth, int screenHeight);
    ~Food();

    void Load();
    void Respawn(const std::deque<Vector2>& body);
    void Draw(Color color) const;
    Vector2 getPosition() const;
    int getSize() const;

private:
    Vector2 position = {0, 0};
    Texture2D texture;
    int size;
    int screenWidth;
    int screenHeight;
};

#endif
