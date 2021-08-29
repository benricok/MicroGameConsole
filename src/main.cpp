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

#include <main.h>

boolean booted = false;

Pong pong;

void setup()
{
  Serial.begin(115200);

  Serial.println("Booting...");
  initDisplay() ? bootLog("Display", 1) : bootLog("Display", 0);
  initPins();
  delay(50);
  bootLog("Control Buttons", 0);
  delay(50);
  bootLog("Wifi comms", 1);
  delay(50);
  bootLog("Loaded Games", 0);
  delay(50);
  bootLog("Bluetooth", 1);

  delay(2000);

  pong.startPong(33, 20, 24, 8);
  pong.loopPong();
}

void loop()
{
  pong.loopPong();
}

bool initDisplay()
{
  d.begin();
  uint8_t errorCode = 0;
  uint8_t w, h;
  errorCode = d.getErrorCode();

  if (errorCode != 0)
  {
    Serial.println("Init error! ");
    if (bitRead(errorCode, 0))
      Serial.println("MOSI or SCLK pin mismach!\n\n");
    if (bitRead(errorCode, 1))
      Serial.println("CS or DC pin mismach!\n\n");
    return true;
  }

  d.setArea(0, 0, 96, 64);
  for (h = 0; h < 64; h++)
  {
    for (w = 0; w < 96; w++)
    {
      if (w > 83)
      {
        d.drawPixel(w, h, WHITE);
      }
      else if (w > 71)
      {
        d.drawPixel(w, h, BLUE);
      }
      else if (w > 59)
      {
        d.drawPixel(w, h, GREEN);
      }
      else if (w > 47)
      {
        d.drawPixel(w, h, CYAN);
      }
      else if (w > 35)
      {
        d.drawPixel(w, h, RED);
      }
      else if (w > 23)
      {
        d.drawPixel(w, h, MAGENTA);
      }
      else if (w > 11)
      {
        d.drawPixel(w, h, YELLOW);
      }
      else
      {
        d.drawPixel(w, h, BLACK);
      }
    }
  }

  delay(200);
  d.clearScreen();
  d.setCursor(0, 0);
  d.setTextColor(WHITE);
  d.setTextScale(1);
  return false;
}

void initPins()
{
  pinMode(UP_BUTTON, INPUT_PULLUP);
  pinMode(DOWN_BUTTON, INPUT_PULLUP);
}

void bootLog(String message, int status)
{
  switch (status)
  {
  case 0:
    Serial.println("[OK] " + message);
    d.setTextColor(WHITE);
    d.print("\n[");
    d.setTextColor(GREEN);
    d.print("OK");
    d.setTextColor(WHITE);
    d.print("] " + message);
    break;

  case 1:
    Serial.println("[ER] " + message);
    d.setTextColor(WHITE);
    d.print("\n[");
    d.setTextColor(RED);
    d.print("ER");
    d.setTextColor(WHITE);
    d.print("] " + message);
    break;

  default:
    break;
  }
}