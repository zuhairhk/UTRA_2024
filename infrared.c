#define pinDig 8
#define pinAnlg A0
#define green 7
#define red 6

float Anlg = 0;
int Dig = 0;
void setup() {
  // put your setup code here, to run once:

  pinMode(pinDig, INPUT);
  pinMode(pinAnlg, INPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Analog: ");
  Serial.println(Anlg);
  Serial.print("Digital: ");
  Serial.println(Dig);
  delay(300);

  
  Anlg = analogRead(pinAnlg);
  Dig = digitalRead(pinDig);

  if(Anlg >= 100){
      digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
  }
  else {
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
  }


}