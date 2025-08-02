/*

 Example sketch for TFT_eSPI library.

 No fonts are needed.
 
 Draws a 3d rotating cube on the TFT screen.
 
 Original code was found at http://forum.freetronics.com/viewtopic.php?f=37&t=5495
 
 */
#include <Wire.h>
// #include "FT62XXTouchScreen.h"

// 

#define DISPLAY_WIDTH  480
#define DISPLAY_HEIGHT 320
#define BLACK 0x0000
#define WHITE 0xFFFF

#include <SPI.h>

#include <TFT_eSPI.h> // Hardware-specific library

TFT_eSPI tft = TFT_eSPI(DISPLAY_HEIGHT, DISPLAY_WIDTH);       // Invoke custom library

// FT62XXTouchScreen touchScreen = FT62XXTouchScreen(DISPLAY_HEIGHT, PIN_SDA, PIN_SCL);

int currY = 0;

/***********************************************************************************************************************************/

void setup() {
  Serial.begin(115200);
  tft.init();

  // Backlight hack...
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, 128);

  // touchScreen.begin();

  // h = tft.height();
  // w = tft.width();

  tft.setRotation(1);

  tft.fillScreen(TFT_BLACK);
}

/***********************************************************************************************************************************/
void loop() {

  // TouchPoint touchPos = touchScreen.read();

  // if (touchPos.touched) {
  //  Serial.printf("X: %d, Y: %d\n", touchPos.xPos, touchPos.yPos);
  //  tft.drawCircle(touchPos.xPos, touchPos.yPos
  //  , 10, TFT_SILVER);
  //}

  int color = (currY / DISPLAY_HEIGHT) % 2 == 0 ? WHITE : BLACK;
  tft.drawLine(0, currY % DISPLAY_HEIGHT, DISPLAY_WIDTH, currY % DISPLAY_HEIGHT, color); // erase the old lines.
  currY++;
  delay(20);
}