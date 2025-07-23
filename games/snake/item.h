#ifndef ITEM_H
#define ITEM_H

#include "raylib.h"
#include <deque>
#include <raymath.h>

class Item {
 protected:
    virtual void Load() = 0;
    //virtual void Respawn(const std::deque<Vector2>& body) = 0;
    virtual void Draw(Color color) const= 0;
    virtual Vector2 getPosition() const = 0;
    virtual int getSize() const = 0;
};

#endif