# Heartbeat Measurement with HW-827 and LOLIN D1 Mini v4.0.0

This repository provides an example of how to use the HW-827 heartbeat sensor with the LOLIN D1 Mini v4.0.0. The example demonstrates reading heartbeat data using the sensor, visualizing the signal in the Serial Plotter, and measuring heartbeat values.

## Hardware Requirements
- **LOLIN D1 Mini v4.0.0**
- **HW-827 Heartbeat Sensor**
- **Jumper Wires**

## Wiring Diagram

| **HW-827 Pin** | **D1 Mini Pin (Based on Board)** | **D1 Mini Pin (Arduino Code)** | **Function**                   |
|----------------|----------------------------------|--------------------------------|--------------------------------|
| **VCC**        | **3V3**                          | **3V3**                        | Power Supply                   |
| **GND**        | **G**                            | **G**                          | Ground                         |
| **OUT**        | **A0**                           | **A0**                         | Analog Output (Heartbeat Data) |

### Wiring Picture

![Wiring Diagram](hw827_wiring_diagram.png)

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
7. Observe the heartbeat waveform displayed in the Serial Plotter.

## How to Test the Sensor
- **Sensor Placement**:
  - Attach the HW-827 sensor to the **tip of your finger** using a soft band or hold it gently to ensure consistent contact.
  - Ensure the sensor is not obstructed by external light sources to avoid interference.
- **Environment**:
  - Test the sensor in a quiet and stable environment to minimize noise and movement artifacts.
  - Keep your hand steady during measurement.
- **Reading the Signal**:
  - The Serial Plotter will display a waveform corresponding to your heartbeat.
  - Peaks in the waveform represent individual heartbeats.
- **Tips for Accurate Results**:
  - Warm up the sensor for 10-15 seconds before taking measurements.
  - Avoid pressing the sensor too tightly as it may restrict blood flow and distort readings.

## Understanding the Output
- **Serial Plotter Visualization**:
  - The sensor outputs a pulsing waveform corresponding to the heartbeat.
  - Peaks in the waveform represent heartbeats.
- **Heartbeat Value (Analog Reading)**:
  - A value between `0` and `1023` based on the sensor's analog output.
  - This value corresponds to the voltage signal from the sensor.
- **Voltage**:
  - The analog reading is converted to a voltage (0-3.3V) for better understanding.

## Measuring Heartbeat Rate
To calculate the heartbeat rate in beats per minute (BPM):
1. Count the number of peaks in the waveform over a 10-second interval.
2. Multiply this count by 6 to obtain BPM.

```

## Troubleshooting
- **No signal in Serial Plotter**:
  - Verify the correct port is selected in Arduino IDE.
  - Ensure the Serial Plotter baud rate matches the `Serial.begin(115200);` statement.
- **No peaks detected**:
  - Ensure the sensor is properly placed on your finger.
  - Adjust the threshold value in the code based on your signal.

## Additional Notes
- The HW-827 sensor requires a stable 3.3V power supply.
- Ensure the sensor is used in a quiet environment to reduce noise and improve accuracy.
- For more precise measurements, consider implementing a moving average filter to smooth the signal.

## License
This project is licensed under the MIT License.

