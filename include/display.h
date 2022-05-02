#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <SSD_13XX.h>
#include <SPI.h>

#define __mosi 23  // 23
#define __sclk 18  // 18
#define __CS D8  // 17
#define __DC D4  // 16
#define __rst D3  // 5

extern SSD_13XX d;

#endif