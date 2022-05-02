#include <global.h>

extern const uint8_t dWidth = 96;
extern const uint8_t dHeight = 64;

extern const uint8_t dDrawWidth = dWidth - 1, dDrawHeight = dHeight - 1;

void drawCourt()
{
    d.drawRect(0, 0, dDrawWidth, dDrawHeight, WHITE);
}
