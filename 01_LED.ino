#define R 8
#define O 9
#define G 10

void setup() {
  pinMode(R, OUTPUT);
  pinMode(O, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop() {
  digitalWrite(R, HIGH);
  digitalWrite(O, LOW);
  digitalWrite(G, HIGH);
  delay(250);
  digitalWrite(R, LOW);
  digitalWrite(O, HIGH);
  digitalWrite(G, LOW);
  delay(250);
}
