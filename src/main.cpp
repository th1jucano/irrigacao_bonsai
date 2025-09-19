#include <Arduino.h>
#include <RTClib.h>

#define bomba 5
#define sensor A0
#define led 13

RTC_DS3231 rtc;

unsigned long pisca = 0;
bool estadoLed = false;
int umidade = 0;

void piscaLed(){

  unsigned long agoraMillis = millis();

  if (estadoLed && (agoraMillis - pisca >= 1000)){
    digitalWrite(led, LOW);
    estadoLed = false;
    pisca = agoraMillis;
  }else if(!estadoLed && (agoraMillis - pisca >= 500)){
    digitalWrite(led, HIGH);
    estadoLed = true;
    pisca = agoraMillis;
  }

}

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
  rtc.begin();
  pinMode(bomba, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);

  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

}

void loop() {
  DateTime agora = rtc.now();
  int horaAtual = agora.hour(); // data e hora atuais
  umidade = lerSensor();

  piscaLed();
  
  if ((horaAtual > 7) && (horaAtual < 17)){
    Serial.print(" ");
    Serial.println(horaAtual);
    if (umidade > 670 ){ // Até agora o número razoável de umidade do solo, alterar quando necessário
      ligaBomba();
    }else{
      desligaBomba();
    }
  }

  Serial.println(umidade);
  
  
}

