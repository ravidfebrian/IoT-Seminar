#define FLAME_DIGITAL_PIN D4 // Digital pin for flame detection
#define FLAME_ANALOG_PIN A0  // Analog pin for flame intensity

void setup() {
  Serial.begin(115200);
  pinMode(FLAME_DIGITAL_PIN, INPUT);
}

void loop() {
  // Read digital value for flame detection
  int flameDetected = digitalRead(FLAME_DIGITAL_PIN);

  // Read analog value for flame intensity (0-1023)
  int flameIntensity = analogRead(FLAME_ANALOG_PIN);

  // Display results
  Serial.print("Flame Detected: ");
  Serial.println(flameDetected == HIGH ? "No" : "Yes");

  Serial.print("Flame Intensity (Analog): ");
  Serial.println(flameIntensity);

  delay(500); // Delay 500ms for smoother readings
}
