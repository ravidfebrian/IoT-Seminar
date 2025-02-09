# Fire Sensor with LOLIN D1 Mini v4.0.0 and MQTT

This guide explains how to use a fire sensor with LOLIN D1 Mini v4.0.0 and publish its readings to an MQTT broker for integration with Home Assistant. Additionally, a buzzer will sound an alarm when fire is detected.

## Hardware Requirements
- **LOLIN D1 Mini v4.0.0**
- **Fire Sensor (KY-026 or similar)**
- **Buzzer (KY-006 or similar)**
- **Jumper Wires**
- **Raspberry Pi (for Home Assistant and MQTT broker, optional)**

## Wiring Diagram

| **Fire Sensor Pin** | **D1 Mini Pin (Based on Board)** | **D1 Mini Pin (Arduino Code)** | **Function**            |
|---------------------|----------------------------------|--------------------------------|-------------------------|
| **VCC**            | **3V3**                          | **3V3**                       | Power Supply           |
| **GND**            | **G**                            | **G**                         | Ground                 |
| **Analog Out (AO)**| **A0**                           | **A0**                        | Analog Fire Intensity  |
| **Digital Out (DO)** | **5**                          | **D5**                        | Digital Fire Detection |

| **Buzzer Pin** | **D1 Mini Pin (Based on Board)** | **D1 Mini Pin (Arduino Code)** | **Function**       |
|--------------|----------------------------------|--------------------------------|-------------------|
| **VCC**     | **3V3**                          | **3V3**                       | Power Supply     |
| **GND**     | **G**                            | **G**                         | Ground           |
| **Signal**  | **1**                            | **D1**                        | Buzzer Output    |

### Wiring Picture
![Wiring Diagram](fire_sensor_mqtt_wiring_diagram.png)

## Software Requirements
1. **Arduino IDE**
2. **Home Assistant OS** (installed on Raspberry Pi, optional)
3. **Mosquitto MQTT Broker** (integrated into Home Assistant or as an add-on)

## Functionality
- Reads **analog fire intensity** using the fire sensor.
- Reads **digital fire detection status** (`1` for fire detected, `0` for no fire).
- Controls a **buzzer** to sound an alarm when fire is detected.
- Publishes **fire detection status** to the `home/fire_sensor/digital` MQTT topic.
- Publishes **fire intensity level** to the `home/fire_sensor/analog` MQTT topic.
- Connects to Wi-Fi and an MQTT broker to send real-time updates.

## Code Breakdown

### Wi-Fi and MQTT Setup
- The D1 Mini connects to Wi-Fi using credentials (`ssid`, `password`).
- It connects to an MQTT broker (`mqtt_server`, `mqtt_port`).
- Topics:
  - `home/fire_sensor/digital`: Publishes `1` when fire is detected and `0` when there is no fire.
  - `home/fire_sensor/analog`: Publishes the **fire intensity level** (`0% - 100%`).

### Sensor Readings & Buzzer Control
- The **analog value** from the fire sensor is read using `analogRead(A0)` and converted into a fire intensity percentage.
- A **threshold** (`fireThreshold = 500`) determines whether fire is detected.
- If fire is detected, the **buzzer** is activated using PWM (`D1`).
- If no fire is detected, the buzzer is turned off.

### MQTT Publishing
- The sensor data is published every second (`delay(1000)`).
- The values are sent as strings to MQTT topics.
- Debugging logs are printed in the Serial Monitor.

## Steps to Configure Home Assistant

### Step 1: Install and Configure MQTT Broker
1. Go to Home Assistant’s **Settings > Add-ons > Add-on Store**.
2. Search for and install the **Mosquitto MQTT broker**.
3. Start the add-on and enable **Start on boot**.
4. Note the MQTT broker details (IP address of the Raspberry Pi, port 1883).

### Step 2: Configure MQTT in Home Assistant
1. Add the following MQTT configuration to your `configuration.yaml` file:

```yaml
mqtt:
  sensor:
    - name: "Fire Detection"
      state_topic: "home/fire_sensor/digital"
      payload_on: "1"
      payload_off: "0"

    - name: "Fire Intensity"
      state_topic: "home/fire_sensor/analog"
      unit_of_measurement: "%"
```

2. Restart Home Assistant to apply the changes.

### Step 3: Add Entities to the Dashboard
1. Go to the **Overview** page in Home Assistant.
2. Click **Edit Dashboard > Add Card > Entities**.
3. Add the **Fire Detection** sensor and **Fire Intensity** sensor to the dashboard.

## Testing the System
1. Open the Home Assistant dashboard on your laptop by navigating to `http://homeassistant.local:8123`.
2. Observe real-time changes in **fire intensity level**.
3. Check if the **fire detection** sensor toggles on/off correctly when exposed to flame or heat.
4. Verify that the **buzzer sounds an alarm** when fire is detected.

## Troubleshooting
- **No response from the sensor:**
  - Verify wiring and connections.
  - Ensure the MQTT broker is running.

- **Buzzer not sounding:**
  - Check that the `buzzerFrequency` value is within the buzzer’s supported range.
  - Ensure the fire sensor is detecting fire correctly.

## Additional Notes
- The **fire sensor** detects infrared radiation and should be placed in an area where flames or heat sources can be detected.
- Adjust the **fireThreshold** value in the code for sensitivity tuning.
- The buzzer should be positioned away from sensitive components to prevent interference.

## License
This project is licensed under the MIT License.
