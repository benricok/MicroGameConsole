#ifndef _MAIN_H_
#define _MAIN_H_

#include <Arduino.h>
#include <color.h>
#include <display.h>
#include <bitmap.h>
#include <control.h>
#include <pong.h>
#include <global.h>

#define _numMenus 3 //Home, Notifications, Settings

const int menusTimeout = 20000;
long long lastMenuAction = 0;
const String MenuItems[_numMenus] = {
    "Home",
    "Notifications",
    "Settings",
};

//Boot
void bootLog(String message, int status);
bool initDisplay();
void initPins();

#endif