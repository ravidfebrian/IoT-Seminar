# Flame Sensor KY-026 with LOLIN D1 Mini v4.0.0

This repository provides an example of how to use the KY-026 flame sensor with the LOLIN D1 Mini v4.0.0. The example demonstrates reading flame detection data via the digital and analog outputs of the sensor and displaying it in the Serial Monitor.

## Hardware Requirements
- **LOLIN D1 Mini v4.0.0**
- **KY-026 Flame Sensor**
- **Jumper Wires**

## Wiring Diagram

| **KY-026 Pin** | **D1 Mini Pin (Based on Board)** | **D1 Mini Pin (Arduino Code)** | **Function**             |
|----------------|-----------------------------------|--------------------------------|--------------------------|
| **VCC**        | **3V3**                          | **3V3**                       | Power Supply             |
| **GND**        | **G**                            | **G**                         | Ground                   |
| **DO**         | **2**                            | **D4**                        | Digital Output (Flame Detection) |
| **AO**         | **A0**                           | **A0**                        | Analog Output (Flame Intensity)  |

### Wiring Picture
![Wiring Diagram](flame_sensor_wiring_diagram.png)

## Software Requirements
1. Install **Arduino IDE**.

## Steps to Run the Example
1. **Connect the wiring** as described in the table and diagram.
2. Open the Arduino IDE and select:
   - **Board**: `LOLIN(WEMOS) D1 mini`
   - **Port**: The COM port for your connected D1 Mini.
3. Copy and paste the code into the Arduino IDE.
4. Click **Upload** to program the D1 Mini.
5. Open the **Serial Monitor** and set the baud rate to **115200**.
6. Observe the flame detection status and intensity readings displayed in the Serial Monitor.

## How the Sensor Works
The KY-026 flame sensor is capable of detecting infrared light emitted by flames. It has two outputs:
- **Digital Output (DO):**
  - Outputs `LOW` when a flame is detected and `HIGH` otherwise.
  - Used for simple flame detection (on/off).
- **Analog Output (AO):**
  - Outputs a value between `0` (strong flame) and `1023` (no flame) representing flame intensity.
  - Useful for measuring the proximity or size of the flame.

## How to Test the Sensor
1. **Setup:**
   - Connect the flame sensor to the D1 Mini according to the wiring table.
   - Upload the provided code to the D1 Mini.
   - Open the Serial Monitor to observe flame detection and intensity values.

2. **Testing Flame Detection:**
   - Use a small flame source (e.g., a lighter or match) and place it near the sensor.
   - Observe the following behaviors:
     - The Serial Monitor displays "Yes" for flame detection.
     - The analog value decreases as the flame gets closer to the sensor.

3. **Test for No Flame:**
   - Move the flame away from the sensor or extinguish it.
   - Observe the following behaviors:
     - The Serial Monitor displays "No" for flame detection.
     - The analog value increases.

4. **Distance Sensitivity:**
   - Gradually move the flame closer to or farther from the sensor.
   - Note how the analog value changes, indicating flame intensity based on proximity.

## Troubleshooting
- **No flame detection:**
  - Ensure the sensor is correctly wired.
  - Verify the power supply is stable.
  - Ensure the sensor is facing the flame source.

- **Fluctuating readings:**
  - Test in a stable environment without strong ambient infrared sources.
  - Adjust the potentiometer on the sensor module to fine-tune sensitivity.

## Additional Notes
- Do not place the flame too close to the sensor to avoid damage.
- The KY-026 module includes an onboard LED that lights up when a flame is detected.
- Use the sensor in a well-ventilated area and follow fire safety precautions when testing.

## License
This project is licensed under the MIT License.

