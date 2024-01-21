#define enableA 9
#define motorA1 4
#define motorA2 5
#define enableB 10
#define motorB1 6
#define motorB2 7
#define green 3
#define red 13
#define trigPin 11
#define echoPin 12

#define leftSensor A0
#define rightSensor A1

//#define THRESHOLD 470
#define THRESHOLD 820

float leftVal = 0;
float rightVal = 0;
float duration, distance;
unsigned long lastPathDetectionTime = 0;
const unsigned long TURN_AROUND_INTERVAL = 3000;

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
  left();
  // delay(5); // MAYBE CHANGE FOR TURN DISTANCE
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

  // TAKE A RIGHT TURN
  if (rightVal >= THRESHOLD && leftVal < THRESHOLD) {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    left();
    delay(10);
    while (rightVal >= THRESHOLD) {
      rightVal = analogRead(rightSensor);
      delay(10);
    }
    off();
    lastPathDetectionTime = millis();  // Update the last path detection time
  }
  // TAKE A LEFT TURN
  else if (leftVal >= THRESHOLD && rightVal < THRESHOLD) {
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    right();
    delay(10);
    while (leftVal >= THRESHOLD) {
      leftVal = analogRead(leftSensor);
      delay(10);
    }
    off();
    lastPathDetectionTime = millis();  // Update the last path detection time
  }
  // GO STRAIGHT
  else if (rightVal <= THRESHOLD && leftVal <= THRESHOLD) {
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    forward();
    lastPathDetectionTime = millis();  // Update the last path detection time

    // TURN AROUND (360) IF NO PATH DETECTED FOR MORE THAN 3 SECONDS
    if (millis() - lastPathDetectionTime >= TURN_AROUND_INTERVAL) {
      left();
      delay(1000);  // Adjust the delay based on the time needed for a 360-degree turn
      off();
      lastPathDetectionTime = millis();  // Reset the timer after the turn around
    }
  }


  //  Serial.print("Distance: ");
  //  Serial.println(distance);
  //
  //  if (distance <= 10) {
  //    put_it_in_reverse_terry();
  //  }
  //delay(25);
}
