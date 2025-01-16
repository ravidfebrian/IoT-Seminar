#define HEARTBEAT_PIN A0 // Analog pin for heartbeat data

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Read heartbeat data from the sensor
  int heartbeatValue = analogRead(HEARTBEAT_PIN);

  // Convert the analog value to voltage (0-3.3V)
  float voltage = heartbeatValue * (3.3 / 1023.0);

  // Output only numeric values (voltage) for Serial Plotter
  Serial.println(voltage);      // Voltage value

  delay(10); // Delay 10ms for smoother signal visualization
}
