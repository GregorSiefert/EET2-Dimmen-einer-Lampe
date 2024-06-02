#include <Arduino.h>
#include <Math.h>

float zuend_winkel = 30;    //in Grad
int gateimpuls_micro = 10;
int bool_spnd = 0;  //Bool zum merken, ob Triag schon angeschaltet wurde in dieser Halbschwingung

//Max-Min Berechnung des Triacs
int einraststrom_mA = 30;
int haltestrom_mA = 20;
int U_eff = 230;
int R_L = 1000;

float zuend_winkel_min = round(asin((einraststrom_mA*R_L)/(sqrt(2)*U_eff))+0.5);
float zuend_winkel_max = 180 - round(asin((haltestrom_mA*R_L)/(sqrt(2)*U_eff))+0.5);

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
    if (zuend_winkel>zuend_winkel_max)
    {
      zuend_winkel = zuend_winkel_max;
    }
  }else if (digitalRead(0)==1)  //Heller
  {
    zuend_winkel--;
    if (zuend_winkel<zuend_winkel_min)
    {
      zuend_winkel = zuend_winkel_min;
    }
  }
}