# Controlling a Buzzer with LOLIN D1 Mini v4.0.0 and Home Assistant via MQTT

This guide explains how to control a buzzer connected to a LOLIN D1 Mini v4.0.0 using Home Assistant's dashboard via MQTT. The setup allows you to send `on`/`off` commands and control the buzzer's tone frequency using a slider or text input.

## Hardware Requirements
- **LOLIN D1 Mini v4.0.0**
- **KY-006 Piezo Buzzer Module**
- **Raspberry Pi (e.g., Raspberry Pi 4)** running Home Assistant
- **Jumper Wires**

## Wiring Diagram

| **KY-006 Pin** | **D1 Mini Pin (Based on Board)** | **D1 Mini Pin (Arduino Code)** | **Function**        |
|----------------|-----------------------------------|--------------------------------|---------------------|
| **VCC**        | **3V3**                          | **3V3**                       | Power Supply        |
| **GND**        | **GND**                            | **G**                         | Ground              |
| **Signal**     | **2**                            | **D2**                        | Signal Input        |

### Wiring Picture
![Wiring Diagram](mqtt_buzzer_wiring_diagram.png)

## Software Requirements
1. **Arduino IDE**
2. **Home Assistant OS** (installed on Raspberry Pi)
3. **Mosquitto MQTT Broker** (integrated into Home Assistant or as an add-on)

## Code Example
This code allows the D1 Mini to receive `on`/`off` commands and frequency values from Home Assistant via MQTT to control the buzzer.

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
  switch:
    - name: "Buzzer Control"
      state_topic: "home/buzzer/control"
      command_topic: "home/buzzer/control"
      payload_on: "on"
      payload_off: "off"

  number:
    - name: "Buzzer Frequency"
      state_topic: "home/buzzer/frequency"
      command_topic: "home/buzzer/frequency"
      min: 100
      max: 5000
      step: 100
```

2. Restart Home Assistant to apply the changes.

### Step 3: Add Entities to the Dashboard
1. Go to the **Overview** page in Home Assistant.
2. Click **Edit Dashboard > Add Card > Entities**.
3. Add the **Buzzer Control** switch and **Buzzer Frequency** slider.

## Testing the System
1. Open the Home Assistant dashboard on your laptop by navigating to `http://homeassistant.local:8123`.
2. Toggle the **Buzzer Control** switch:
   - Turn it `on` to activate the buzzer.
   - Turn it `off` to deactivate the buzzer.
3. Adjust the **Buzzer Frequency** slider to change the tone frequency of the buzzer in real-time.

## Troubleshooting
- **No response from the buzzer:**
  - Verify the D1 Mini is connected to the same Wi-Fi network as the Raspberry Pi.
  - Check the MQTT broker configuration.

- **Incorrect tones:**
  - Ensure the frequency slider values are within the buzzer’s supported range (typically 1 kHz to 5 kHz).

## Additional Notes
- Ensure the KY-006 module is properly connected and powered.
- Use the buzzer in a well-ventilated area to avoid overheating.

## License
This project is licensed under the MIT License.

