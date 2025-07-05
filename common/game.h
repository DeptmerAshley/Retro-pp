#ifndef GAME_H
#define GAME_H

#include "theme.h"

class Game {
public:
    Game(const Theme& theme);
    ~Game();
    void run();

private:
    Theme theme;
};

#endif