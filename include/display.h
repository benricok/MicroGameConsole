#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <Arduino.h>
#include <SSD_13XX.h>

#define __mosi 23
#define __sclk 18
#define __CS 17
#define __DC 16
#define __rst 5

SSD_13XX tft = SSD_13XX(__CS, __DC, __rst);

#endif
