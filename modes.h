uint16_t i, j;

// Will act as delay function but still updates clock
//  Input 'wait' in seconds
void full_color( uint16_t wait, uint32_t color ){
  for(i=0; i<wait; i++) {
    showClock( TMIL, strip.Color(150,150,150) );
    strip.show();
    delay(1);
    strip.fill(color);
  }
}

// Cascading colors based on row
void rainbowCascade_loop( uint16_t loops, uint16_t wait, bool showTime ) {
  for(j=0; j<256*loops; j++) {
    rainbowCascade( j );
    if (showTime) {showClock( TMIL, strip.Color(150,150,150) );}
    strip.show();
    delay(wait);
  }
}

// Basically rainbowCascade but in reverse
void rainbowRise_loop( uint16_t loops, uint16_t wait, bool showTime ) {
  for(j=0; j<256*loops; j++) {
    rainbowRise( j );
    if (showTime) {showClock( TMIL, strip.Color(150,150,150) );}
    strip.show();
    delay(wait);
  }
}

// Columns of colors move across the matrix
void rainbowColumns_loop( uint16_t loops, uint16_t wait, bool showTime ) {
  for(j=0; j<256*loops; j++) {
    rainbowColumns( j );
    if (showTime) {
      if (digitalRead(switchPin) == LOW) {return;}  // For non-greeting interruption by switch
      showClock( TMIL, strip.Color(150,150,150) );
    }
    strip.show();
    delay(wait);
  }
}

// Closes or opens a single color around the center column
void shutter_loop( uint16_t loops, uint16_t wait, uint32_t color, bool shut, bool showTime ) {
  uint8_t c;
  for(i=0; i<loops; i++) {
    for(c=1; c<11; c++) {
      shutter( c, shut, color );
      if (showTime) {showClock( TMIL, strip.Color(150,150,150) );}
      strip.show();
      delay(wait);
    }
  }
}

//
void fullShutter_loop( bool shut ) {
  uint8_t sec;
  sec = rtc.now().second();
  shutter_loop( 1, 30, Wheel( sec*255/60 ), false, true );
  if (rtc.now().second()>57) {return;}
  full_color(300, Wheel( sec*255/60 ));
}

void fullFade_loop( ) {
  uint8_t sec;
  sec = rtc.now().second();
  strip.fill(( Wheel( sec*255/60 ) ));
  showClock( TMIL, strip.Color(150,150,150) );
  strip.show();
}

// Either opens or closes a rainbow pattern around the center column
void rainbowShutter_loop( uint16_t loops, uint16_t wait, bool shut, bool soft, bool showTime ) {
  for(j=0; j<256*loops; j++) {
    rainbowShutter( j, shut, soft );
    if (showTime) {showClock( TMIL, strip.Color(150,150,150) );}
    strip.show();
    delay(wait);
  }  
}

//
void rainbowSweep( uint16_t loops, uint16_t wait, bool trans ) {
  for(i=0; i<loops; i++) {
    rainbowWipe( wait, trans );
    delay(500);
    wipe( wait, Wheel( rtc.now().second()*255/60 ), true, true );
  }
}

void greeting( uint16_t wait ) {
  rainbowWipe( wait, false );
  rainbowColumns_loop( 1, 4, false );
  if (digitalRead(switchPin) == LOW) 
    {wipe( wait, Wheel( rtc.now().second()*255/60 ), true, true );
  }
}

// rainbowShutter back and forth
void rainbowBreathe( uint16_t loops, uint16_t wait, bool soft, bool showTime ) {
  for(i=0; i<loops; i++) {
    for(j=0; j<256; j++) {
      rainbowShutter( j, false, soft );
      if (showTime) {showClock( TMIL, strip.Color(150,150,150) );}
      strip.show();
      delay(wait);
    }
    for(j=0; j<256; j++) {
      rainbowShutter( j, true, soft );
      if (showTime) {showClock( TMIL, strip.Color(150,150,150) );}
      strip.show();
      delay(wait);
    }    
  }
}
