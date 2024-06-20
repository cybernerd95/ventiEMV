#include <VirtualWire.h>

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  vw_set_rx_pin(11);   // Set the receive pin to D11
  vw_setup(2000);      // Bits per second
  vw_rx_start();       // Start the receiver
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) {
    buf[buflen] = '\0'; // Null-terminate the string
    Serial.print("Received: ");
    Serial.println((int)buf);
  }

  // Optional: Add delay or other operations here
  delay(100); // Adjust delay if necessary
}