#include <Arduino.h>
#include <Math.h>

float zuend_winkel = 30;    //in Grad
int gateimpuls_micro = 10;
int bool_spnd = 0;  //Bool zum merken, ob Triag schon angeschaltet wurde in dieser Halbschwingung

void setup(){ 
pinMode(3,OUTPUT);
pinMode(6,INPUT);
pinMode(0,INPUT);
pinMode(1,INPUT);
}

void loop(){
  if (digitalRead(6)==1 && bool_spnd==0)
  {
    delayMicroseconds(round(zuend_winkel*pow(10,6)/(360*50)));  //zündzeit in micro = round(zuend_winkel*pow(10,6)/(360*50))
    digitalWrite(3,HIGH);
    delayMicroseconds(gateimpuls_micro);
    digitalWrite(3,LOW);
    bool_spnd = 1;
  }else if (digitalRead(6)==0 && bool_spnd==1)  //verhindert wiederholtes einschalten in einer Halbschwingung
  {
    bool_spnd=0;  
  }
  
  if (digitalRead(1)==1)        //Dunkler
  {
    zuend_winkel++;
  }else if (digitalRead(0)==1)  //Heller
  {
    zuend_winkel--;
  }
}