// An example demonstrating how to control the Adafruit Dot Star RGB LED
// included on board the ItsyBitsy M4 board.
// This randomly shifts the red, green and blue brightness

#include <Adafruit_DotStar.h>

// There is only one pixel on the board
#define NUMPIXELS 1 

//Use these pin definitions for the ItsyBitsy M4
#define DATAPIN    8
#define CLOCKPIN   6

Adafruit_DotStar px(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

void setup() {
  px.begin(); // Initialize pins for output
  px.show();  // Turn all LEDs off ASAP
  randomSeed(analogRead(0)); //initialise the random number generator
}

uint16_t red = 0, green = 0, blue = 0;

void loop() {
  px.setPixelColor(0, red, green, blue); // Set the pixel colors
  px.show();              // Refresh strip
  delay(20);              // Pause 20 milliseconds (~50 FPS)
  red   += random(-8, 8); // add random numbers to each pixel value
  green += random(-8, 8);
  blue  += random(-8, 8);
}
