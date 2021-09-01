void setAll(uint32_t color) {
  for(int c=1; c<21; c++) {
    for(int r=0; r<7; r++) {
      strip.setPixelColor(led_num(c,r),color);
    }
  }
}

void shutter( uint8_t c, bool shut, uint32_t color ) {
  uint8_t r;
  for(r=0; r<7; r++) {
    if (shut) {
      strip.setPixelColor(led_num(c, r), color);
      strip.setPixelColor(led_num(21-c, r), color);
    }
    else {
      strip.setPixelColor(led_num(11-c, r), color);
      strip.setPixelColor(led_num(10+c, r), color);
    }
  }
}

void wipe( uint16_t wait, uint32_t color ) {
  int c, r;
  for(c=1; c<21; c++) {
    for(r=0; r<7; r++) {
      strip.setPixelColor(led_num(c,r), color);
    }
    strip.show();
    delay(wait);
  }
}
