#define BUZZER_PIN D2 // Pin connected to the buzzer

int melody[] = {
  262, 294, 330, 349, 392, 440, 494, 523 // Notes (C4 to C5)
};

int noteDurations[] = {
  500, 500, 500, 500, 500, 500, 500, 500 // Durations in milliseconds
};

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < 8; i++) {
    tone(BUZZER_PIN, melody[i]); // Play the note
    delay(noteDurations[i]); // Wait for the duration
    noTone(BUZZER_PIN); // Turn off the buzzer between notes
    delay(100); // Pause between notes
  }
  delay(2000); // Wait before replaying the melody
}
