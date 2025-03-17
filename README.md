# 📈 ESP32 Stock Market Ticker with OLED Display 🖥️

This project allows you to **fetch real-time stock prices** using an ESP32 and display them on a **0.96" OLED display (SSD1306, I2C)**. The ESP32 connects to **WiFi**, fetches stock market data from an API, and updates the OLED screen every minute.

---

## **🚀 Features**
✅ Fetches **real-time stock prices** from an API  
✅ Displays stock price on an **OLED (0.96" SSD1306, I2C)**  
✅ Uses **WiFi** to fetch stock data  
✅ Updates the stock price **every 1 minute**  
✅ Can be expanded to **support multiple stocks & alerts**  

---

## **🔧 Hardware Requirements**
- **ESP32 Development Board**
- **0.96" OLED Display (SSD1306, I2C)**
- **Jumper Wires**
- **WiFi Connection**

---

## **🔌 Wiring: ESP32 to OLED (SSD1306, I2C)**
| **OLED Pin** | **ESP32 Pin** |
|-------------|--------------|
| VCC         | **3.3V**         |
| GND         | **GND**          |
| SDA         | **GPIO21**       |
| SCL         | **GPIO22**       |

✅ **Ensure you connect the OLED correctly before uploading the code.**

---

## **📥 Software Setup**
### **1️⃣ Install Required Libraries**
Before uploading the code, **install the following Arduino libraries**:
- `Adafruit_GFX`
- `Adafruit_SSD1306`
- `ArduinoJson`
- `WiFi`
- `HTTPClient`

To install these libraries in **Arduino IDE**:
1. Go to **Sketch** → **Include Library** → **Manage Libraries**.
2. Search for the library names and click **Install**.

---

### **2️⃣ Stock Market API Setup**
We use **Alpha Vantage API** to get real-time stock data.

#### **🔹 Get Your API Key**
1. **Go to** [Alpha Vantage API](https://www.alphavantage.co/support/#api-key).
2. Sign up for a **free API key**.
3. Copy your **API Key** and **replace it in the code**.

---
