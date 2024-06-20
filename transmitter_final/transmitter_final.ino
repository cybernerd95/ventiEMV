const int pulsePin = A0;       // Analog input pin for pulse sensor
int threshold = 512;           // Threshold value for detecting peaks
unsigned long lastBeatTime = 0; // Time of the last detected beat
int beatInterval = 0;          // Time interval between beats
int bpm = 0;                   // Beats Per Minute
int sampleWindow = 2000;       // Sample window for calculating BPM (2 seconds)
#include <VirtualWire.h>
void setup() {
  Serial.begin(9600);          // Initialize serial communication for debugging
  pinMode(pulsePin, INPUT);    // Set pulse sensor pin as input
  vw_set_tx_pin(12);  // Set the transmit pin to D12
  vw_setup(2000);     // Bits per second
}

void loop() {
  static unsigned long lastTime = 0;
  static int peakCount = 0;
  
  // Read raw data from the pulse sensor
  int signal = analogRead(pulsePin);

  // Check if the signal is above the threshold
  if (signal > threshold) {
    unsigned long currentTime = millis();

    // Check if enough time has passed since the last detected beat
    if (currentTime - lastBeatTime > 250) { // 250 ms debounce time to avoid noise
      lastBeatTime = currentTime;
      peakCount++;

      // Calculate BPM if enough time has passed in the sample window
      if (currentTime - lastTime >= sampleWindow) {
        bpm = (peakCount * 60 * 1000L) / (currentTime - lastTime);
        lastTime = currentTime;
        peakCount = 0;

        // Print the BPM value to the Serial Monitor for debugging
        Serial.print("BPM: ");
        Serial.println(2*bpm);
      }
    }
  const int num = 2*bpm;
  vw_send((uint8_t *)&num, sizeof(num));
  vw_wait_tx(); // Wait until the message is sent
  delay(1000);
  }

  delay(1000);  // Short delay to avoid excessive processing
}
