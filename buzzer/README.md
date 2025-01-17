# Playing a Buzzer (KY-006) with LOLIN D1 Mini v4.0.0

This guide explains how to connect a KY-006 piezo buzzer module to a LOLIN D1 Mini v4.0.0 and program it to play tones or simple melodies using the Arduino IDE.

## Hardware Requirements
- **LOLIN D1 Mini v4.0.0**
- **KY-006 Piezo Buzzer Module**
- **Jumper Wires**

## Wiring Diagram

| **KY-006 Pin** | **D1 Mini Pin (Based on Board)** | **D1 Mini Pin (Arduino Code)** | **Function**        |
|----------------|-----------------------------------|--------------------------------|---------------------|
| **VCC**        | **3V3**                          | **3V3**                       | Power Supply        |
| **GND**        | **GND**                            | **G**                         | Ground              |
| **Signal**     | **2**                            | **D2**                        | Signal Input        |

### Wiring Picture
![Wiring Diagram](ky006_buzzer_wiring_diagram.png)

## Software Requirements
1. Install **Arduino IDE**.

## Code Example
Basic example is given in buzzer.ino

### Playing a Melody
To play a melody, you can use an array to define notes and durations. melody.ino is an example.

## Steps to Run the Example
1. **Connect the wiring** as described in the table and diagram.
2. Open the Arduino IDE and select:
   - **Board**: `LOLIN(WEMOS) D1 mini`
   - **Port**: The COM port for your connected D1 Mini.
3. Copy and paste the code into the Arduino IDE.
4. Click **Upload** to program the D1 Mini.
5. Observe the buzzer playing tones or melodies.

## How to Test the Buzzer
1. **Test Simple Tones:**
   - Use the basic example to play a steady tone.
   - Vary the frequency in `tone(BUZZER_PIN, frequency)` to test different pitches.

2. **Test Melody Playback:**
   - Use the melody example to play a sequence of notes.
   - Modify the `melody` and `noteDurations` arrays to customize the tune.

3. **Observe Behavior:**
   - Ensure the buzzer produces clear tones.
   - Verify the sound matches the expected frequency or melody.

## Troubleshooting
- **No sound from the buzzer:**
  - Verify the wiring matches the diagram.
  - Ensure the KY-006 module is properly connected.

- **Distorted sound:**
  - Check the power supply voltage (3.3V for the D1 Mini).
  - Ensure the tone frequency is within the buzzer's range.

## Additional Notes
- The KY-006 module is designed for precise tone control and works well with the `tone()` function.
- Avoid running the buzzer at high frequencies for prolonged periods to prevent damage.

## License
This project is licensed under the MIT License.

