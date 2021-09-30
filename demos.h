
void demo_simple( bool showTime ) {
  rainbowColumns_loop( 1, 4, showTime );
}

bool isDemoTime( ) {
  if (digitalRead(tmilPin) == LOW) {TMIL=false; return true;}
  else {return false;}
}

uint8_t sec_passage( uint8_t prev_sec ) {
  uint8_t now_sec = rtc.now().second();
  if (now_sec < prev_sec) {return now_sec + (60 - prev_sec);}
  else {return now_sec - prev_sec;}
}

void demo_random( uint8_t period ) {
  bool showTime;
  uint8_t prev_sec = rtc.now().second();
  uint8_t duration = 0;
  switch(random(5)) {
    case 0 :
      while (duration<period) {
        if (digitalRead(modePin) == LOW) {return;}
        showTime = isDemoTime( );
        rainbowColumns_loop( 1, 4, showTime );
        duration += sec_passage(prev_sec);
        prev_sec = rtc.now().second();
      }
    case 1 :
      while (duration<period) {
        if (digitalRead(modePin) == LOW) {return;}
        showTime = isDemoTime( );
        rainbowCascade_loop( 1, 8, showTime );
        duration += sec_passage(prev_sec);
        prev_sec = rtc.now().second();
      }
    case 2 :
      while (duration<period) {
        if (digitalRead(modePin) == LOW) {return;}
        showTime = isDemoTime( );
        rainbowRise_loop( 1, 8, showTime );
        duration += sec_passage(prev_sec);
        prev_sec = rtc.now().second();
      }
    case 3 :
      while (duration<period) {
        if (digitalRead(modePin) == LOW) {return;}
        showTime = isDemoTime( );
        rainbowBreathe( 1, 8, true, showTime );
        duration += sec_passage(prev_sec);
        prev_sec = rtc.now().second();
      }
    case 4 :
      while (duration<period) {
        if (digitalRead(modePin) == LOW) {return;}
        showTime = isDemoTime( );
        rainbowFlash( 4, showTime );
        duration += sec_passage(prev_sec);
        prev_sec = rtc.now().second();
      }
  }
}
