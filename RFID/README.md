# RFID-RC522 with LOLIN D1 Mini v4.0.0

This repository provides an example of how to connect and use the MFRC522 RFID module with the LOLIN D1 Mini v4.0.0. The example demonstrates reading RFID card UIDs and printing them to the Serial Monitor.

## Hardware Requirements
- **LOLIN D1 Mini v4.0.0**
- **MFRC522 RFID Module**
- **Jumper Wires**
- **RFID Cards/Tags**

## Wiring Diagram

| **RFID-RC522 Pin** | **D1 Mini Pin (Based on Board)**  | **D1 Mini Pin (Arduino Code)** | **Function**                |
|--------------------|-----------------------------------|--------------------------------|-----------------------------|
| **SDA**            | **SS**                            | **D8**                         | SPI Chip Select (SS)        |
| **SCK**            | **SCK**                           | **D5**                         | SPI Clock                   |
| **MOSI**           | **MISO**                          | **D6**                         | SPI Master Out Slave In     |
| **MISO**           | **MOSI**                          | **D7**                         | SPI Master In Slave Out     |
| **RST**            | **RST**                           | **D0**                         | Reset                       |
| **GND**            | **GND**                             | **G**                          | Ground                      |
| **VCC**            | **3V3**                           | **3V3**                        | 3.3V Power Supply           |

### Important Note
- The MISO and MOSI pins on the RFID-RC522 must be **switched** when connecting to the D1 Mini v4.0.0:
  - **RFID MOSI** connects to **D1 Mini MISO (D6)**.
  - **RFID MISO** connects to **D1 Mini MOSI (D7)**.

### Wiring Picture

![Wiring Diagram](RFID_wiring_diagram.png)

## Software Requirements
1. Install **Arduino IDE**.
2. Install the **MFRC522 Library**:
   - Open Arduino IDE.
   - Go to **Sketch > Include Library > Manage Libraries**.
   - Search for "MFRC522" by Miguel Balboa and click **Install**.


## Steps to Run the Example
1. **Connect the wiring** as described in the table and diagram.
2. Open the Arduino IDE and select:
   - **Board**: `LOLIN(WEMOS) D1 mini (clone)`
   - **Port**: The COM port for your connected D1 Mini.
3. Copy and paste the code into the Arduino IDE.
4. Click **Upload** to program the D1 Mini.
5. Open the **Serial Monitor** and set the baud rate to **115200**.
6. Place an RFID card near the MFRC522 module and observe the UID printed in the Serial Monitor.

## Troubleshooting
- **No output in Serial Monitor**:
  - Verify the correct port is selected in Arduino IDE.
  - Ensure the Serial Monitor baud rate matches the `Serial.begin(115200);` statement.
- **RFID tag not detected**:
  - Check the wiring.
  - Ensure the MFRC522 module is powered by 3.3V.
  - Test with different RFID tags/cards.

## Additional Notes
- The MFRC522 module requires 3.3V power. Do not use 5V as it may damage the module.
- Ensure the D1 Mini v4.0.0 pinout is followed exactly as described.

## License
This project is licensed under the MIT License.
