#define MOISTURE_PIN A0 // Analog pin for soil moisture data

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Read soil moisture data from the sensor
  int moistureValue = analogRead(MOISTURE_PIN);

  // Convert the analog value to voltage (0-3.3V)
  float voltage = moistureValue * (3.3 / 1023.0);

  // Output numeric values for Serial Plotter
  Serial.println(voltage); // Voltage value for visualization

  delay(100); // Delay 100ms for smoother readings
}
