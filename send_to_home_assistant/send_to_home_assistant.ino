#include <WiFi.h>
#include <PubSubClient.h>
#define FLAME_DIGITAL_PIN 2  // Digital pin for flame detection
#define FLAME_ANALOG_PIN A0 // Analog pin for flame intensity

const char* ssid = "WIFI_SSID";        // Replace with your Wi-Fi SSID
const char* password = "WIFI_PASSWORD"; // Replace with your Wi-Fi password
const char* mqtt_server = "RASPBERRY_PI_IP"; // Replace with your Raspberry Pi IP address

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long previousMillis = 0;
const long interval = 8000; // Send data every 8 seconds

void setup() {
  Serial.begin(115200);
  pinMode(FLAME_DIGITAL_PIN, INPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");

  // Connect to MQTT broker
  client.setServer(mqtt_server, 1883);
  while (!client.connected()) {
    if (client.connect("D1MiniFlameSensor")) {
      Serial.println("MQTT connected");
    } else {
      delay(5000);
    }
  }
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Read sensor values
    int flameDetected = digitalRead(FLAME_DIGITAL_PIN);
    int flameIntensity = analogRead(FLAME_ANALOG_PIN);

    // Publish flame detection status
    client.publish("home/flame/detection", flameDetected == HIGH ? "No" : "Yes");

    // Publish flame intensity
    char intensityStr[10];
    itoa(flameIntensity, intensityStr, 10);
    client.publish("home/flame/intensity", intensityStr);

    Serial.println("Data sent to MQTT");
  }

  client.loop();
}
