/*

*/

#include <Arduino.h>
#include <U8x8lib.h>
#include <U8g2lib.h>

# include "DHT.h"

# define DHTTYPE DHT22  //Define DHT Sensor type
# define PINDHT 2  // Define data pin

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif

// U8X8
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);
// HT sensor
DHT dht(PINDHT, DHTTYPE);

char data[16];

void getHT(void) {
  float t = dht.readTemperature(); // 'C, Takes ~250ms
  //  float f = dht.readTemperature(true); // 'F
  float h = dht.readHumidity(); // %

  if (isnan(h) || isnan(t)) {
    Serial.println("NULL");
    return;
  }
  float t0 = dht.computeHeatIndex(t, h, false);
  //  float f0 = dht.computeHeatIndex(f, h);
  strcpy(data, (String(h) + "," + String(t0)).c_str());
  Serial.print(h);
  Serial.print(",");
  Serial.println(t0);
  //    Serial.println(data);
  //  return data;
}

void setup(void)
{
  Serial.begin(9600);  // Setup serial
  Serial.println("***DHT SENSOR!***");
  dht.begin();
  u8x8.begin();
}

void loop(void)
{
  //  char* data = getHT();
  getHT();
  u8x8.clearDisplay();
  u8x8.setFont(u8x8_font_open_iconic_weather_2x2);
  u8x8.drawString(5, 0, "\x42");
  u8x8.setFont(u8x8_font_pxplusibmcgathin_n);
  u8x8.drawString(5, 3, "2020");
  u8x8.setFont(u8x8_font_pxplusibmcgathin_u);
  u8x8.drawString(2, 5, "ARDUINO UNO");
  delay(500);
  u8x8.clearDisplay();
  u8x8.setFont(u8x8_font_pxplusibmcgathin_u);
  u8x8.drawString(5, 2, "%/'C");
  u8x8.setFont(u8x8_font_pxplusibmcgathin_n);
  u8x8.drawString(2, 4, data);
  Serial.println(data);
  delay(2500);
}
