uint16_t i, j;

// Will act as delay function but still updates clock
//  Input 'wait' in seconds
void full_color( uint16_t wait, uint32_t color ){
  for(i=0; i<wait+1; i++) {
    showClock( TMIL, strip.Color(150,150,150) );
    strip.show();
    delay(1);
    strip.fill(color);
  }
}

void rainbow_loop( uint16_t loops, uint16_t wait, bool showTime ) {
  for(j=0; j<256*loops; j++) {
    rainbow( j );
    if (showTime) {showClock( TMIL, strip.Color(150,150,150) );}
    strip.show();
    delay(wait);
  }
}

void rainbowRise_loop( uint16_t loops, uint16_t wait, bool showTime ) {
  for(j=0; j<256*loops; j++) {
    rainbowRise( j );
    if (showTime) {showClock( TMIL, strip.Color(150,150,150) );}
    strip.show();
    delay(wait);
  }
}

void rainbowColumns_loop( uint16_t loops, uint16_t wait, bool showTime ) {
  for(j=0; j<256*loops; j++) {
    rainbowColumns( j );
    if (showTime) {showClock( TMIL, strip.Color(150,150,150) );}
    strip.show();
    delay(wait);
  }
}

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

void rainbowShutter_loop( uint16_t loops, uint16_t wait, bool shut, bool soft, bool showTime ) {
  for(j=0; j<256*loops; j++) {
    rainbowShutter( j, shut, soft );
    if (showTime) {showClock( TMIL, strip.Color(150,150,150) );}
    strip.show();
    delay(wait);
  }  
}

void rainbowSweep( uint16_t loops, uint16_t wait ) {
  for(i=0; i<loops; i++) {
    rainbowWipe( wait );
    wipe( wait, strip.Color(0,0,0) );
  }
}

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
