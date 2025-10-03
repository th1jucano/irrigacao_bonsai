#include <Arduino.h>
#include <PiscaLed.h>

#define bomba 5
#define sensor A0

int umidade = 0;
unsigned long ultimoSerial = 0;

PiscaLed led(13);

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
  led.begin();
}

void loop() {
  umidade = lerSensor();
  
  if (umidade > 750 ){ // Até agora o número razoável de umidade do solo, alterar quando necessário
    ligaBomba();
  }else{
    desligaBomba();
  }
  
  led.setTempos(100,1000);
  led.atualizar();

  // Imprime no Serial apenas a cada 1 segundo, sem travar o loop
  if (millis() - ultimoSerial >= 1000) {
    Serial.println(umidade);
    ultimoSerial = millis();
  }
}

