#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// WiFi and MQTT Configuration
//const char* ssid = "TP-Link_A1D3";        // Replace with your WiFi SSID
//const char* password = "91648600";        // Replace with your WiFi password
//const char* mqtt_server = "10.168.73.196"; // Replace with your MQTT broker IP
const char* ssid = "gemit_1";        // Replace with your WiFi SSID
const char* password = "codingschool24";        // Replace with your WiFi password
const char* mqtt_server = "192.168.68.63"; // Replace with your MQTT broker IP

const int mqtt_port = 1883;               // Default MQTT port
const char* mqtt_user = "gemit";          // MQTT username (if required)
const char* mqtt_password = "gemit1212";  // MQTT password (if required)

// MQTT Topics
const char* fire_digital_topic = "home/fire_sensor/digital";
const char* fire_analog_topic = "home/fire_sensor/analog";

// Pins
#define FIRE_ANALOG_PIN A0    // Analog pin for the fire sensor
#define FIRE_DIGITAL_PIN D5   // Digital pin for fire detection
#define BUZZER_PWM_PIN D1     // PWM output for buzzer

// WiFi and MQTT clients
WiFiClient espClient;
PubSubClient client(espClient);

// Threshold for fire detection (adjust as needed)
const int fireThreshold = 500;

// Buzzer tone frequency (adjust as needed)
const int buzzerFrequency = 250; // 2 kHz tone

// Connect to WiFi
void setup_wifi() {
  delay(10);
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
}

// Reconnect to MQTT broker
void reconnect() {
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");
    if (client.connect("FireSensorClient", mqtt_user, mqtt_password)) {
      Serial.println("Connected to MQTT broker!");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" trying again in 5 seconds...");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  // Set up pins
  pinMode(FIRE_DIGITAL_PIN, INPUT);
  pinMode(BUZZER_PWM_PIN, OUTPUT);

  // Connect to WiFi
  setup_wifi();

  // Set up MQTT client
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  // Ensure MQTT connection
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Read the analog value from the fire sensor
  int fireLevel = (analogRead(FIRE_ANALOG_PIN))*100/1024;

  // Determine if fire is detected based on the digital input
  bool fireDetected = digitalRead(FIRE_DIGITAL_PIN) == HIGH;

  // Control buzzer based on fire detection
  if (fireDetected) {
    analogWriteFreq(buzzerFrequency); // Set frequency for the buzzer
    analogWrite(BUZZER_PWM_PIN, 255); // Set duty cycle (50% for audible tone)
  } else {
    analogWrite(BUZZER_PWM_PIN, 0);   // Turn off the buzzer
  }

  // Publish digital and analog values to MQTT topics
  String digitalPayload = fireDetected ? "1" : "0";
  String analogPayload = String(fireLevel);

  if (client.publish(fire_digital_topic, digitalPayload.c_str())) {
    Serial.println("Fire detection value sent to MQTT broker.");
  } else {
    Serial.println("Failed to send fire detection value.");
  }

  if (client.publish(fire_analog_topic, analogPayload.c_str())) {
    Serial.println("Fire level value sent to MQTT broker.");
  } else {
    Serial.println("Failed to send fire level value.");
  }

  // Debugging output
  Serial.print("Fire Level (Analog): ");
  Serial.print(fireLevel);
  Serial.println("%");
  Serial.print("Fire Detected: ");
  Serial.println(fireDetected ? "Yes" : "No");

  delay(1000); // Delay 1 second
}

