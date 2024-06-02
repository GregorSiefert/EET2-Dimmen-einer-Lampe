#include <Arduino.h>

int blink_abstand = 1;  //in sekunden
int frequenz = 50;
int needed_count = blink_abstand*frequenz*2;
int counter = 0;
int gateimpuls_micro = 10;

void setup(){ 
// Initialisiert Pin 14 (LED1) als output
pinMode(3,OUTPUT);
pinMode(6,INPUT);
}

//LED1 blinkt im Zweisekundentakt
void loop(){
  	if (digitalRead(6)==1)
    {
      counter++;
      if (counter%needed_count==0) //Triac für eine Halbschwingung anschalten
      {
        digitalWrite(3,HIGH);
        delayMicroseconds(gateimpuls_micro);
        digitalWrite(3,LOW);
      }   
    }    
}