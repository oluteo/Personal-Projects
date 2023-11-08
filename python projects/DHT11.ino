#include"DHT.h"
#define DHT11PIN 4
#define DHTTYPE DHT11
DHT dht(DHT11PIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("failed"));
                   return;
  }
  Serial.println("Humiidity");
  Serial.println(h);
  Serial.println("Temperature");
  Serial.println(t);
  Serial.println("temperature(f):");
  Serial.println(f);
  delay(2000);
}
