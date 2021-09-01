// Import Adafruit Neopixel library for LEDs
#include <Adafruit_NeoPixel.h>

// Date and time functions for DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 rtc;

#define PIN 6
#define TMIL false

// Sums for finding LED number based on row
const int R[7]={-1,16,34,53,72,90,107};

// Pixel width of each number
const int w[11]={3,2,3,3,2,3,3,2,3,2,1};
// Pixel width of column lead
int v[11]={1,0,0,0,2,0,1,2,1,2,1};

// Initialize LED strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(128, PIN, NEO_GRB + NEO_KHZ800);

// Import local packages
#include "numbers.h"
#include "patterns.h"
#include "rainbow_patterns.h"
#include "modes.h"

void setup() {
  // Set up real-time clock and initialize with computer time
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // Set up LED strip
  strip.begin();
  strip.setBrightness(25);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Primary clock functioning
  if (rtc.now().minute()==59 && rtc.now().second()>57) {
    rainbowShutter_loop( 5, 4, false, true, true );
  }
  else if (rtc.now().second()>57) {
    rainbowSweep( 1, 40, Wheel( rtc.now().second()*255/60 ) );
  }
  fullShutter_loop( true );
}
