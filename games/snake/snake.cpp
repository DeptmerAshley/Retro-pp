#include "snake.h"
int offset = 50;
int score = 0;

Snake::Snake(const Theme& theme) :
    Game(theme), food(30, 750, 750) {
        food.Respawn(snakeBody.body);
    }

void Snake::update() {
    this->moveTimer += GetFrameTime();

    if (this->moveTimer >= this->moveDelay) {
        this->moveTimer = 0.0f;
        snakeBody.direction = snakeBody.nextDirection;

        Vector2 nextHead = Vector2Add(snakeBody.body.front(), snakeBody.direction);

        if (nextHead.x < 0 || nextHead.y < 0 ||
            nextHead.x >= cellCount || nextHead.y >= cellCount) 
        {
            CloseWindow();
        }

        for (auto i = snakeBody.body.begin() + 1; i != snakeBody.body.end(); i++) {
            if (Vector2Equals(snakeBody.snakeHead, *i)) {
                CloseWindow();
            }
        }

        //Vector2 foodPos = Vector2Divide(food.getPosition(), {(float)cellSize, (float)cellSize});

        bool growing = Vector2Equals(nextHead, food.getPosition());

        if (growing) {
            food.Respawn(snakeBody.body);
            score++;
        }

        snakeBody.update(growing);

        if (IsKeyDown(KEY_UP) && snakeBody.direction.y != 1) {
            snakeBody.nextDirection = {0, -1};
        }
        if (IsKeyDown(KEY_DOWN) && snakeBody.direction.y != -1) {
            snakeBody.nextDirection = {0, 1};
        }
        if (IsKeyDown(KEY_LEFT) && snakeBody.direction.x != 1) {
            snakeBody.nextDirection = {-1, 0};
        }
        if (IsKeyDown(KEY_RIGHT) && snakeBody.direction.x != -1) {
            snakeBody.nextDirection = {1, 0};
        }

    }
}


void Snake::render() {
    ClearBackground(theme.backgroundColor);
    food.Draw(theme.snakeFood);
    snakeBody.Draw(cellSize, theme);
}

// Food class

void Snake::Food::Respawn(std::deque<Vector2> body) {
    bool valid;
    do {
        position.x = (float)(GetRandomValue(0, (screenWidth / size) - 1));
        position.y = (float)(GetRandomValue(0, (screenHeight / size) - 1));

        valid = true;

        for (auto i = body.begin(); i != body.end(); i++) {
            if (Vector2Equals(position, *i)) {
                valid = false;
                break;
            }
        }
    } while (!valid);
}

void Snake::Food::Draw(Color color) const {
    Vector2 drawPos = {
        offset + position.x * size,
        offset + position.y * size
    };
    DrawTextureV(texture, drawPos, WHITE);
}

Vector2 Snake::Food::getPosition() const {
    //return Vector2Scale(position, (float)size);
    return position;
}

int Snake::Food::getSize() const {
    return size;
}

// SnakeBody class

void Snake::SnakeBody::Draw(int cellSize, const Theme& theme) {
    for(const Vector2& segment : body) {
        Rectangle seg = {
            offset + segment.x * cellSize,
            offset + segment.y * cellSize,
            (float)cellSize,
            (float)cellSize
        };
        DrawRectangleRounded(seg, 0.5f, 6, theme.snakeBody);
        snakeHead = body.front();
    }
}

void Snake::SnakeBody::update(bool newSeg) {
    Vector2 newHead = Vector2Add(body.front(), direction);
    body.push_front(newHead);
    if(newSeg == false)
    {
        body.pop_back();
    }
    snakeHead = newHead;
}