# Flame Sensor KY-026 with LOLIN D1 Mini v4.0.0 and Home Assistant on Raspberry Pi

This guide explains how to use the KY-026 flame sensor with LOLIN D1 Mini v4.0.0 to send flame detection data to Home Assistant hosted on a Raspberry Pi. The Raspberry Pi acts as a headless server (without a monitor) and is accessed from a laptop.

## Hardware Requirements
- **LOLIN D1 Mini v4.0.0**
- **KY-026 Flame Sensor**
- **Raspberry Pi (e.g., Raspberry Pi 4)**
- **Laptop or Desktop Computer**
- **Micro SD Card (8GB or higher)**
- **Jumper Wires**

## Software Requirements
- **Arduino IDE**
- **Home Assistant OS** (installed on Raspberry Pi)
- **MQTT Broker** (integrated into Home Assistant or an external broker)

## Wiring Diagram

| **KY-026 Pin** | **D1 Mini Pin (Based on Board)** | **D1 Mini Pin (Arduino Code)** | **Function**             |
|----------------|-----------------------------------|--------------------------------|--------------------------|
| **VCC**        | **3V3**                          | **3V3**                       | Power Supply             |
| **GND**        | **G**                            | **G**                         | Ground                   |
| **DO**         | **2**                            | **D2**                        | Digital Output (Flame Detection) |
| **AO**         | **A0**                           | **A0**                        | Analog Output (Flame Intensity)  |

### Wiring Picture
![Wiring Diagram](flame_sensor_home_assistant_wiring_diagram.png)

## Steps to Set Up the System

### Step 1: Configure the Raspberry Pi with Home Assistant
1. Install Home Assistant OS on the Raspberry Pi:
   - Download the Raspberry Pi Imager from [Raspberry Pi’s website](https://www.raspberrypi.com/software/).
   - Select **Home Assistant OS** as the operating system.
   - Write the image to the micro SD card and insert it into the Raspberry Pi.
2. Power up the Raspberry Pi and connect it to the same network as your laptop.
3. Access the Home Assistant web interface from your laptop by typing `http://homeassistant.local:8123` in your browser.

### Step 2: Install and Configure the MQTT Broker
1. Go to Home Assistant’s **Settings > Add-ons > Add-on Store**.
2. Search for and install the **Mosquitto MQTT broker**.
3. Start the add-on and enable **Start on boot**.
4. Note the MQTT broker details (IP address of the Raspberry Pi, port 1883).

### Step 3: Program the D1 Mini
Use code Example for the Flame Sensor with MQTT


### Step 4: Configure Home Assistant
1. Add the MQTT integration:
   - Go to **Settings > Devices & Services > Add Integration**.
   - Search for and add **MQTT**.
   - Configure it to use the Raspberry Pi’s MQTT broker.
2. Create sensors for flame detection and intensity:
   ```yaml
   mqtt:
     sensor:
       - name: "Flame Detection"
         state_topic: "home/flame/detection"
       - name: "Flame Intensity"
         state_topic: "home/flame/intensity"
   ```
3. Restart Home Assistant.

### Step 5: View Data on Laptop
1. Open Home Assistant’s web interface on your laptop by typing `http://homeassistant.local:8123`.
2. Add the sensors to a dashboard to monitor flame detection and intensity values.

## Testing the System
1. Place the KY-026 sensor in a location to monitor for flames.
2. Use a lighter or match to test flame detection.
   - Check the flame detection sensor status on the Home Assistant dashboard.
   - Observe the flame intensity readings changing in real-time.

## Troubleshooting
- **No data in Home Assistant:**
  - Verify the D1 Mini is connected to the same Wi-Fi network.
  - Check the MQTT broker configuration in Home Assistant.
- **Incorrect readings:**
  - Ensure the KY-026 sensor is properly connected.
  - Adjust the potentiometer on the sensor to calibrate sensitivity.

## Additional Notes
- Ensure fire safety precautions when testing the flame sensor.
- The KY-026 module includes an onboard LED to indicate flame detection.
- Use the D1 Mini and Raspberry Pi in a well-ventilated area.

## License
This project is licensed under the MIT License.

