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

//#define THRESHOLD   820
float THRESHOLD = 0;
enum State {det, fwd, left, right}
State state = det;
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

void checkAndTransition(float leftVal, float rightVal, float threshold) {
    if (leftVal <= threshold - 100 && leftVal >= threshold + 100) {
        state = left;
    } else if (rightVal <= threshold - 100 && rightVal >= threshold + 100) {
        state = right;
    } else {
        state = fwd;
    }
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
  

  leftVal = analogRead(leftSensor);
  rightVal = analogRead(rightSensor);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2;

  switch (state) {
          case det:
              delay(3000);
              THRESHOLD = (leftVal + rightVal) / 2;
              forward();
              checkAndTransition(leftVal, rightVal, THRESHOLD);
              break;

          case fwd:
              forward();
              checkAndTransition(leftVal, rightVal, THRESHOLD);
              break;

          case left:
              left();
              checkAndTransition(leftVal, rightVal, THRESHOLD);
              break;

          case right:
              right();
              checkAndTransition(leftVal, rightVal, THRESHOLD);
              break;
      }


  }
}