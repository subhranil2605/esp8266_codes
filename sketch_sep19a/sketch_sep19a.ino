void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
}

void loop() {
  digitalWrite(D0, HIGH);
  delay(100);
  digitalWrite(D0, LOW);
  delay(100);
  digitalWrite(D1, HIGH);
  delay(100);
  digitalWrite(D1, LOW);
  delay(100);
  digitalWrite(D2, HIGH);
  delay(100);
  digitalWrite(D2, LOW);
  delay(100);
}
