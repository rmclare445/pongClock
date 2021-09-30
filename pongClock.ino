/*
 * 
 * 
 * 
 * 
 * Should rebuild codebase so that demo functions are entirely separate from
 *  clock functions.  This should fix delays like those present in demo mode
 *  while switching showTime and back to clock function.
 * 
 * Really should just rebuild codebase in general.
 *  Move all TMIL switch statements to showClock function!
 * 
 * 
 * 
 */





// Import Adafruit Neopixel library for LEDs
#include <Adafruit_NeoPixel.h>

// Date and time functions for DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 rtc;

// Data pin for LEDs
#define LPIN 6
// Analog pin for potentiometer
#define PPIN 2
// Military time (24-hour clock)
bool TMIL;

// Digital input pin for switch
const int tmilPin = 2;
const int modePin = 3;

uint8_t brt, prev_brt;
uint8_t rtc_sec;

// Initialize LED strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(128, LPIN, NEO_GRB + NEO_KHZ800);

// Import local packages
#include "numbers.h"
#include "rainbow_patterns.h"
#include "patterns.h"
#include "modes.h"
#include "demos.h"

void setup() {
  // Military time switch initialization
  pinMode(tmilPin, INPUT);
  if (digitalRead(tmilPin) == LOW) {TMIL=false;}
  else {TMIL=true;}
  // Demo mode switch initialization
  pinMode(modePin, INPUT);
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
//  brt = min(analogRead(PPIN), 1000);
//  if (brt != prev_brt) {
//  if ((brt-prev_brt)>10) {
//    strip.setBrightness( round(100 * (brt/1000.)) );
//    prev_brt = brt;
//  }
  if (digitalRead(tmilPin) == LOW) {TMIL=false;}
  else {TMIL=true;}

  if (digitalRead(modePin) == LOW) {
    // Primary clock functioning
    rtc_sec = rtc.now().second();
    //if (rtc_sec>57) {    // Used to test hour changes
    if (rtc.now().minute()==59 && rtc_sec>57) {
      delay(2000);
      rainbowShutter_loop( 4, 2, false, true, true );
    }
    else if (rtc_sec>57) {
      delay(750);
      rainbowSweep( 1, 40, true );
    }
    //fullShutter_loop( true );
    fullFade_loop( );
  }
  else {
    // Secondary - Demo mode
    //rainbowColumns_loop( 1, 4, true );
    demo_random( 15 );
  }
}
