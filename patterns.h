void setAll(uint32_t color) {
  for(int c=1; c<21; c++) {
    for(int r=0; r<7; r++) {
      strip.setPixelColor(led_num(c,r),color);
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
