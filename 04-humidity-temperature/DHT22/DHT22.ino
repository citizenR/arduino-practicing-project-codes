/*
  DHT22: vcc 3-5V, ±5% humidity, ±0.5'C temperature
*/

# include "DHT.h"

# define DHTTYPE DHT22  //Define DHT Sensor type
# define PINDHT 2  // Define data pin

DHT dht(PINDHT, DHTTYPE);

void setup() {
  Serial.begin(9600);  // Setup serial
  Serial.println("***DHT SENSOR!***");
  dht.begin();
}

void loop() {
  // serial write (humidity%, temperature 'C)
  delay(2000);
  float t = dht.readTemperature(); // 'C, Takes ~250ms
  float f = dht.readTemperature(true); // 'F
  float h = dht.readHumidity(); // %

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("NULL");
    return;
  }
  float t0 = dht.computeHeatIndex(t, h, false);
  float f0 = dht.computeHeatIndex(f, h);
  Serial.print(h);
  Serial.print(",");
  Serial.println(t0);
}
