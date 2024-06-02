#include <Arduino.h>
#include <Math.h>

float zuend_winkel = 30;    //in Grad
int gateimpuls_micro = 10;

//Max-Min Berechnung des Triacs
int einraststrom_mA = 30;
int haltestrom_mA = 20;
int U_eff = 230;
int R_L = 1000;

float zuend_winkel_min = round(asin((einraststrom_mA*R_L)/(sqrt(2)*U_eff))+0.5);
float zuend_winkel_max = 180 - round(asin((haltestrom_mA*R_L)/(sqrt(2)*U_eff))+0.5);

void nulldurchgang();

void setup(){ 
pinMode(3,OUTPUT);
pinMode(9,INPUT);
pinMode(0,INPUT);
pinMode(1,INPUT);
attachInterrupt(digitalPinToInterrupt(9),nulldurchgang,RISING);
}

void loop(){
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

void nulldurchgang(){
  delayMicroseconds(round(zuend_winkel*pow(10,6)/(360*50)));
  digitalWrite(3,HIGH);
  delayMicroseconds(gateimpuls_micro);
  digitalWrite(3,LOW);
}