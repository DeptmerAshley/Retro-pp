#include "game.h"
#include "theme.h"

int main() {

    Theme snakeTheme = {
        {17,124,19,255}
    };

    Game game(snakeTheme);
    game.run();
    return 0;
}