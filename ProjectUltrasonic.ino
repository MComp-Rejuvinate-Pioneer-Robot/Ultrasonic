#include <time.h>

enum Pins {SelectA = 22, SelectB = 23, SelectC = 24, INIT = 26, ECHO = 27};

class Ultrasonic {
    //Attributes
  private:
    //Functions
  private:
    void setSelectorPins(int selector);
  public:
    float pulse(int selector);
};

void Ultrasonic::setSelectorPins(int selector){
  if (selector >= 4){
    digitalWrite(SelectC, HIGH);
    selector -= 4;
  } else {
    digitalWrite(SelectC, LOW);
  }
  if (selector >= 2){
    digitalWrite(SelectB, HIGH);
    selector -= 2;
  } else {
    digitalWrite(SelectB, LOW);
  }
  if (selector >= 1){
    digitalWrite(SelectA, HIGH);
    selector -= 1;
  } else {
    digitalWrite(SelectA, LOW);
  }
}

float Ultrasonic::pulse(int selector) {
  setSelectorPins(selector);
  int startTime = 0;
  digitalWrite(INIT, HIGH);
  float duration = pulseIn(ECHO, HIGH);
  float distance = duration * 0.034 / 2;
  digitalWrite(INIT, LOW);
  return distance;
}

Ultrasonic ultrasonic;

void setup() {
  pinMode(SelectA, OUTPUT);
  pinMode(SelectB, OUTPUT);
  pinMode(SelectC, OUTPUT);
  pinMode(INIT, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}

void loop() {
  float output = 0;
  for (int i = 0; i < 8; i++) {
    output = ultrasonic.pulse(i);
    Serial.println(output);
  }
  delay(3000);
}
