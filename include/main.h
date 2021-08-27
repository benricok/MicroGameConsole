#ifndef _MAIN_H_
#define _MAIN_H_

#define _numMenus 3 //Home, Notifications, Settings

const int menusTimeout = 20000;
long long lastMenuAction = 0;
const String MenuItems[_numMenus] = {
    "Home",
    "Notifications",
    "Settings",
};

bool initDisplay();
void home();
void updateScreen();

void bootLog(String message, int status);

#endif