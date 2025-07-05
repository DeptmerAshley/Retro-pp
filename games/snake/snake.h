#ifndef SNAKE_H
#define SNAKE_H

#include <raylib.h>
#include "common/game.h"
#include <cstdlib>

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
        Food(int size, int screenWidth, int screenHeight) :
            size(size), screenWidth(screenWidth), screenHeight(screenHeight) {
                Respawn();
        }

        void Respawn();
        void Draw(Color color) const;
        Vector2 getPosition() const;
        int getSize() const;

     private:
        Vector2 position;
        int size;
        int screenWidth, screenHeight;
    };

    Food food;

};


#endif