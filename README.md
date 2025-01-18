# IoT Seminar

## Introduction to IoT
The **Internet of Things (IoT)** is a network of interconnected devices that collect, exchange, and act on data in real-time. IoT combines sensors, actuators, communication protocols, and data processing to enable smarter environments, ranging from smart homes to industrial automation.

### Key Features of IoT
- **Data Streaming**: Collecting real-time data from sensors (e.g., temperature, humidity, or motion).
- **Threshold Notifications**: Alerting users when a condition exceeds defined limits (e.g., smoke detection).
- **Device Control**: Turning devices on/off or adjusting settings (e.g., adjusting thermostat temperature).
- **Automation**: Enabling scheduled or event-driven device interactions.

### Overview of IoT Use Cases
| **Category**                | **Description**                                                  | **Examples**                                                                                       |
|-----------------------------|------------------------------------------------------------------|---------------------------------------------------------------------------------------------------|
| **Data Streaming**          | Continuous or periodic collection of data from sensors.         | Monitoring temperature, humidity, or heart rate; GPS tracking for vehicles.                      |
| **Threshold Notifications** | Alerts when parameters cross a set threshold.                  | Smoke detection alarm, low soil moisture notification, or temperature exceeding a set value.     |
| **On/Off Control**          | Binary control of devices based on conditions.                  | Turning on lights when motion is detected or switching off a heater when a target temperature is reached. |
| **Value-Based Actions**     | Adjusting a device to a specific value instead of on/off.       | Adjusting brightness of a bulb, setting a thermostat temperature, or fan speed control.          |
| **Scheduled Operations**    | Automating actions based on a timer or schedule.                | Turning on lights at sunset, running appliances at specific times, or scheduling irrigation.      |
| **Event-Driven Actions**    | Triggering actions based on specific events or states.          | Smart doorbell notification, unlocking a door via proximity, or turning off appliances after inactivity. |
| **Data Logging and Analysis** | Storing data for trend analysis or tracking.                   | Logging energy consumption, weather pattern monitoring, or industrial equipment wear tracking.    |
| **Remote Monitoring and Control** | Monitoring or controlling devices remotely.                  | Controlling appliances via app, viewing security camera feeds, or adjusting irrigation settings while away. |
| **Multi-Device Interaction** | Devices communicating for complex automation.                  | Thermostat adjusting fans and AC together, motion sensors triggering cameras and lights.          |
| **User Feedback and Learning** | Adapting device behavior based on user preferences.            | Smart thermostat learning schedules, fitness trackers suggesting workouts, or adjusting speaker volume. |
| **Proactive Alerts**        | Anticipating issues and notifying users.                        | Predictive maintenance, low battery alerts, or filter replacement reminders.                     |
| **Geofencing**              | Triggering actions based on user location.                     | Locking doors when leaving home, turning on HVAC when nearby, or sending location-based reminders. |

## Introduction to MQTT
**MQTT (Message Queuing Telemetry Transport)** is a lightweight messaging protocol ideal for IoT applications. It facilitates communication between devices in a publish-subscribe model.

### Why MQTT for IoT?
- **Lightweight**: Minimal overhead, perfect for resource-constrained devices.
- **Reliable**: Offers QoS (Quality of Service) levels for reliable message delivery.
- **Scalable**: Handles numerous clients efficiently.

### MQTT Basics
- **Broker**: The central server that manages message distribution.
- **Client**: A device that publishes or subscribes to topics.
- **Topic**: A string used to filter messages (e.g., `home/livingroom/temperature`).
- **QoS Levels**:
  - `0`: At most once (fire-and-forget).
  - `1`: At least once (acknowledged delivery).
  - `2`: Exactly once (guaranteed delivery).

### Example Use Case
1. A temperature sensor publishes readings to the topic `home/livingroom/temperature`.
2. A smart thermostat subscribes to this topic and adjusts the heating accordingly.
3. Users can monitor the temperature via a dashboard.

## Introduction to Home Assistant
**Home Assistant** is an open-source home automation platform that enables local control and integration of IoT devices. It supports numerous protocols, including MQTT, Zigbee, and Z-Wave.

### Features
- **Device Integration**: Works with a wide range of devices and platforms.
- **Automation**: Create custom automations to control devices based on events, schedules, or conditions.
- **Dashboards**: Build customizable interfaces to monitor and control devices.
- **Local Control**: Operates locally, ensuring privacy and reliability without relying on the cloud.

### Getting Started with Home Assistant
1. **Install Home Assistant**:
   - Use a Raspberry Pi or install on Docker, a virtual machine, or directly on a server.
2. **Configure MQTT**:
   - Set up an MQTT broker (e.g., Mosquitto).
   - Integrate MQTT with Home Assistant.
3. **Add Devices**:
   - Connect IoT devices (e.g., sensors, switches, cameras) using supported protocols.
4. **Automate**:
   - Create automations to respond to events (e.g., turn on lights when motion is detected).
5. **Monitor and Control**:
   - Use the Home Assistant dashboard to view and control devices.

### Example Automation
- **Scenario**: Turn on lights when motion is detected at night.
```yaml
alias: Turn on Lights on Motion
trigger:
  - platform: state
    entity_id: binary_sensor.motion_sensor
    to: 'on'
conditions:
  - condition: time
    after: '19:00:00'
    before: '06:00:00'
  - condition: state
    entity_id: light.living_room
    state: 'off'
action:
  - service: light.turn_on
    target:
      entity_id: light.living_room
```

## Conclusion
IoT, MQTT, and Home Assistant together provide a powerful platform for creating smart environments. With MQTT handling efficient communication and Home Assistant offering robust integration and automation tools, building and managing IoT systems becomes accessible and versatile.

For more information, explore the [Home Assistant Documentation](https://www.home-assistant.io/docs/) or learn about [MQTT Protocol](https://mqtt.org/).

