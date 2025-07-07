#ifndef GAME_H
#define GAME_H

#include "theme.h"

extern int offset;
extern int score;


class Game {
public:
    Game(const Theme& theme);
    virtual ~Game();
    void run();

    int cellSize = 30;
    int cellCount = 25;
    
protected:
    Theme theme;
    virtual void update() = 0;
    virtual void render() = 0;
};

#endif