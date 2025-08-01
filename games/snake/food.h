#ifndef FOOD_H
#define FOOD_H

#include "item.h"

class Food : public Item {
public:
    Food(int size, int screenWidth, int screenHeight);
    ~Food();

<<<<<<< HEAD
    Food(int size, int screenWidth, int screenHeight, int itemType);

    void Load();
=======
    void Load() override;
>>>>>>> virtualItem
    void Respawn(const std::deque<Vector2>& body);
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
