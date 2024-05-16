#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library.   

//  Variables
const int PulseWire = 0;
//const int LED = LED_BUILTIN;          
int Threshold = 550;           

PulseSensorPlayground pulseSensor;


void setup() {   

  Serial.begin(9600);


  pulseSensor.analogInput(PulseWire);   
  //pulseSensor.blinkOnPulse(LED);
  pulseSensor.setThreshold(Threshold);   


   if (pulseSensor.begin()) {
    Serial.println("Pulse sensor working !");  
  }
}



void loop() {

 

//if (pulseSensor.sawStartOfBeat()) {           
int myBPM = pulseSensor.getBeatsPerMinute();  

 Serial.println("Heart beat detected "); 
 Serial.print("BPM: ");                        
 Serial.println(myBPM);                       


  delay(2000);                  

}

  
