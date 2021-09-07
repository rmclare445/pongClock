// Translates column and row number into pixel number
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

// Defines number pixel patterns
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


// Determines how numbers are spced/displayed
void allNumbers(int hr1, int hr2, int mn1, int mn2, bool colon, uint32_t color) {
  uint8_t col_spot;

  if (mn1==0 && mn2==7) {v[7]=1;}
  else if (mn2==7) {v[7]=2;}

  // Necessary to ensure pretty spacing for ones (see below)
  v[1]=1;
  
  if (hr1==0) {
//    int wSum1 = w[hr2] + w[10] + v[10]
//    int wSum2 = w[mn1] + v[mn1] + w[mn2] + v[mn2];
//    int width = wSum1 + wSum2 + 1;
//    int bdry  = 18 - width;
//    if (bdry%2==0) {int col = bdry/2 + wSum1;}
//    else {int col = 
    if (mn1==4) {col_spot=7;} else {col_spot=8;}
    showNumber(mn1, col_spot + w[10] + v[mn1], color);
    // Pretty spacing for ones
    if ((mn1==0 || mn1==4) && mn2==1) {v[1]=0;}
    else {v[1]=1;}
  }
  else { // if (hr1==1) {
    if (mn1==4) {col_spot=8;} else {col_spot=9;}
    //int wSum = w[hr1] + w[hr2] + w[10] + w[mn1] + w[mn2];
    showNumber(hr1, col_spot - w[hr2] - w[hr1] - v[10] - v[hr2], color);
    showNumber(mn1, col_spot + w[10] + v[mn1], color);
    // Pretty spacing for ones
    if ((mn1==0 || mn1==4) && mn2==1) {v[1]=0;}
    else {v[1]=1;}
  }
  showNumber(hr2, col_spot - w[hr2] - v[10], color);
  if (colon) {showNumber(-1, col_spot, color);}
  showNumber(mn2, col_spot + w[10] + w[mn1] + v[mn1] + v[mn2], color);
}

// Feeds clock data into showNumber
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
  if (now.second()%2==0) {allNumbers(hr1, hr2, mn1, mn2, true, color);}
  else {allNumbers(hr1, hr2, mn1, mn2, false, color);}
  //allNumbers(0, 7, 0, 1, true, color);    // Used to test number configurations
}
