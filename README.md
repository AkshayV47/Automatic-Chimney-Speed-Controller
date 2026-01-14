# Automatic-Chimney-Speed-Controller
Automatic Chimney Speed Controller using ESP IOT project

# Automatic Chimney Speed Controller (ESP IoT)

## 📌 Project Overview

The **Automatic Chimney Speed Controller** is an IoT-based embedded system designed to automatically control the speed of a kitchen chimney (exhaust fan) using an ESP microcontroller. The system monitors environmental conditions such as smoke, gas, or temperature and dynamically adjusts the chimney speed without manual intervention. This improves air quality, enhances safety, and optimizes power consumption.

---

## 🚀 Features

* Automatic chimney fan speed control based on sensor data
* Real-time monitoring using ESP-based IoT platform
* Reduces manual effort and human error
* Improves kitchen air quality and smoke removal
* Energy-efficient operation
* Scalable and cost-effective design
* Can be extended with mobile/web dashboard support

---

## ⚙️ Working Principle

1. Sensors continuously monitor kitchen conditions such as smoke, gas concentration, or temperature.
2. The sensor data is read by the ESP microcontroller.
3. Based on predefined threshold values, the controller determines the required chimney speed.
4. The ESP generates control signals (PWM or relay-based) to adjust the chimney motor speed.
5. As conditions normalize, the system automatically reduces or turns off the chimney speed.

This closed-loop system ensures efficient ventilation while minimizing unnecessary power usage.

---

## 🧩 Components Used

### Hardware Components

* ESP8266 / ESP32 Microcontroller
* Gas / Smoke Sensor (MQ series or equivalent)
* Temperature Sensor (optional)
* Relay Module or Motor Driver
* Chimney Exhaust Fan (AC/DC motor)
* Power Supply Module
* Connecting Wires and PCB/Breadboard

### Software & Tools

* Arduino IDE
* ESP Board Package
* Embedded C / Arduino Framework
* IoT Platform (optional – Blynk, Firebase, Thingspeak, etc.)

---

## 🔄 Flowchart

```
Start
  ↓
Initialize ESP & Sensors
  ↓
Read Sensor Values
  ↓
Compare with Threshold Levels
  ↓
Determine Required Chimney Speed
  ↓
Control Fan Speed (PWM / Relay)
  ↓
Monitor Continuously
  ↓
Repeat Process
```

---

## 📈 Applications

* Smart kitchens
* Home automation systems
* Commercial kitchens
* Energy-efficient ventilation systems

---

## 🔮 Future Enhancements

* Mobile application for real-time monitoring
* AI-based adaptive speed control
* Voice assistant integration
* Cloud data logging and analytics
* Fire and gas leak alert system

---

## 🧠 Conclusion

The **Automatic Chimney Speed Controller** demonstrates how IoT and embedded systems can be used to automate everyday appliances for improved safety, efficiency, and user convenience. This project serves as a practical implementation of smart home automation using ESP technology.

---
