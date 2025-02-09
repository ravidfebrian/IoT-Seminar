# Light Sensor (LDR) with LOLIN D1 Mini v4.0.0 and MQTT

This guide explains how to use a Light Dependent Resistor (LDR) sensor with LOLIN D1 Mini v4.0.0 and publish its readings to an MQTT broker for integration with Home Assistant.

## Hardware Requirements
- **LOLIN D1 Mini v4.0.0**
- **LDR Sensor (Light Dependent Resistor)**
- **Jumper Wires**
- **LED (for brightness control, optional)**
- **Raspberry Pi (for Home Assistant and MQTT broker, optional)**

## Wiring Diagram

| **LDR Pin**      | **D1 Mini Pin (Based on Board)** | **D1 Mini Pin (Arduino Code)** | **Function**         |
|-----------------|----------------------------------|--------------------------------|----------------------|
| **VCC**         | **3V3**                          | **3V3**                       | Power Supply        |
| **GND**         | **G**                            | **G**                         | Ground              |
| **Analog Out**  | **A0**                           | **A0**                        | Analog Input        |
| **Digital Out** | **SCL**                           | **D1**                        | Digital Output      |
| **LED Control** | **SDA**                           | **D2**                        | PWM Output (LED)    |

### Wiring Picture
![Wiring Diagram](ldr_mqtt_wiring_diagram.png)

## Software Requirements
1. **Arduino IDE**
2. **Home Assistant OS** (installed on Raspberry Pi, optional)
3. **Mosquitto MQTT Broker** (integrated into Home Assistant or as an add-on)

## Functionality
- Reads **analog light intensity** using the LDR sensor.
- Converts the brightness level into a percentage (`0% - 100%`).
- Uses a **PWM output** to control an LED brightness level based on the sensor reading.
- Publishes **digital light detection status** (`1` for dark, `0` for bright) to the `home/ldr_sensor/digital` topic via MQTT.
- Publishes **analog brightness level** (percentage) to the `home/ldr_sensor/analog` topic via MQTT.
- Connects to Wi-Fi and MQTT broker to send real-time updates.

## Code Breakdown

### Wi-Fi and MQTT Setup
- The D1 Mini connects to Wi-Fi using credentials (`ssid`, `password`).
- It connects to an MQTT broker (`mqtt_server`, `mqtt_port`).
- Topics:
  - `home/ldr_sensor/digital`: Publishes `1` when the light level is **low** and `0` when it is **bright**.
  - `home/ldr_sensor/analog`: Publishes the **brightness level in percentage** (`0% - 100%`).

### Sensor Readings & LED Control
- The **analog value** from the LDR is read using `analogRead(A0)` and converted into a brightness percentage.
- A **threshold** (`lightThreshold = 50`) determines whether the environment is bright or dark.
- If dark, the **digital output** (`D1`) is set HIGH.
- The LED brightness is adjusted using **PWM** (`D2`).

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
    - name: "Light Detection"
      state_topic: "home/ldr_sensor/digital"
      payload_on: "1"
      payload_off: "0"

    - name: "Brightness Level"
      state_topic: "home/ldr_sensor/analog"
      unit_of_measurement: "%"
```

2. Restart Home Assistant to apply the changes.

### Step 3: Add Entities to the Dashboard
1. Go to the **Overview** page in Home Assistant.
2. Click **Edit Dashboard > Add Card > Entities**.
3. Add the **Light Detection** sensor and **Brightness Level** sensor to the dashboard.

## Testing the System
1. Open the Home Assistant dashboard on your laptop by navigating to `http://homeassistant.local:8123`.
2. Observe real-time changes in **brightness level**.
3. Check if the **light detection** sensor toggles on/off correctly when exposed to different lighting conditions.
4. Verify that the **LED brightness** changes dynamically based on light intensity.

## Troubleshooting
- **No response from the sensor:**
  - Verify wiring and connections.
  - Ensure the MQTT broker is running.

- **Incorrect brightness levels:**
  - Adjust the `lightThreshold` value in the code.
  - Make sure the LDR sensor is correctly positioned.

## Additional Notes
- The **LDR sensor** detects ambient light levels and should be placed in an open area.
- Adjust the **PWM frequency** to fine-tune LED brightness control.

## License
This project is licensed under the MIT License.

