#define enableA 9
#define motorA1 4
#define motorA2 5
#define enableB 10
#define motorB1 6
#define motorB2 7
#define green_led 3
#define red_led 4

void setup() {
  // pinMode(enableA, HIGH);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  // pinMode(enableB, HIGH);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  Serial.begin(9600);

}

void forward() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void backward() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}


void left() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void right() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void off() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}

void loop() {
  // digitalWrite(enableA, HIGH);
  forward();
  delay(1000);
  left();
  delay(1000);
  backward();
  delay(1000);
  right();
  delay(1000);
  //  digitalWrite(green, HIGH);
  //  digitalWrite(red, HIGH);
  digitalWrite(green_led, HIGH);
  digitalWrite(red_led, HIGH);
  //
  //  Serial.println(digitalRead(motorA1));
  //  Serial.println(digitalRead(motorA2));
  Serial.println("zomg!");


}