// An example demonstrating how to control the onboard DotStar RGB LED
// Works for the following boards:
//   Adafruit ItsyBitsy M0 Express
//   Adafruit ItsyBitsy M4
//   Adafruit ItsyBitsy nRF52840
//   Adafruit Trinket M0
//   Adafruit PyRuler
//   Adafruit FunHouse
//   Adafruit GEMMA M0

#include <Adafruit_DotStar.h>

#ifndef DOTSTAR_NUM
#define DOTSTAR_NUM 1
#endif

#ifndef PIN_DOTSTAR_DATA
#define PIN_DOTSTAR_DATA 0
#endif

#ifndef PIN_DOTSTAR_CLK
#define PIN_DOTSTAR_CLK 1
#endif

// Everything is defined in the Board Support Package
// DOTSTAR_NUM        number of onboard DotStars (typically just 1)
// PIN_DOTSTAR_DATA   onboard DotStar data pin
// PIN_DOTSTAR_CLK    onboard DotStar clock pin
Adafruit_DotStar strip(DOTSTAR_NUM, PIN_DOTSTAR_DATA, PIN_DOTSTAR_CLK, DOTSTAR_BRG);

void setup() {
  strip.begin(); // Initialize pins for output
  strip.setHDGammaMode(true);
  strip.show();  // Turn all LEDs off ASAP
}

void loop() {
  // "Breathing pattern" for the leds.
  for (uint16_t val = 0; val < 256; ++val) {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, val, val, val);
    }
    strip.show();
    delay(10);
  }
}