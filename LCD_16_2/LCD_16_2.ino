#include <Wire.h>
#include<LCD_I2C.h>
LCD_I2C lcd(0x27,16,2);//Set the LCD address to 0x27 with the width of 16 & the height of 2

void setup(){
  Serial.begin(9600);
  lcd.begin(true);
  lcd.backlight();
}
void loop(){
  // lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MALLADI");
  delay(1000);
}