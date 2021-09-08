// Import Adafruit Neopixel library for LEDs
#include <Adafruit_NeoPixel.h>

// Date and time functions for DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 rtc;

// Data pin for LEDs
#define PIN 6
// Military time (24-hour clock)
#define TMIL false

const int buttonPin = 2;
int buttonState = 0;

// Initialize LED strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(128, PIN, NEO_GRB + NEO_KHZ800);

// Import local packages
#include "numbers.h"
#include "rainbow_patterns.h"
#include "patterns.h"
#include "modes.h"

void setup() {
  pinMode(buttonPin, INPUT);
  // Set up real-time clock and initialize with computer time
  rtc.begin();
  if (! rtc.isrunning()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  // Set up LED strip
  strip.begin();
  strip.setBrightness(15);
  strip.show(); // Initialize all pixels to 'off'
  // Greeting sequence
  greeting( 50 );
}

void loop() {
  //buttonState = digitalRead(buttonPin);
  //if (buttonState == LOW) {
    // Primary clock functioning
    //if (rtc.now().second()>57) {    // Used to test hour changes
    if (rtc.now().minute()==59 && rtc.now().second()>57) {
      delay(2000);
      rainbowShutter_loop( 4, 2, false, true, true );
    }
    else if (rtc.now().second()>57) {
      delay(500);
      rainbowSweep( 1, 40, true );
    }
    //fullShutter_loop( true );
    fullFade_loop( );
  //}
  //else {
    // Secondary - Demo mode
    //rainbowColumns_loop( 1, 4, true );
  //}
}
