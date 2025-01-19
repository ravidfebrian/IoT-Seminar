# IoT-Seminar

## Home Assistant

### Home Assistant installation
**Requirements:**
- Raspberry Pi 4
- min. 8GB micro SD Card

**Installation:**
1. Download [Raspberry Pi Imager](https://www.raspberrypi.com/software/).
2. Choose the your Raspberry Pi Device and choose `Operating System -> Other specific-purpose OS -> Home Assistant and Home Automation -> Home Assistant -> Home Assistant OS 14.1`.   
![image](https://github.com/user-attachments/assets/6e625f45-b186-4a00-a16a-40fd9f2efff0)
3. After it is finished you can place the SD card into the Raspberry Pi and boot it up.
4. You can access the Home Assistant dashboard by typing in `http://homeassistant.local:8123` in your web browser. If you know the IP address, you can also access it with `http://YOUR_HA_IP:8123`.
![image](https://github.com/user-attachments/assets/3d479bb3-97cf-4f1f-8205-e0bf9e3926fa)

  

### Restore Home Assistant Backup
There are two ways to restore Home Assistant backup. The first one is by doing it from the beggining where the Home Assistant just installed. The second one is after you create an account. You can choose whatever needed.
#### First option:
1. Here you can create a new account or restore it directly from the backup file.
2. If you choose restore backup, chose the backup file that you downloaded from this repo and choose `Full backup` to restore.
![image](https://github.com/user-attachments/assets/b8f18bb2-1ac8-40c1-997f-570d4bf63156)
3. After it is succesfully restored, change the IP address and the Hostname of the device in `Settings -> System -> Network`. If you **cannot access** the device, type in `http://mxr-lab-1.local:8123` in your web browser.


#### Second option:
1. Download the Home Assistant backup file from this repo.
2. In Home Assistant Dashboard, go to `Settings -> System -> Backups`. Here, click on the three dots icon at the upper right side and click on `Upload backup`. 
  ![image](https://github.com/user-attachments/assets/5a9defa1-7e33-49e7-9f1b-3541d9b7df43)
  ![image](https://github.com/user-attachments/assets/356f7584-7028-4edf-b78d-8093b6d5ffcd)
3. Choose the file that you are downloaded from this repo. Choose Full backup and Restore.
   ![image](https://github.com/user-attachments/assets/53be26a2-6ce4-4513-a2f5-c43d37a7e5a8)
4. After it is succesfully restored, change the IP address and the Hostname of the device in `Settings -> System -> Network`. If you **cannot access** the device, type in `http://mxr-lab-1.local:8123` in your web browser.

## Credentials:
Username: gemit
Pass: gemit1212

## Arduino

### Explanation of Arduino Code
The provided Arduino code demonstrates how to integrate a DHT11 sensor with MQTT to publish temperature and humidity data to an MQTT broker.

#### Key Components of the Code
1. **DHT11 Sensor Setup:**
   - The DHT11 sensor is connected to pin `7` of the Arduino.
   - The library `DHT.h` is used to interface with the sensor, enabling the code to read temperature and humidity values.

2. **Wi-Fi Connectivity:**
   - The `WiFiNINA` library establishes a connection to a specified Wi-Fi network.
   - `WiFi.begin(ssid, pass)` attempts to connect to the given SSID and password.
   - If the connection fails, it retries every 5 seconds until successful.

3. **MQTT Client Setup:**
   - The `ArduinoMqttClient` library is used to connect to an MQTT broker.
   - `mqttClient.connect(broker, port)` establishes the connection to the broker at the given IP and port.
   - Topics `temperature` and `moisture` are predefined for publishing temperature and humidity data, respectively.

4. **Data Collection and Publishing:**
   - The `dht.readTemperature()` and `dht.readHumidity()` methods retrieve temperature and humidity data from the sensor.
   - Heat index is optionally calculated using `dht.computeHeatIndex()`.
   - Data is published to the MQTT broker every 8 seconds (controlled by a timer using `millis()` and `interval`).

5. **Serial Monitor Feedback:**
   - The code outputs debug and status messages to the Serial Monitor at `9600` baud.
   - This includes connection status, MQTT broker status, and published data values.

#### Workflow
1. **Setup Phase:**
   - The Arduino initializes the Serial Monitor, Wi-Fi connection, MQTT client, and DHT sensor.
   - Any connection failures (Wi-Fi or MQTT) result in retry loops until successful.

2. **Loop Phase:**
   - The loop continuously polls the MQTT client to keep the connection alive (`mqttClient.poll()`).
   - Every 8 seconds, temperature and humidity data is read from the DHT11 sensor and published to the MQTT broker.
   - Debug information is printed to the Serial Monitor for troubleshooting and verification.

#### How to Test the Code
1. **Setup:**
   - Connect the DHT11 sensor to the Arduino as follows:
     - `VCC` to `5V`
     - `GND` to `GND`
     - `OUT` to pin `7`
   - Replace `WIFI_NAME` and `WIFI_PASS` with your Wi-Fi credentials.
   - Replace `MQTT_BROKER_IP` and `MQTT_BROKER_PORT` with your broker's details.

2. **Run the Code:**
   - Upload the code to your Arduino.
   - Open the Serial Monitor to view debug information.

3. **Verify Data:**
   - Check the MQTT broker for incoming messages on the `temperature` and `moisture` topics.
   - Ensure the data corresponds to the current temperature and humidity values.

#### Troubleshooting
- **Wi-Fi Connection Fails:**
  - Verify SSID and password.
  - Ensure the Wi-Fi signal strength is adequate.

- **MQTT Connection Fails:**
  - Check broker IP and port.
  - Ensure the broker is running and accessible from the network.

- **Incorrect Sensor Readings:**
  - Ensure the DHT11 sensor is connected correctly.
  - Replace the sensor if the issue persists.
