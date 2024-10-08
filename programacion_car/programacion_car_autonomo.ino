// Definição dos pinos de saída para os dois motores e os LEDs
#define IN1 6
#define IN2 7
#define IN3 11
#define IN4 10


//Definindo pinos para o controle de velocidade dos motores
#define ENA 9
#define ENB 8

void setup() {
  Serial.begin(9600);  // inicia a porta serial, configura a taxa de dados para 9600 bps


  // Declarando os motores e os LEDs como Saídas
  pinMode(IN1, OUTPUT);
  //pinMode(led1, OUTPUT);
  //pinMode(led2, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);

  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Velocidade dos Motores, Caso esteja muito lento ou muito rápido altere os números entre 0 a 255
  analogWrite(ENA, 170);
  analogWrite(ENB, 170);
}

char cha;
void loop() {
  if (Serial.available() > 0) {
    cha = Serial.read();
    delay(2);

    // Movimenta para frente
    if (cha == 'F') {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }

    //Movimenta para trás
    if (cha == 'R') {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }

    //movimenta para direita
    if (cha == 'D') {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }

    //movimenta para esquerda
    if (cha == 'E') {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }


    //Sem movimento
    if (cha == '0') {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
  }
}
