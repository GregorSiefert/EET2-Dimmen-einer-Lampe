#include <Arduino.h>

void setup(){ 
// Initialisiert Pin 14 (LED1) als output und die beiden Taster
pinMode(14,OUTPUT);
pinMode(0,INPUT);
pinMode(1,INPUT);
}

//LED1 schaltet ein mit Taster 1 und aus mit Taster 2
void loop(){
digitalWrite(14,HIGH);
while (digitalRead(1)==0){};
digitalWrite(14,LOW);
while (digitalRead(0)==0){};
}