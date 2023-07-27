#ifndef _PONG_H_
#define _PONG_H_

#include <Arduino.h>
#include <control.h>
#include <global.h>
#include <bitmap.h>
#include <display.h>

class Pong 
{
public:
    void loopPong();
    void startPong(short iPADDLE_RATE, short iBALL_RATE, short iPADDLE_HEIGHT, short iMAX_SCORE);

    // Game parameters
    short PADDLE_RATE;
    short BALL_RATE;
    uint8_t PADDLE_HEIGHT;
    short MAX_SCORE;

    // Live Game Parameters
    boolean gameIsRunning = true;
    boolean resetBall = false;

private:
    // Game clock
    unsigned long ball_update;
    unsigned long paddle_update;

    // Players position
    const uint8_t CPU_X = 6;
    uint8_t cpu_y;

    const uint8_t PLAYER_X = 89;
    uint8_t player_y;

    // Players score
    short CPU_SCORE;
    short PLAYER_SCORE;

    // Ball position
    uint8_t ball_x, ball_y, ball_dir_x, ball_dir_y;
    void showScore();
    void gameOver();
    void initPong();
};

#endif