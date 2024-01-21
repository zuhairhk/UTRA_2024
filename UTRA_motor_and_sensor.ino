#define enableA     9
#define motorA1     4
#define motorA2     5
#define enableB     10
#define motorB1     6
#define motorB2     7
#define green       3
#define red         13
#define trigPin     11
#define echoPin     12

#define leftSensor  A0
#define rightSensor A1

#define THRESHOLD   820

float leftVal = 0;
float rightVal = 0;
float duration, distance;

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);

  pinMode(leftSensor, INPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void forward() {
  off();
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void backward() {
  off();
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}


void left() {
  off();
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void right() {
  off();
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

// check all degrees and then take the shortest path
// put movements in a stack pop off then go in reverse
void put_it_in_reverse_terry() {
  off();
  right();      // initiate the left turn
  delay(850);  // adjust this delay to make a 180-degree turn (in milliseconds)
  off();       // stop turning
}

void loop() {
  // Serial.print("Left Val: ");
  // Serial.println(leftVal);
  // Serial.print("Right Val: ");
  // Serial.println(rightVal);

  leftVal = analogRead(leftSensor);
  rightVal = analogRead(rightSensor);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2;

  // GO STRAIGHT
  if (rightVal <= THRESHOLD && leftVal <= THRESHOLD) {
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    forward();
  }
  // TAKE A RIGHT TURN
  else if (rightVal >= THRESHOLD && leftVal < THRESHOLD) {
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    left();
    delay(10);
    while (rightVal >= THRESHOLD) {
      rightVal = analogRead(rightSensor);
      delay(10);
    }
  }
  // TAKE A LEFT TURN
  else if (leftVal >= THRESHOLD && rightVal < THRESHOLD) {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    right();
    delay(10);
    while (leftVal >= THRESHOLD) {
      leftVal = analogRead(leftSensor);
      delay(10);
    }
  }

  if (distance <= 10) {
    put_it_in_reverse_terry();
  }
}