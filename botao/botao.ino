// pra esse sketch precisa de:
// um resistor de 10k
// um resistor de 300
// um botao
// jumpers
// um led

// ligue o 5V do arduino com a perna inferior dir do botao
// ligue o resistor de 10k com a perna inferior esq do botao
// ligue o gnd do arduino com a outra perna do resistor
// ligue um jumper na perna superior esq do botao com o pino 5 digital
// ligue um jumper no pino 10 digital ao resistor de 300
// ligue a outra ponta do resistor com a perna maior do led
// ligue a perna menor do led no gnd 

// YOU ARE READY TO GO!!!

int readPin = 5; //definimos 5 como pino que vai ler a info do botao
int ledPin = 10; // definimos 10 como pino que vai acender o led

// setup roda antes do loop e apenas quando o codigo e enviado ao arduino
void setup() {
  pinMode(readPin, INPUT);// definimos que o pino 5 vai ser do tipo LEITURA
  pinMode(ledPin, OUTPUT);// definimos que o pino 10 vai ser do tipo ESCRITA  Serial.begin(9600);

}

// a funço loop repete enquanto o arduino tiver energia.
void loop() {
  
    if (digitalRead(readPin)==HIGH){ // se a leitura do pino 5 for 1
      digitalWrite(ledPin,HIGH); // acione o pino 10 (acenda o LED)
      Serial.write(0);// escreva 0 na porta serial
    }else{ //senao
      digitalWrite(ledPin, LOW); // desacione o pino 10 (apaga o LED)
      Serial.write(1); // escreva 1 na porta serial
      //Serial.print(1);
    }
    
    delay(100); // espere 100ms. para esperar 1s use delay(1000).
  

}
