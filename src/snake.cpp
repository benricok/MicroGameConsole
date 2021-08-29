#include <snake.h>

Snake::Snake()
{
    intro();
    resetGame();
}

void Snake::intro()
{
}

void Snake::resetGame()
{
    d.fillScreen(BLACK);
}

Snake::Player::Player()
{
    reset();
}

void Snake::Player::reset()
{
}