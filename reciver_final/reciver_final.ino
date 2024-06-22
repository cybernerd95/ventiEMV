#include <VirtualWire.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#define OLED_WIDTH 128
#define OLED_HEIGHT 64

#define OLED_ADDR 0x3C
Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT);

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  vw_set_rx_pin(11);  // Set the receive pin to D11
  vw_setup(2000);     // Bits per second
  vw_rx_start();      // Start the receiver
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) {
    int received_integer;
    if (buflen == sizeof(received_integer)) {
      // Copy the received bytes into the integer variable
      memcpy(&received_integer, buf, sizeof(received_integer));
      
      // Process the received integer (for example, print it)
      Serial.print("Received BPM: ");
      Serial.println(received_integer);
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(0, 0);
      display.println(received_integer);
      display.display();
      if(received_integer < 58){
        display.clearDisplay(); 
        display.setTextColor(WHITE);
        display.setTextSize(2);        
        display.setCursor(0, 0);
        display.println(received_integer);
        display.setTextSize(1);
        display.setCursor(0, 30);
        display.println("Patient heart is falling");
        display.display();
        delay(1000);
      }
    } else {
      Serial.println("Received message length does not match expected integer size");
    }
    
  
  }
  
}
