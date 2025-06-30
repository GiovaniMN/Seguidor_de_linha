
const int sensorEsq = A4;
const int sensorCentro = A2;
const int sensorDir = A0;
#define motorEsq 10
#define motorDir 11

void setup() {
  pinMode(sensorEsq, INPUT);
  pinMode(sensorDir, INPUT);
  pinMode(sensorCentro, INPUT);
  pinMode(motorEsq, OUTPUT);
  pinMode(motorDir, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int vEsq = digitalRead(sensorEsq);
  int vCen = digitalRead(sensorCentro);
  int vDir = digitalRead(sensorDir);

  if(vEsq == 1 && vCen == 0 && vDir == 1){
    reto();
  }
  else if(vEsq == vCen && vCen == vDir){
    parar();
  }
  else if(vEsq == 0 && vDir == 1) {
    esquerda();
  }
  else if(vDir == 0 && vEsq == 1){
    direita();
  }
}

void reto(){
  analogWrite(motorEsq, 200);
  analogWrite(motorDir, 200);
}

void parar(){
  analogWrite(motorEsq, 0);
  analogWrite(motorDir, 0);
}

void esquerda(){
  analogWrite(motorEsq, 0);
  analogWrite(motorDir, 200);
}

void direita(){
  analogWrite(motorEsq, 200);
  analogWrite(motorDir, 0);
}
