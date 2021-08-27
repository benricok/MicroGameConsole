#include <Arduino.h>
#include <SSD_13XX.h>
#include <main.h>
#include <color.h>
#include <display.h>

boolean booted = false;

void setup()
{
  Serial.begin(9600);
  long unsigned debug_start = millis();
  while (!Serial && ((millis() - debug_start) <= 5000))
    ;
  Serial.println("Booting...");
  initDisplay() ? bootLog("Display", 1) : bootLog("Display", 0);

  delay(1000);
  tft.clearScreen();

  home();
  updateScreen();
}

void loop()
{
  updateScreen();
}

void updateScreen()
{
  if (millis() - lastMenuAction < menusTimeout)
  {
    home();
  }
}

void home()
{
}

bool initDisplay()
{
  tft.begin();
  uint8_t errorCode = 0;
  uint8_t w, h;
  errorCode = tft.getErrorCode();

  if (errorCode != 0)
  {
    Serial.println("Init error! ");
    if (bitRead(errorCode, 0))
      Serial.println("MOSI or SCLK pin mismach!\n\n");
    if (bitRead(errorCode, 1))
      Serial.println("CS or DC pin mismach!\n\n");
    return true;
  }

  tft.setArea(0, 0, 96, 64);
  for (h = 0; h < 64; h++)
  {
    for (w = 0; w < 96; w++)
    {
      if (w > 83)
      {
        tft.drawPixel(w, h, WHITE);
      }
      else if (w > 71)
      {
        tft.drawPixel(w, h, BLUE);
      }
      else if (w > 59)
      {
        tft.drawPixel(w, h, GREEN);
      }
      else if (w > 47)
      {
        tft.drawPixel(w, h, CYAN);
      }
      else if (w > 35)
      {
        tft.drawPixel(w, h, RED);
      }
      else if (w > 23)
      {
        tft.drawPixel(w, h, MAGENTA);
      }
      else if (w > 11)
      {
        tft.drawPixel(w, h, YELLOW);
      }
      else
      {
        tft.drawPixel(w, h, BLACK);
      }
    }
  }

  delay(1000);
  tft.clearScreen();
  tft.setCursor(0, 0);
  tft.setTextColor(WHITE);
  tft.setTextScale(1);
  return false;
}

void bootLog(String message, int status)
{
  switch (status)
  {
  case 0:
    Serial.println("[OK] " + message);
    tft.setTextColor(WHITE);
    tft.print("\n[");
    tft.setTextColor(GREEN);
    tft.print("OK");
    tft.setTextColor(WHITE);
    tft.print("] " + message);
    break;

  case 1:
    Serial.println("[ER] " + message);
    tft.setTextColor(WHITE);
    tft.print("\n[");
    tft.setTextColor(RED);
    tft.print("ER");
    tft.setTextColor(WHITE);
    tft.print("] " + message);
    break;

  default:
    break;
  }
}