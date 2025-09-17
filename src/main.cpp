#include <Arduino.h>

#define bomba 5
#define led 13
#define sensor A0


void ligaBomba(){
  digitalWrite(bomba, HIGH);
}

void desligaBomba(){
  digitalWrite(bomba, LOW);
}

int lerSensor(){
  return analogRead(sensor);
}

void setup() {
  Serial.begin(9600);
  pinMode(bomba, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop() {
  if (lerSensor() > 670 ){
    ligaBomba();
  }else{
    desligaBomba();
  }
  delay(1000);

  Serial.println(lerSensor());
  delay(1000);


  // ligaBomba(true);
  // delay(50000);
  // ligaBomba(false);
  // delay(50000);

}

