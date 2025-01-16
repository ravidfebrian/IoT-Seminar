# Raindrop Detection with MH-RD Module and LOLIN D1 Mini v4.0.0

This repository provides an example of how to use the MH-RD raindrop detection module with the LOLIN D1 Mini v4.0.0. The example demonstrates reading digital and analog values from the raindrop sensor and printing them to the Serial Monitor.

## Hardware Requirements
- **LOLIN D1 Mini v4.0.0**
- **MH-RD Raindrop Detection Module**
- **Jumper Wires**

## Wiring Diagram

| **MH-RD Pin** | **D1 Mini Pin (Based on Board)** | **D1 Mini Pin (Arduino Code)** | **Function**               |
|---------------|-----------------------------------|--------------------------------|----------------------------|
| **VCC**       | **3V3**                          | **3V3**                       | Power Supply               |
| **GND**       | **G**                            | **G**                         | Ground                     |
| **DO**        | **SCL**                          | **D1**                        | Digital Output (Rain Detection) |
| **AO**        | **A0**                           | **A0**                        | Analog Output (Moisture Level) |

### Important Note
- On the D1 Mini v4.0.0 board, the **SCL** pin is equivalent to **D1** in Arduino code.

### Wiring Picture

![Wiring Diagram](mh_rd_wiring_diagram.png)

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
6. Observe the rain detection status and moisture level readings.

## Understanding the Output
- **Rain Detection (Digital Value)**:
  - `0` or "Yes": Rain/Water detected.
  - `1` or "No": No rain/water detected.
- **Water Level (Analog Value)**:
  - A value between `0` and `1023` corresponding to the water level on the sensor pad.
  - Converted to voltage for better understanding (e.g., `1.65V`).

## Troubleshooting
- **No output in Serial Monitor**:
  - Verify the correct port is selected in Arduino IDE.
  - Ensure the Serial Monitor baud rate matches the `Serial.begin(115200);` statement.
- **Incorrect readings**:
  - Check wiring and connections.
  - Ensure the sensor pad is clean and functioning.

## Additional Notes
- The MH-RD module requires 3.3V power. Using 5V may damage the module.
- The analog output can be calibrated using the potentiometer on the module.

## License
This project is licensed under the MIT License.

