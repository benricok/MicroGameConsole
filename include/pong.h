#ifndef _PONG_H_
#define _PONG_H_

#include <Arduino.h>
#include <control.h>
#include <global.h>
#include <bitmap.h>
#include <display.h>

void loopPong();
void showScore();
void gameOver();
void initPong();

#endif