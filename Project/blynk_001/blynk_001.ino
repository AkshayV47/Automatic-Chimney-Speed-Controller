#define BLYNK_TEMPLATE_ID "TMPL3rEhRnJKE"
#define BLYNK_TEMPLATE_NAME "Automatic chimney sucking speed controller"
#define BLYNK_AUTH_TOKEN "vvmajsmm-USlEd8qpB7Lo-RVrPGEZFVX"

#define BLYNK_PRINT Serial
#define DHTPIN D4
#define DHTTYPE DHT11
#include <BlynkSimpleEsp8266.h>    
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <MQ2_LPG.h>
#include <DHT.h>

const char* ssid = "**************";
const char* password ="*******";
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  pinMode(A0, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(D4, INPUT);
  pinMode(D8, OUTPUT);
  pinMode(D5, OUTPUT);
  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
  Serial.begin(115200);
}

void loop() {
  int sensor = analogRead(A0);
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();
  Serial.print("Temperature : ");
  Serial.println(temp);
  Blynk.virtualWrite(V0, temp);
  Serial.print("Humidity : ");
  Serial.println(hum);
  Blynk.virtualWrite(V1, hum);
  if(sensor > 800){
  Serial.print("Answer : ");
  Serial.println(sensor);
  Blynk.virtualWrite(V2, sensor);
  Serial.println("There is a Gas leakage");
  Blynk.virtualWrite(V4,"There is a Gas leakage" );
  digitalWrite(D8, HIGH);  
  }
  else if(sensor <500){                    
  digitalWrite(D8, LOW);    
  Serial.println("here is no Gas leakage");
  Blynk.virtualWrite(V4,"here is no Gas leakage");
  }
  if((temp >= 29 && hum >= 30) && (temp < 40 && hum < 70)){
    analogWrite(D5, 100);
    Serial.println("Fan - Mid speed");
    Blynk.virtualWrite(V3, "Fan - Mid speed");
    digitalWrite(LED_BUILTIN, HIGH);  
  }
  else if(temp >= 31 && hum >= 20){
    analogWrite(D5, 255);
    Serial.println("Fan - Full speed");
    Blynk.virtualWrite(V3, "Fan - Full speed");
    digitalWrite(LED_BUILTIN, LOW);  
  }
  delay(100);
}


