const int R = 13;
const int G = 12;
const int B = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(R, HIGH);
  delay(500);
  digitalWrite(G, HIGH);
  delay(500);
  digitalWrite(B, HIGH);
  delay(500);
  digitalWrite(R, LOW);
  delay(500);
  digitalWrite(G, LOW);
  delay(500);
  digitalWrite(B, LOW);
  delay(500);
}
