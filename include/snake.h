#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <global.h>
#include <Arduino.h>
#include <bitmap.h>
#include <display.h>

class Snake
{
public:
    Snake();

private:
    class Player
    {
    public:
        Player();
        void reset();

    private:
    };
    void intro();
    void resetGame();
    const uint8_t maxLength = 464, startLength = 0;
};

#endif