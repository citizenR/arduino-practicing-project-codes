/*

*/

#include <Arduino.h>
#include <U8x8lib.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif

// init U8X8 object
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);

void getHT(void) {

}

void setup(void)
{
  u8x8.begin();
}

void loop(void)
{
  u8x8.setFont(u8x8_font_open_iconic_weather_2x2);
  u8x8.drawString(4, 0, "\x40");
  u8x8.setFont(u8x8_font_pxplusibmcgathin_n);
  u8x8.drawString(4, 3, "0123456789");
  u8x8.setFont(u8x8_font_pxplusibmcgathin_u);
  u8x8.drawString(4, 5, "ARDUINO UNO");
  delay(500);
}
