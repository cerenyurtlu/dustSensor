# 🌫️ Dust Density Monitoring with ESP32 and Sharp GP2Y1010AU0F

This project uses an **ESP32** microcontroller and the **Sharp GP2Y1010AU0F Optical Dust Sensor** to measure dust density in the air. The measured values are displayed on a **2x16 I2C LCD** and sent to **Adafruit IO** for visualization and remote monitoring.

---

## 🛠️ Features

- Real-time dust density measurement using the **Sharp GP2Y1010AU0F** sensor.
- Display measurements on a **2x16 I2C LCD**.
- Send data to **Adafruit IO** for remote visualization.
- Works with **ESP32-WROOM-32D** module.

---

## 📦 Components

| **Component**                                      | **Quantity** | **Price**      |
|----------------------------------------------------|--------------|----------------|
| **Sharp GP2Y1010AU0F Dust Sensor**                | 1            | Varies         |
| **ESP32-WROOM-32D Wi-Fi/Bluetooth Module**        | 1            | 207.51 TL      |
| **2x16 I2C LCD Display**                          | 1            | 101.64 TL      |
| **Breadboard (830 Points)**                       | 1            | 36 TL          |
| **150Ω Resistor**                                 | 1            | -              |
| **220µF Capacitor**                               | 1            | -              |
| **Jumper Wires**                                  | Several      | -              |

---

## 📝 Installation

1. **Install Arduino IDE**  
   [Download Arduino IDE](https://www.arduino.cc/en/software)

2. **Add ESP32 Board Support**  
   - Go to `File` → `Preferences`  
   - Add the following URL to the **Boards Manager URLs**:  
     ```
     https://dl.espressif.com/dl/package_esp32_index.json
     ```
   - Open `Tools` → `Board` → `Boards Manager` and install the **ESP32** package.

3. **Install Required Libraries**  
   In the Arduino IDE, go to `Sketch` → `Include Library` → `Manage Libraries` and install:
   - `Adafruit IO Arduino`
   - `LiquidCrystal I2C`
   - `Adafruit MQTT Library`

4. **Clone This Repository**  
   ```bash
   git clone https://github.com/yourusername/dust-sensor-monitor.git
   ```

---

## ⚙️ Wiring Diagram

### Sharp GP2Y1010AU0F to ESP32

| **Sharp GP2Y1010AU0F Pin** | **ESP32 Pin**          |
|-----------------------------|------------------------|
| **LED (Pin 3)**            | `GPIO 32`              |
| **VOUT (Pin 5)**           | `GPIO 34` (Analog)     |
| **VCC (Pin 1)**            | `3.3V`                 |
| **GND (Pin 2, 4)**         | `GND`                  |

### LCD Display to ESP32

| **LCD I2C Pin**  | **ESP32 Pin**  |
|------------------|----------------|
| **SDA**          | `GPIO 21`      |
| **SCL**          | `GPIO 22`      |
| **VCC**          | `5V`           |
| **GND**          | `GND`          |

---

## 💻 Code Explanation

### `setup()`

- Initializes the **LCD** and displays a welcome message.
- Connects to **Wi-Fi** using the provided credentials.
- Establishes a connection to **Adafruit IO**.

### `loop()`

- Measures dust density from the **GP2Y1010AU0F sensor**.
- Displays the measured value on the **LCD**.
- Sends the measured value to **Adafruit IO**.
- Repeats every **3 seconds**.

---

## 🔧 How to Use

1. **Update Wi-Fi and Adafruit IO Credentials** in the code:

   ```cpp
   #define IO_USERNAME  "your_username"
   #define IO_KEY       "your_adafruit_io_key"
   
   #define WIFI_SSID    "your_wifi_ssid"
   #define WIFI_PASSWORD "your_wifi_password"
   ```

2. **Upload the Code** to ESP32:
   - Connect your ESP32 to your computer.
   - Select the correct port and board in **Arduino IDE** (`Tools` → `Board` → `ESP32`).
   - Click **Upload**.

3. **Monitor Output**:
   - Open the **Serial Monitor** (`115200 baud rate`) to see the data.
   - View real-time data on the **LCD**.
   - Check data visualization on **Adafruit IO**.

---

## 📊 Adafruit IO Setup

1. Go to [Adafruit IO](https://io.adafruit.com) and log in.
2. Create a new **Feed** named `dustdensity`.
3. Create a **Dashboard** and add a widget (e.g., **Line Chart**) linked to `dustdensity`.

---

## 📜 License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.

---

## 📝 References

- **Sharp GP2Y1010AU0F Datasheet**: [Download PDF](https://www.sparkfun.com/datasheets/Sensors/gp2y1010au_e.pdf)
- **Follows the tutorial**: https://github.com/sharpsensoruser/sharp-sensor-demos/wiki/Application-Guide-for-Sharp-GP2Y1014AU0F-Dust-Sensor

---

## 📧 Contact

For any questions or suggestions, feel free to reach out:
- **Email**: `cerennyurtlu@gmail.com`

---

**Enjoy Monitoring Air Quality! 🌱**
