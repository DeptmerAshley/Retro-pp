#ifndef STARFOOD_H
#define STARFOOD_H

#include "item.h"

class starFood : public Item {
public:
    starFood(int size, int screenWidth, int screenHeight);
    ~starFood();

    void Load() override;
    void Respawn(const std::deque<Vector2>& body, Vector2 foodPos);
    void Draw(Color color) const override;
    Vector2 getPosition() const override;
    int getSize() const override;

private:
    Vector2 position = {0, 0};
    Texture2D texture;
    int size;
    int screenWidth;
    int screenHeight;
};

#endif
