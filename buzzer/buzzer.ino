#define BUZZER_PIN D2 // Pin connected to the buzzer

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Play a tone for 1 second
  tone(BUZZER_PIN, 1000); // Play a 1 kHz tone
  delay(1000); // Wait for 1 second

  // Turn off the buzzer for 1 second
  noTone(BUZZER_PIN);
  delay(1000); // Wait for 1 second
}
