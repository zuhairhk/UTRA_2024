#define trigPin 9
#define echoPin 10
#define red 7
#define green 6

float duration, distance;


void setup() {
  // put your setup code here, to run once:

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration * 0.0343) / 2; //d=s/t, 0.0343 is speed of sound. 2 because wave travles to and back.

  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);



  if (distance >= 10) {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
  }
  else {
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
  }



}