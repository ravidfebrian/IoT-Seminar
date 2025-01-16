#define RAIN_DIGITAL_PIN D1 // Digital pin for rain detection (SCL on board)
#define RAIN_ANALOG_PIN A0  // Analog pin for moisture level

void setup() {
  Serial.begin(115200);
  pinMode(RAIN_DIGITAL_PIN, INPUT);
}

void loop() {
  // Read digital value for rain detection
  int rainDetected = digitalRead(RAIN_DIGITAL_PIN);

  // Read analog value for moisture level (0-1023)
  int moistureLevel = analogRead(RAIN_ANALOG_PIN);

  // Convert analog value to voltage (0-3.3V)
  float voltage = moistureLevel * (3.3 / 1023.0);

  // Display results
  Serial.print("Rain Detected: ");
  Serial.println(rainDetected == HIGH ? "No" : "Yes");

  Serial.print("Moisture Level (Analog): ");
  Serial.print(moistureLevel);
  Serial.print(" (Voltage: ");
  Serial.print(voltage);
  Serial.println(" V)");

  delay(1000); // Delay 1 second
}
