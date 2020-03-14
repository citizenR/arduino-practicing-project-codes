const int BUZZ = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 1; i < 10; i++){
     digitalWrite(BUZZ, HIGH);
     delay(100);
     digitalWrite(BUZZ, LOW);
     delay(i*100);
  }
}
