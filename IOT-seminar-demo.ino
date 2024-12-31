#include <ArduinoMqttClient.h>
#include <WiFiNINA.h>
#include <DHT.h>

#define DHTTYPE DHT11
#define DHTPIN 7 

DHT dht(DHTPIN, DHTTYPE);

char ssid[] = "APA012";      
char pass[] = "425005f3e4f7"; 

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

const char broker[] = "192.168.77.18";
int        port     = 1884;
const char topic[]  = "temperature";
const char topic2[]  = "moisture";

//set interval for sending messages (milliseconds)
const long interval = 8000;
unsigned long previousMillis = 0;

int count = 0;

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // failed, retry
    Serial.print(".");
    delay(5000);
  }

  Serial.println("You're connected to the network");
  Serial.println();

  Serial.print("Attempting to connect to the MQTT broker: ");
  Serial.println(broker);

  if (!mqttClient.connect(broker, port)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());

    while (1);
  }

  Serial.println("You're connected to the MQTT broker!");
  Serial.println();

  dht.begin();
}

void loop() {
  // call poll() regularly to allow the library to send MQTT keep alive which
  // avoids being disconnected by the broker
  mqttClient.poll();

  unsigned long currentMillis = millis();

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

   float hic = dht.computeHeatIndex(temperature, humidity, false);

  if (currentMillis - previousMillis >= interval) {
    // save the last time a message was sent
    previousMillis = currentMillis;

    Serial.print("Sending message to topic: ");
    Serial.println(topic);
    Serial.println(humidity);

    Serial.print("Sending message to topic: ");
    Serial.println(topic2);
    Serial.println(temperature);

    // send message, the Print interface can be used to set the message contents
    mqttClient.beginMessage(topic);
    mqttClient.print(humidity);
    mqttClient.endMessage();

    mqttClient.beginMessage(topic2);
    mqttClient.print(temperature);
    mqttClient.endMessage();

    Serial.println();

    delay(2000);
  }
}