#include <Wire.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// WiFi Credentials
const char* ssid = "Your_WiFi_SSID";
const char* password = "Your_WiFi_Password";

// Stock Market API (Replace with your API Key)
String stock_symbol = "AAPL";  // Default: Apple Inc.
String api_key = "YOUR_API_KEY";
String api_url = "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=" + stock_symbol + "&apikey=" + api_key;

// OLED Setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    // Connect to WiFi
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi Connected!");

    // Initialize OLED
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("SSD1306 allocation failed");
        for (;;);
    }
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
}

void loop() {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin(api_url);
        int httpCode = http.GET();

        if (httpCode == 200) {
            String payload = http.getString();
            Serial.println(payload);

            // Parse JSON Data
            DynamicJsonDocument doc(1024);
            deserializeJson(doc, payload);
            String stock_price = doc["Global Quote"]["05. price"].as<String>();

            // Display on OLED
            display.clearDisplay();
            display.setCursor(0, 0);
            display.println("Stock: " + stock_symbol);
            display.println("Price: $" + stock_price);
            display.display();
        } else {
            Serial.println("Error fetching stock data!");
        }

        http.end();
    }

    delay(60000);  // Fetch stock data every 1 minute
}
