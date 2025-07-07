#include "food.h"
#include "raylib.h"
#include "game.h" // For offset

Food::Food(int size, int screenWidth, int screenHeight)
    : size(size), screenWidth(screenWidth), screenHeight(screenHeight) {
    texture = {0};
}

void Food::Load() {
    texture = LoadTexture("assets/snakeApple.png");
}

void Food::Respawn(const std::deque<Vector2>& body) {
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
    } while (!valid);
}

void Food::Draw(Color color) const {
    Vector2 drawPos = {
        offset + position.x * size,
        offset + position.y * size
    };
    DrawTextureV(texture, drawPos, WHITE);
}

Vector2 Food::getPosition() const {
    return position;
}

int Food::getSize() const {
    return size;
}
