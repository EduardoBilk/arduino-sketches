#include <DHT.h>

#define DHTPIN A1
#define DHTTYPE DHT11

int ledPin = 13;
int coPin = 8;
int state = 0;
int flag = 0;
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(coPin, INPUT);
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  if (Serial.available() > 0) {
    state = Serial.read();
    flag = 0;
  }
  if (state == '0') {
    digitalWrite(ledPin, LOW);
    if (flag == 0) {
      Serial.println("Sistema em Stand by");
      flag = 1;
    }

  } else  {
    digitalWrite(ledPin, HIGH);
    coletaCO();
    coletaUT();
    if (flag == 0) {
      Serial.println("Sistema iniciando coleta.");
      flag = 1;
    }


  }
  

}

void coletaCO(){
 int sensorCOValue = 0;
 sensorCOValue = analogRead(A0);
 Serial.println(sensorCOValue);
// if (digitalRead(8) == HIGH) {     
//    Serial.println("Saida digital abaixo do limite" );   
//  } 
//  else {
//    Serial.println("Saida digital acima do limite" );  
//  }
 delay(1000);
}

void coletaUT(){
  float u = dht.readHumidity();
  float t = dht.readTemperature();
  
  if (isnan(t) || isnan(u)) {
    Serial.println("Sensor de Umidade e Temperatura falhou.");
  } else {
//    Serial.print("Umidade: ");
    Serial.println(u);
//    Serial.print(" %\t");
//    Serial.print("Temperatura: "); 
    Serial.println(t);
//    Serial.println(" *C");
  delay(1000);
  }
}
