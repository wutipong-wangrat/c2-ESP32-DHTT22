#include <Arduino.h>
#include<Adafruit_Sensor.h>
#include <Wire.h>
#include<DHT.h>
#include <SPI.h>

DHT mysensor(5,DHT12);
float temperature,humidity;
int LED = 4;

void setup() {
  Serial.begin(11250);
  mysensor.begin();
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {
  humidity = mysensor.readHumidity();
  temperature = mysensor.readTemperature();
  if(temperature >= 26.5){
    digitalWrite(LED,HIGH);
    Serial.print("LED ON");
  }else{
    digitalWrite(LED,LOW);
    Serial.print("LED OFF");
  }
  Serial.print("Temerature: ");
  Serial.print(temperature);
  Serial.print("C / Humidity");
  Serial.print(humidity);
  Serial.print("%");
  delay(2000);
}