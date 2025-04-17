#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_SSD1306 display(128, 64, &Wire);
Adafruit_BME280 bme;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  bme.begin(0x76);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.display(); 
}

void display_value(const String& title, const String& value, int x, int y) {
    display.setCursor(x, y + 4);
    display.setTextSize(1);
    display.print(title + ":");
    display.setCursor(x + 12, y);
    display.setTextSize(2);
    display.print(value);
}

void loop() {
  int temperature = bme.readTemperature();
  float pressure = bme.readPressure() / 100.0F;
  int humidity = bme.readHumidity();

  display.fillRect(0, 0, 128, 64, SSD1306_BLACK);
  display_value("T", String(temperature) + "C", 0, 0);
  display_value("H", String(humidity) + "%", 68, 0);
  display_value("P", String(pressure) + "hPa", 0, 32);
  display.display(); 
  
  delay(10000);  
}
