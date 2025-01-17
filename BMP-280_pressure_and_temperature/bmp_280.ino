#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define BMP_SCL_PIN D1 // I2C Clock
#define BMP_SDA_PIN D2 // I2C Data

Adafruit_BMP280 bmp; // Create an instance of the BMP280 sensor

void setup() {
  Serial.begin(115200);

  if (!bmp.begin(0x76)) { // Initialize the sensor with I2C address 0x76
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }

  Serial.println("BMP280 Sensor Ready");
}

void loop() {
  // Read temperature and pressure values
  float temperature = bmp.readTemperature();
  float pressure = bmp.readPressure() / 100.0F; // Convert pressure to hPa

  // Display the readings on the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");

  delay(1000); // Delay 1 second between readings
}
