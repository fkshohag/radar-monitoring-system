int trigPin = 8, echoPin = 9, buzzer = 7;
float distance, duration;
Servo myServo;
int pos;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void runRadar() {
  myServo.write(i);
  delay(100);
  distance = calculateDistance();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.setCursor(6, 0);
  lcd.print(i);

  // lcd.print
  lcd.setCursor(",");
  lcd.print("deg");
  lcd.setCursor(0, 1);
  lcd.print("Distance=");
  lcd.setCursor(9 ,1);
  lcd.print(distance);
  lcd.setCursor(13, 1);
  lcd.print("cm");
}

int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2;

  if (distance < 10) {
    tone(buzzer, 1000);
    delay(200);
    noTone(buzzer);
  }
  return distance;
}

void loop() {
  for (pos = 0; pos <= 180; pos++){
    servo.write(pos);
    delay(20);
    runRadar();
  }
  delay(1000);
  
  for (pos = 180; pos >= 90; pos--) {
    servo.write(pos);
    delay(20);
    runRadar();
  }
  delay(10000);
  
  for (pos = 90; pos <= 180; pos++) {
    servo.write(pos);
    delay(20);
    runRadar();
  }
  delay(1000);
}
