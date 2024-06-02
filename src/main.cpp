#include <Arduino.h>
#include <Math.h>

float zuend_winkel = 30;    //in Grad
float zuend_zeit_sec = zuend_winkel/(360*50);
int zuend_zeit_micro = round(zuend_zeit_sec*pow(10,6));
int gateimpuls_micro = 10;

void setup(){ 
pinMode(3,OUTPUT);
pinMode(6,INPUT);
}

void loop(){
  if (digitalRead(6)==1)
  {
    delayMicroseconds(zuend_zeit_micro);
    digitalWrite(3,HIGH);
    delayMicroseconds(gateimpuls_micro);
    digitalWrite(3,LOW);
    while (digitalRead(6)==1){};    //verhindert wiederholtes einschalten in einer Halbschwingung
  }
}