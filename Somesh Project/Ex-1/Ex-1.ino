#define MQ2_LPG A0;
#define DHTPIN D4
#define DHTTYPE DHT11

#include <ESP8266WiFi.h>
#include <MQ2_LPG.h>
#include <DHT.h>
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  pinMode(A0, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(D4, INPUT);
  pinMode(D8, OUTPUT);
  pinMode(D5, OUTPUT);
  dht.begin();
  Serial.begin(115200);
}

void loop() {
  int sensor = analogRead(A0);
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();
  Serial.print("Temperature : ");
  Serial.println(temp);
  Serial.print("Humidity : ");
  Serial.println(hum);
  if(sensor > 500){
  Serial.print("Answer : ");
  Serial.println(sensor);
  Serial.println("Not harmfull");
  digitalWrite(D8, HIGH);  
  }
  else if(sensor <500){                    
  digitalWrite(D8, LOW);    
  Serial.println("Not harmfull");
  }
  if((temp >= 25 && hum >= 60) && (temp < 40 && hum < 75)){
    analogWrite(D5, 100);
    Serial.println("Fan - Mid speed");
    digitalWrite(LED_BUILTIN, HIGH);  
  }
  else if(temp >= 30 && hum >= 70){
    analogWrite(D5, 255);
    Serial.println("Fan - Full speed");
    digitalWrite(LED_BUILTIN, LOW);  
  }
  delay(100);
}
