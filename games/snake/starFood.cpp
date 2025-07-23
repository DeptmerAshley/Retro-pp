#include "starFood.h"
#include "raylib.h"
#include "game.h" // For offset
#include <raymath.h>

starFood::starFood(int size, int screenWidth, int screenHeight)
    : size(size), screenWidth(screenWidth), screenHeight(screenHeight) {
    texture = {0};
}

void starFood::Load() {
    texture = LoadTexture("assets/starFood.png");
}

void starFood::Respawn(const std::deque<Vector2>& body, const Vector2 foodPos) {
    bool valid;
    do {
        position.x = (float)(GetRandomValue(0, (screenWidth / size) - 1));
        position.y = (float)(GetRandomValue(0, (screenHeight / size) - 1));
        valid = true;
        for (const Vector2& seg : body) {
            if (Vector2Equals(position, seg)) {
                valid = false;
                break;
            }
        }

        if (Vector2Equals(position, foodPos)) {
            valid = false;
        }
    } while (!valid);
}

void starFood::Draw(Color color) const {
    Vector2 drawPos = {
        offset + position.x * size,
        offset + position.y * size
    };
    DrawTextureV(texture, drawPos, WHITE);
}

Vector2 starFood::getPosition() const {
    return position;
}

int starFood::getSize() const {
    return size;
}

starFood::~starFood() {
    UnloadTexture(texture);
}
