# IoT Seminar

## Introduction to IoT
The **Internet of Things (IoT)** is a network of interconnected devices that collect, exchange, and act on data in real-time. IoT combines sensors, actuators, communication protocols, and data processing to enable smarter environments, ranging from smart homes to industrial automation.

### Key Features of IoT
- **Data Streaming**: Collecting real-time data from sensors (e.g., temperature, humidity, or motion).
- **Threshold Notifications**: Alerting users when a condition exceeds defined limits (e.g., smoke detection).
- **Device Control**: Turning devices on/off or adjusting settings (e.g., adjusting thermostat temperature).
- **Automation**: Enabling scheduled or event-driven device interactions.

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

