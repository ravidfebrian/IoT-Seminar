#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// WiFi and MQTT Configuration
const char* ssid = "gemit_1";        // Replace with your WiFi SSID
const char* password = "codingschool24";        // Replace with your WiFi password
const char* mqtt_server = "192.168.68.63"; // Replace with your MQTT broker IP
const int mqtt_port = 1883;               // Default MQTT port
const char* mqtt_user = "gemit";          // MQTT username (if required)
const char* mqtt_password = "gemit1212";  // MQTT password (if required)

// MQTT Topics
const char* ldr_topic = "home/ldr_sensor/digital";
const char* brightness_topic = "home/ldr_sensor/analog";

// Pins
#define LDR_ANALOG_PIN A0    // Analog pin for the LDR sensor
#define DIGITAL_OUTPUT_PIN D1 // Digital output for light detection
#define PWM_OUTPUT_PIN D2     // PWM output for LED brightness

// WiFi and MQTT clients
WiFiClient espClient;
PubSubClient client(espClient);

// Threshold for light detection (adjust as needed)
const int lightThreshold = 50;

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
    if (client.connect("LightSensorClient", mqtt_user, mqtt_password)) {
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
  pinMode(DIGITAL_OUTPUT_PIN, OUTPUT);
  pinMode(PWM_OUTPUT_PIN, OUTPUT);

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

  // Read the analog value from the LDR sensor
  int brightnessLevel = (analogRead(LDR_ANALOG_PIN))*100/1024;

  // Map the brightness level to PWM range (0-1023)
  int pwmValue = map(brightnessLevel, 0, 100, 0, 255);

  // Adjust LED brightness using PWM
  analogWrite(PWM_OUTPUT_PIN, pwmValue);

  // Determine if light is detected based on the threshold
  bool lightDetected = brightnessLevel > lightThreshold;
  digitalWrite(DIGITAL_OUTPUT_PIN, lightDetected ? LOW : HIGH);

  // Publish digital and analog values to MQTT topics
  String digitalPayload = lightDetected ? "0" : "1";
  String analogPayload = String(brightnessLevel);

  if (client.publish(ldr_topic, digitalPayload.c_str())) {
    Serial.println("Light detection value sent to MQTT broker.");
  } else {
    Serial.println("Failed to send light detection value.");
  }

  if (client.publish(brightness_topic, analogPayload.c_str())) {
    Serial.println("Brightness level value sent to MQTT broker.");
  } else {
    Serial.println("Failed to send brightness level value.");
  }

  // Debugging output
  Serial.print("Brightness Level: ");
  Serial.print(brightnessLevel);
  Serial.println("%");
  Serial.print("PWM Value: ");
  Serial.println(pwmValue);
  Serial.print("Light Detected: ");
  Serial.println(lightDetected ? "No" : "Yes");

  delay(1000); // Delay 1 second
}
