#include <Arduino.h>

#define bomba 5
#define led 13
#define sensor A0

void ligaBomba(){ // Ligar a bomba 
  digitalWrite(bomba, HIGH);
}

void desligaBomba(){ // Desligar a bomba
  digitalWrite(bomba, LOW);
}

int lerSensor(){ // Leitura do sensor
  return analogRead(sensor);
}

void setup() {
  Serial.begin(9600);
  pinMode(bomba, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop() {
  if (lerSensor() > 670 ){ // Até agora o número razoável de umidade do solo, alterar quando necessário
    ligaBomba();
  }else{
    desligaBomba();
  }
  delay(1000);

  Serial.println(lerSensor());
  delay(1000);

}

