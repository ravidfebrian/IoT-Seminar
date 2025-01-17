# GY-BMP280 Sensor with LOLIN D1 Mini v4.0.0

This repository provides an example of how to use the GY-BMP280 sensor (for temperature and pressure measurements) with the LOLIN D1 Mini v4.0.0. The example demonstrates reading data via the I2C interface and displaying it in the Serial Monitor.

## Hardware Requirements
- **LOLIN D1 Mini v4.0.0**
- **GY-BMP280 Sensor Module**
- **Jumper Wires**

## Wiring Diagram

| **GY-BMP280 Pin** | **D1 Mini Pin (Based on Board)** | **D1 Mini Pin (Arduino Code)** | **Function**          |
|--------------------|-----------------------------------|--------------------------------|-----------------------|
| **VCC**            | **3V3**                          | **3V3**                       | Power Supply          |
| **GND**            | **G**                            | **G**                         | Ground                |
| **SCL**            | **SCL**                          | **D1**                        | I2C Clock Signal      |
| **SDA**            | **SDA**                          | **D2**                        | I2C Data Signal       |

### Wiring Picture
![Wiring Diagram](gy_bmp280_wiring_diagram.png)

## Software Requirements
1. Install **Arduino IDE**.
2. Install the required libraries for the BMP280 sensor:
   - Open Arduino IDE.
   - Go to **Sketch > Include Library > Manage Libraries**.
   - Search for "Adafruit BMP280 Library" and click **Install**.
   - Search for "Adafruit Unified Sensor" and click **Install**.

## Steps to Run the Example
1. **Connect the wiring** as described in the table and diagram.
2. Open the Arduino IDE and select:
   - **Board**: `LOLIN(WEMOS) D1 mini`
   - **Port**: The COM port for your connected D1 Mini.
3. Copy and paste the code into the Arduino IDE.
4. Click **Upload** to program the D1 Mini.
5. Open the **Serial Monitor** and set the baud rate to **115200**.
6. Observe the temperature and pressure readings displayed in the Serial Monitor.

## How to Test the Sensor
- **Verify Measurements**:
  - Place the sensor in different environments to observe changes in temperature and pressure.
  - Compare the readings with a known reference device for calibration.

## Understanding the Output
- **Temperature**:
  - Measured in degrees Celsius (°C).
- **Pressure**:
  - Measured in hectopascals (hPa).
  - Useful for altitude estimation if needed.

## Troubleshooting
- **Sensor not detected**:
  - Ensure the wiring matches the table and diagram.
  - Verify the I2C address (default is `0x76`, some modules use `0x77`).
- **Incorrect readings**:
  - Check the power supply (3.3V recommended).
  - Ensure the sensor is not exposed to extreme conditions beyond its specifications.

## Additional Notes
- The GY-BMP280 sensor is a low-power, high-precision barometric pressure and temperature sensor.
- If using the SPI interface instead of I2C, modify the wiring and code accordingly.

## License
This project is licensed under the MIT License.

