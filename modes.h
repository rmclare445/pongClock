uint16_t i, j;

void rainbow_loop( uint16_t loops, uint16_t wait, bool showTime ) {
  for(j=0; j<256*loops; j++) {
    rainbow( j );
    if (showTime) {showClock( false, strip.Color(150,150,150) );}
    strip.show();
    delay(wait);
  }
}

void rainbowRise_loop( uint16_t loops, uint16_t wait, bool showTime ) {
  for(j=0; j<256*loops; j++) {
    rainbowRise( j );
    if (showTime) {showClock( false, strip.Color(150,150,150) );}
    strip.show();
    delay(wait);
  }
}

void rainbowColumns_loop( uint16_t loops, uint16_t wait, bool showTime ) {
  for(j=0; j<256*loops; j++) {
    rainbowColumns( j );
    if (showTime) {showClock( false, strip.Color(150,150,150) );}
    strip.show();
    delay(wait);
  }
}

void rainbowShutter_loop( uint16_t loops, uint16_t wait, bool shut, bool showTime ) {
  for(j=0; j<256*loops; j++) {
    rainbowShutter( j, shut );
    if (showTime) {showClock( false, strip.Color(150,150,150) );}
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

void rainbowBreathe( uint16_t loops, uint16_t wait, bool showTime ) {
  for(i=0; i<loops; i++) {
    for(j=0; j<256; j++) {
      rainbowShutter( j, false );
      if (showTime) {showClock( false, strip.Color(150,150,150) );}
      strip.show();
      delay(wait);
    }
    for(j=0; j<256; j++) {
      rainbowShutter( j, true );
      if (showTime) {showClock( false, strip.Color(150,150,150) );}
      strip.show();
      delay(wait);
    }    
  }
}
