#include <WiFi.h>
#include <PubSubClient.h>
#define BUZZER_PIN D2 // Pin connected to the buzzer

const char* ssid = "WIFI_SSID";        // Replace with your Wi-Fi SSID
const char* password = "WIFI_PASSWORD"; // Replace with your Wi-Fi password
const char* mqtt_server = "RASPBERRY_PI_IP"; // Replace with your Raspberry Pi IP address

WiFiClient espClient;
PubSubClient client(espClient);

bool buzzerState = false;
int buzzerFrequency = 1000; // Default frequency in Hz

void callback(char* topic, byte* payload, unsigned int length) {
  String message;
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  if (String(topic) == "home/buzzer/control") {
    if (message == "on") {
      buzzerState = true;
    } else if (message == "off") {
      buzzerState = false;
      noTone(BUZZER_PIN);
    }
  } else if (String(topic) == "home/buzzer/frequency") {
    buzzerFrequency = message.toInt();
  }
}

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");

  // Connect to MQTT broker
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  while (!client.connected()) {
    if (client.connect("D1MiniBuzzer")) {
      Serial.println("MQTT connected");
      client.subscribe("home/buzzer/control");
      client.subscribe("home/buzzer/frequency");
    } else {
      delay(5000);
    }
  }
}

void loop() {
  client.loop();

  if (buzzerState) {
    tone(BUZZER_PIN, buzzerFrequency);
  }
}
