int trigPin = 11;
int echoPin = 12;

int time_taken, cm, inch;

void setup() {
  Serial.begin(9600);

  // echo = recieve(input), trigger = send(output)
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

pinMode(echoPin, INPUT);
time_taken = pulseIn(echoPin, HIGH);

cm = (time_taken/2) / 29.1;
inch = (time_taken /2) / 74;

Serial.print(inch);
Serial.print("in, ");
Serial.print(cm);
Serial.print("cm");
Serial.println();

delay(5);


}
