#include <VirtualWire.h>

void setup() {
  vw_set_tx_pin(12);  // Set the transmit pin to D12
  vw_setup(2000);     // Bits per second
}

void loop() {
  const char *msg = "Hello";
  vw_send((uint8_t *)msg, strlen(msg));
  vw_wait_tx(); // Wait until the message is sent
  delay(100);
}
