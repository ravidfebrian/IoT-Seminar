# Capacitive Soil Moisture Sensor v1.2 with LOLIN D1 Mini v4.0.0

This repository provides an example of how to use the Capacitive Soil Moisture Sensor v1.2 with the LOLIN D1 Mini v4.0.0. The example demonstrates reading soil moisture levels and visualizing the data in the Serial Plotter.

## Hardware Requirements
- **LOLIN D1 Mini v4.0.0**
- **Capacitive Soil Moisture Sensor v1.2**
- **Jumper Wires**
- **3.3V or 5V Power Supply**

## Wiring Diagram

| **Soil Moisture Sensor Pin** | **D1 Mini Pin (Based on Board)** | **D1 Mini Pin (Arduino Code)** | **Function**          |
|------------------------------|-----------------------------------|--------------------------------|-----------------------|
| **VCC**                      | **3V3**                          | **3V3**                       | Power Supply (3.3V or 5V) |
| **GND**                      | **G**                            | **G**                         | Ground                |
| **OUT**                      | **A0**                           | **A0**                        | Analog Output (Moisture Data) |

### Wiring Picture

![Wiring Diagram](soil_moisture_wiring_diagram.png)

## Software Requirements
1. Install **Arduino IDE**.

## Steps to Run the Example
1. **Connect the wiring** as described in the table and diagram.
2. Open the Arduino IDE and select:
   - **Board**: `LOLIN(WEMOS) D1 mini`
   - **Port**: The COM port for your connected D1 Mini.
3. Copy and paste the code into the Arduino IDE.
4. Click **Upload** to program the D1 Mini.
5. Open the **Serial Plotter** (from the Arduino IDE: `Tools > Serial Plotter`).
6. Set the baud rate to **115200**.
7. Observe the soil moisture signal displayed in the Serial Plotter.

## How to Test the Sensor
- **Testing Soil Moisture**:
  - Insert the sensor into the soil, ensuring the capacitive probe is fully submerged.
  - Ensure the probe is clean and free of debris for accurate readings.
- **Environment**:
  - Use the sensor in a stable environment to reduce noise.
- **Interpreting the Signal**:
  - The Serial Plotter will display a voltage corresponding to the soil moisture level.
  - Higher voltage indicates drier soil; lower voltage indicates wetter soil.

## Understanding the Output
- **Voltage Output**:
  - The sensor outputs a voltage between **0V (wet)** and **3.3V (dry)** (when powered with 3.3V).
  - If powered with 5V, adjust the voltage conversion in the code.

## Troubleshooting
- **No signal in Serial Plotter**:
  - Verify the correct port is selected in Arduino IDE.
  - Ensure the Serial Plotter baud rate matches the `Serial.begin(115200);` statement.
- **Inconsistent readings**:
  - Ensure the probe is fully submerged in soil and clean.
  - Check the power supply and wiring connections.

## Additional Notes
- The sensor can operate at both **3.3V and 5V**. Adjust the wiring and voltage conversion formula in the code accordingly.
- Clean the probe after use to maintain accuracy and longevity.
- Avoid exposing the sensor to water above the probe's maximum marking to prevent damage.

## License
This project is licensed under the MIT License.

