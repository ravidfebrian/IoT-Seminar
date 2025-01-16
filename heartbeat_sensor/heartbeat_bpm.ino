#define HEARTBEAT_PIN A0

unsigned long previousTime = 0;
int peakCount = 0;
float bpm = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int heartbeatValue = analogRead(HEARTBEAT_PIN);

  // Detect peaks (simple threshold-based detection)
  if (heartbeatValue > 600) { // Adjust threshold based on your signal
    if (millis() - previousTime > 300) { // Minimum delay between beats
      peakCount++;
      previousTime = millis();
    }
  }

  // Calculate BPM every 10 seconds
  if (millis() % 10000 < 50) { // Check every 10 seconds
    bpm = peakCount * 6; // Convert to BPM
    Serial.print("Heartbeat BPM: ");
    Serial.println(bpm);
    peakCount = 0; // Reset peak count
  }

  delay(10);
}
