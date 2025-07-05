#include "game.h"
#include "theme.h"
#include "snake.h"

#include <raylib.h>

int main() {

    Theme snakeTheme = {
        {17,124,19,255},
        {255, 8, 0, 255}
    };

    Snake game(snakeTheme);
    game.run();
    return 0;
}