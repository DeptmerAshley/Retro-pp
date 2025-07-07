// game.h
#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "theme.h"

extern const int cellSize;
extern const int cellCount;
extern const int offset;

class Game {
public:
    Game(const Theme& selectedTheme);
    virtual ~Game();

    void run(); // Main game loop

protected:
    Theme theme;

    // Must be implemented by subclasses
    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;
    virtual void Draw() = 0;
    virtual void Unload() = 0;
};

#endif
