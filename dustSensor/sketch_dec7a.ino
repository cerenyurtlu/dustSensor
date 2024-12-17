#include <LiquidCrystal_I2C.h>
#include "config.h"
#include "Adafruit_MQTT.h"         // adafruit kütüphanesi
#include "Adafruit_MQTT_Client.h"  //adafruit kütüphanesi
#include <WiFi.h>

// LCD tanımı
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Toz sensörü ve LED pinleri
int measurePin = 34;  // ESP32'de kullanılan analog pin
int ledPower = 32;    // LED'in bağlı olduğu pin

// Zamanlama değişkenleri
int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9860;

// Ölçüm değişkenleri
float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

// Adafruit IO Feed tanımları
AdafruitIO_Feed *dustFeed = io.feed("dustdensity");

void setup() {
  // LCD başlatma
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("Dust Sensor");

  // Seri iletişim başlatma
  Serial.begin(115200);
  pinMode(ledPower, OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("?");
  }
  Serial.println("");
  Serial.println("Wi-Fi bağlantısı başarılı!");
  Serial.print("IP Adresi: ");
  Serial.println(WiFi.localIP());
  // Adafruit IO'ya bağlanma
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.println(io.statusText());
}

void loop() {
  io.run();  // Adafruit IO bağlantısını sürdür

  digitalWrite(ledPower, LOW);
  delayMicroseconds(samplingTime);

  voMeasured = analogRead(measurePin);

  delayMicroseconds(deltaTime);
  digitalWrite(ledPower, HIGH);
  delayMicroseconds(sleepTime);

  // Toz yoğunluğunu hesaplama
  calcVoltage = voMeasured * (3.3 / 4095.0);
  dustDensity = 0.17 * calcVoltage - 0.1;

  Serial.print("Dust Density: ");
  Serial.println(dustDensity);

  // LCD'ye yazdırma
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dust Density:");

  lcd.setCursor(0, 1);
  lcd.print(dustDensity, 3);

  // Adafruit IO'ya veri gönderme
  dustFeed->save(dustDensity);

  delay(3000);  // 3 saniye bekle
}
