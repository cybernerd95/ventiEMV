// Define variables
unsigned long lastPeakTime = 0;
int peakThreshold = 512; // Adjust this threshold according to your sensor's output range
int heartRate = 0;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read analog voltage from pulse sensor
  int sensorValue = analogRead(A0); // Assuming pulse sensor is connected to analog pin A0
  
  // Check if a peak is detected
  if (sensorValue > peakThreshold && millis() - lastPeakTime > 300) {
    // Calculate time interval since last peak
    unsigned long timeSinceLastPeak = millis() - lastPeakTime;
    
    // Calculate heart rate
    heartRate = 60000 / timeSinceLastPeak;
    
    // Update last peak time
    lastPeakTime = millis();
    
    // Print heart rate to Serial Monitor
    //Serial.print("Heart Rate (BPM): ");
    Serial.println(heartRate);

  }
}
