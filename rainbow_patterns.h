// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel( byte WheelPos ) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

// Cascading colors based on row
void rainbowCascade( uint16_t j ) {
  uint16_t i;
  for(i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, Wheel((i+j) & 255));
  }
}

// Basically rainbow but in reverse
void rainbowRise( uint16_t j ) {
  uint8_t c, r;
  for(c=1; c<21; c++) {
    for(r=0; r<7; r++) {
      strip.setPixelColor(led_num(c, r), Wheel(((r*256/14)-j) & 255));
    }
  }
}

// Columns of colors move across the matrix
void rainbowColumns( uint16_t j ) {
  uint8_t c, r;
  for(c=1; c<21; c++) {
    for(r=0; r<7; r++) {
      strip.setPixelColor(led_num(c, r), Wheel(((c*256/20)-j) & 255));
    }
  }
}

// Either opens or closes a rainbow pattern around the center column
void rainbowShutter( uint16_t j, bool shut, bool soft ) {
  uint8_t c, r, i, s;
  if (shut) {i=-1;} else {i=1;}
  if (soft) {s=20;} else {s=10;}
  for(c=1; c<11; c++) {
    for(r=0; r<7; r++) {
      strip.setPixelColor(led_num(c, r), Wheel(((c*256/s)+j*i) & 255));
      strip.setPixelColor(led_num(21-c, r), Wheel(((c*256/s)+j*i) & 255));
    }
  }
}

// Wipes a rainbow pattern across the matrix with color based on column number
void rainbowWipe( uint16_t wait, bool showTime ) {
  uint8_t c, r;
  if (showTime) {showClock( TMIL, strip.Color(150,150,150) );}
  for(c=1; c<21; c++) {
    for(r=0; r<7; r++) {
      strip.setPixelColor(led_num(c,r), Wheel(((c*256/20)) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Intended only to succeed rainbowWipe and wipe if time is displayed
//  This function shows the time under the rainbow layer
void rainbowWipeFollow( uint8_t col ) {
  uint8_t c, r;
  for(c=col; c<21; c++) {
    for(r=0; r<7; r++) {
      strip.setPixelColor(led_num(c,r), Wheel(((c*256/20)) & 255));
    }
  }
}

// Shimmering rainbow border around clock
//rainbowBorder( ) {
//  
//}
