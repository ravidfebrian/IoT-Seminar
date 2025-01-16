#include <SPI.h>
#include <MFRC522.h>

// Define the GPIO pins for MFRC522
#define RST_PIN D0   // GPIO16, labeled
#define SS_PIN D8    // GPIO15, labeled

MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance

void setup() {
  Serial.begin(115200);
  while (!Serial); // Wait for serial connection

  SPI.begin();     // Initialize SPI bus
  mfrc522.PCD_Init(); // Initialize MFRC522

  Serial.println("Place an RFID tag near the reader...");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print("UID:");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();

  mfrc522.PICC_HaltA();
}
