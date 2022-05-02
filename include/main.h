// -----------------------------------------------------------------------------
//
//  Copyright (C) 2021  Benrico Krog
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Affero General Public License as published
//  by the Free Software Foundation version 3 of the License.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Affero General Public License for more details.
//
//  You should have received a copy of the GNU Affero General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>
//
// -----------------------------------------------------------------------------

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

//Boot
void bootLog(String message, int status);
bool initDisplay();
void initPins();

#endif