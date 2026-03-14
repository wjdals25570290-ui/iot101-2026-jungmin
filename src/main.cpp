#include <Arduino.h>

int RELAY = 23;
int SW = 15;
volatile bool relayOn = false;

IRAM_ATTR void pushButton(){
  relayOn = ! relayOn;
}

void setup(){
  Serial.begin(115200);
  delay(500);
  Serial.println("Starting");
  pinMode(RELAY, OUTPUT);
  pinMode(SW, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(SW), pushButton, FALLING);
}

void loop(){
  delay(100);
  if (relayOn){
    digitalWrite(RELAY,HIGH);
  } else{
    digitalWrite(RELAY, LOW);
  }
}