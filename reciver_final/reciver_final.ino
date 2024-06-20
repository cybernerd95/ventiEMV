#include <VirtualWire.h>

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  vw_set_rx_pin(11);  // Set the receive pin to D11
  vw_setup(2000);     // Bits per second
  vw_rx_start();      // Start the receiver
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
    } else {
      Serial.println("Received message length does not match expected integer size");
    }
  }
}
