




uint16_t led_num( int col, int row ) {
  if      (row>6)            {return strip.numPixels();}
  else if (row<0)            {return strip.numPixels();}
  else if (col<4 && row==6)  {return strip.numPixels();}
  else if (col<3 && row==5)  {return strip.numPixels();}
  else if (col<2 && row==4)  {return strip.numPixels();}
  else if (col>17 && row==0) {return strip.numPixels();}
  else if (col>18 && row==1) {return strip.numPixels();}
  else if (col>19 && row==2) {return strip.numPixels();}
  return col + R[row];
}


void showNumber(int num, int col, uint32_t color) {
  // col is column of bottom left pixel
  //uint32_t color = strip.Color(255, 255, 255);
  if (num==0){
    for(int i=0;i<4;i++) {
      strip.setPixelColor(led_num(col+i,i+2),color);
      strip.setPixelColor(led_num(col+i+1,i+1),color);
    }
    strip.setPixelColor(led_num(col,1),color);
    strip.setPixelColor(led_num(col+4,5),color);
  }
  else if (num==1) {
    for(int i=0;i<5;i++) {
      strip.setPixelColor(led_num(col+i,i+1),color);
    }
  }
  else if (num==2) {
    strip.setPixelColor(led_num(col,1),color);
    strip.setPixelColor(led_num(col+1,1),color);
    strip.setPixelColor(led_num(col+1,2),color);
    strip.setPixelColor(led_num(col+2,3),color);
    strip.setPixelColor(led_num(col+3,3),color);
    strip.setPixelColor(led_num(col+4,4),color);
    strip.setPixelColor(led_num(col+5,5),color);
    strip.setPixelColor(led_num(col+4,5),color);
  }
  else if (num==3) {
    showNumber(1, col+1, color);
    strip.setPixelColor(led_num(col,1),color);
    strip.setPixelColor(led_num(col+2,3),color);
    strip.setPixelColor(led_num(col+4,5),color);
  }
  else if (num==4) {
    showNumber(1, col, color);
    strip.setPixelColor(led_num(col,3),color);
    strip.setPixelColor(led_num(col+1,3),color);
    strip.setPixelColor(led_num(col+1,4),color);
    strip.setPixelColor(led_num(col+2,5),color);
  }
  else if (num==5) {
    strip.setPixelColor(led_num(col,1),color);
    strip.setPixelColor(led_num(col+1,1),color);
    strip.setPixelColor(led_num(col+2,2),color);
    strip.setPixelColor(led_num(col+2,3),color);
    strip.setPixelColor(led_num(col+3,3),color);
    strip.setPixelColor(led_num(col+3,4),color);
    strip.setPixelColor(led_num(col+5,5),color);
    strip.setPixelColor(led_num(col+4,5),color);
  }
  else if (num==6) {
    for(int i=0;i<4;i++) {
      strip.setPixelColor(led_num(col+i,i+2),color);
    }
    strip.setPixelColor(led_num(col,1),color);
    strip.setPixelColor(led_num(col+1,1),color);
    strip.setPixelColor(led_num(col+2,2),color);
    strip.setPixelColor(led_num(col+2,3),color);
  }
  else if (num==7) {
    showNumber(1, col, color);
    strip.setPixelColor(led_num(col+2,5),color);
    strip.setPixelColor(led_num(col+3,5),color);
  }
  else if (num==8) {
    showNumber(0, col, color);
    strip.setPixelColor(led_num(col+2,3),color);
  }
  else if (num==9) {
    for(int i=0;i<4;i++) {
      strip.setPixelColor(led_num(col+i,i+1),color);
    }
    strip.setPixelColor(led_num(col+1,3),color);
    strip.setPixelColor(led_num(col+1,4),color);
    strip.setPixelColor(led_num(col+2,5),color);
    strip.setPixelColor(led_num(col+3,5),color);
  }
  else if (num==-1) {
    strip.setPixelColor(led_num(col,2),color);
    strip.setPixelColor(led_num(col+2,4),color);
  }
}



void allNumbers(int hr1, int hr2, int mn1, int mn2, bool colon, uint32_t color) {

  if (mn1==0 && mn2==7) {v[mn2]=1;}
  else if (mn2==7) {v[mn2]=2;}
  
  if (hr1==0) {
//    int wSum1 = w[hr2] + w[10] + v[10]
//    int wSum2 = w[mn1] + v[mn1] + w[mn2] + v[mn2];
//    int width = wSum1 + wSum2 + 1;
//    int bdry  = 18 - width;
//    if (bdry%2==0) {int col = bdry/2 + wSum1;}
//    else {int col = 
    showNumber(hr2, 8 - w[hr2] - v[10], color);
    showNumber(-1, 8, color);
    showNumber(mn1, 8 + w[10] + v[mn1], color);
    showNumber(mn2, 8 + w[10] + w[mn1] + v[mn1] + v[mn2], color);
  }
  else { // if (hr1==1) {
    //int wSum = w[hr1] + w[hr2] + w[10] + w[mn1] + w[mn2];
    showNumber(hr1, 9 - w[hr2] - w[hr1] - v[10] - v[hr2], color);
    showNumber(hr2, 9 - w[hr2] - v[10], color);
    showNumber(-1, 9, color);
    showNumber(mn1, 9 + w[10] + v[mn1], color);
    showNumber(mn2, 9 + w[10] + w[mn1] + v[mn1] + v[mn2], color);
  }
//  else if (hr1==2) {
//    
//  }
}


void showClock( bool t_mil, uint32_t color ) {
  uint8_t hr1, hr2, mn1, mn2, now_hour;
  DateTime now = rtc.now();
  if (! t_mil && now.hour() > 12) {now_hour = now.hour() - 12;}
  else {now_hour = now.hour();}
  if (now_hour>9) {
    hr1 = floor(now_hour/10);
    hr2 = now_hour % 10;
  }
  else {hr1=0; hr2=now_hour;}
  if (now.minute()>9) {
    mn1 = floor(now.minute()/10);
    mn2 = now.minute() % 10;
  }
  else {mn1=0; mn2=now.minute();}
  allNumbers(hr1, hr2, mn1, mn2, true, color);
}
