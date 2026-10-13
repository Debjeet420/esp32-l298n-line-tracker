# ESP32 Line Following Robot (Wokwi Simulation)

An autonomous Line Following Robot designed using an **ESP32 DevKit V1**, an **L298N Motor Driver breakout chip**, **IR sensors (simulated with pushbuttons)**, and **4 status LEDs** for visual directional feedback.

---

## 🛠️ Components & Circuit Setup

### Hardware / Virtual Components
- **Microcontroller:** ESP32 DevKit V1
- **Motor Driver:** L298N Dual H-Bridge Module (`chip-l298n`)
- **Sensors:** 2x Pushbuttons (Simulating Left & Right IR Sensors)
- **Indicators:** 4x LEDs (Left FWD, Left REV, Right FWD, Right REV)

### Pin Mapping

| Component | Pin / Terminal | ESP32 Board Pin | Function |
| :--- | :--- | :--- | :--- |
| **Left IR Sensor** | Terminal 1.a / 2.a | `3V3` / `GPIO 18` | Left Sensor Digital Signal |
| **Right IR Sensor** | Terminal 1.a / 2.a | `3V3` / `GPIO 19` | Right Sensor Digital Signal |
| **L298N Driver** | VCC / GND | `5V` / `GND` | Power & Shared Ground |
| | ENA / ENB | `5V` / `5V` | Driver Enable Pins |
| | IN1 / IN2 | `GPIO 25` / `GPIO 26` | Left Motor Direction Control |
| | IN3 / IN4 | `GPIO 27` / `GPIO 14` | Right Motor Direction Control |
| **L FWD LED (Green)** | Anode / Cathode | `OUT1` / `GND` | Left Motor Forward Signal |
| **L REV LED (Red)** | Anode / Cathode | `OUT2` / `GND` | Left Motor Reverse Signal |
| **R FWD LED (Green)** | Anode / Cathode | `OUT3` / `GND` | Right Motor Forward Signal |
| **R REV LED (Red)** | Anode / Cathode | `OUT4` / `GND` | Right Motor Reverse Signal |

---

## 🚀 Control Logic Matrix

The robot adjusts steering dynamically using differential motor drive based on IR surface reflection:

| Left IR | Right IR | Left Motor | Right Motor | Robot Movement | Active Status LEDs |
| :---: | :---: | :---: | :---: | :---: | :--- |
| `0` (Off) | `0` (Off) | Forward | Forward | **Move Forward** | `L FWD` (Green) + `R FWD` (Green) |
| `1` (On) | `0` (Off) | Reverse | Forward | **Turn Left** | `L REV` (Red) + `R FWD` (Green) |
| `0` (Off) | `1` (On) | Forward | Reverse | **Turn Right** | `L FWD` (Green) + `R REV` (Red) |
| `1` (On) | `1` (On) | Stop | Stop | **Stop** | All LEDs OFF |

---

## ⚡ How to Run in Wokwi

1. Open [Wokwi.com](https://wokwi.com) and create a new **ESP32** project.
2. Replace the contents of `diagram.json` with the provided `diagram.json` in this repository.
3. Copy `src/sketch.ino` into the main sketch tab.
4. Add `chip-l298n` dependency to your project if prompted.
5. Click **Start Simulation**.

---

## 📜 License
This project is open-source and available under the [MIT License](LICENSE).