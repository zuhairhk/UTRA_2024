#define enableA 9
#define motorA1 4
#define motorA2 5
#define enableB 10
#define motorB1 6
#define motorB2 7
#define green 3
#define red 4
#define trigPin 11
#define echoPin 12

#define leftSensor A0
#define rightSensor A1

float leftVal = 0;
float rightVal = 0;
float duration, distance;

void setup() {
  // pinMode(enableA, HIGH);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  // pinMode(enableB, HIGH);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);

  //pinMode(pinDig, INPUT);
  pinMode(leftSensor, INPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
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
//    forward();
//    delay(1000);
//    left();
//    delay(1000);
//    backward();
//    delay(1000);
//    right();
//    delay(1000);
    //  digitalWrite(green, HIGH);
    //  digitalWrite(red, HIGH);
//    digitalWrite(green, HIGH);
//    digitalWrite(red, HIGH);
  //  //
  //  //  Serial.println(digitalRead(motorA1));
  //  //  Serial.println(digitalRead(motorA2));
  //  Serial.println("zomg!");

  Serial.print("Left Val: ");
  Serial.println(leftVal);
  Serial.print("Right Val: ");
  Serial.println(rightVal);
  //  Serial.print("Digital: ");
  //  Serial.println(Dig);
  //delay(100);


  leftVal = analogRead(leftSensor);
  rightVal = analogRead(rightSensor);
  //Dig = digitalRead(pinDig);

  if (rightVal >= 250) {
    digitalWrite(red, HIGH);
  }
  if (leftVal >= 100) {
    digitalWrite(green, HIGH);
  }
  else {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
  }

//  digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
//
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//
//  duration = pulseIn(echoPin, HIGH);
//
//  distance = (duration * 0.0343) / 2; //d=s/t, 0.0343 is speed of sound. 2 because wave travles to and back.
//
//  Serial.print("Distance: ");
//  Serial.println(distance);
//  //delay(25);




}