#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <PulseSensorPlayground.h> 
const int PulseWire = 0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int LED = LED_BUILTIN;          // The on-board Arduino LED, close to PIN 13.
int Threshold = 550;
LiquidCrystal_I2C lcd(0x27,16,2);//Set the LCD address to 0x27 with the width of 16 & the height of 2
PulseSensorPlayground pulseSensor;

void setup(){
  Serial.begin(9600);
  lcd.begin(true);
  lcd.backlight();
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED);       //auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.setThreshold(Threshold);
  if (pulseSensor.begin()) {
    Serial.println("PULSE SENSOR WORKING");  //This prints one time at Arduino power-up,  or on Arduino reset.  
  }
}
void loop(){
  lcd.clear();
  float myBPM = pulseSensor.getBeatsPerMinute();
  lcd.print("ROHIT"); 
  Serial.println(myBPM); 
  lcd.setCursor(0,1);
  lcd.print("MALLADI");
  delay(1000);
}