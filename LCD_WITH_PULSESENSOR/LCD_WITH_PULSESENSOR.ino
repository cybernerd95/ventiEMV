#include <Wire.h>

#include<LCD_I2C.h>
LCD_I2C lcd(0x27,16,2);//Set the LCD address to 0x27 with the width of 16 & the height of 2

const int pulsePin = 0;  // Pulse sensor connected to analog pin 0

// Variables
int pulseValue = 0;      // Variable to store the pulse value
int threshold = 550;     // Adjust this threshold according to your sensor and environment

void setup(){
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();

}
void loop(){
  pulseValue = analogRead(pulsePin);  
  
 
    Serial.println(pulseValue);
    
  
  delay(1000);  // Delay for stability
  // lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(pulseValue);
 
}