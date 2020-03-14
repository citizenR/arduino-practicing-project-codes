const int R = A0;
const int G = A2;
const int B = A4;

int bR = 0xFF,
    bG = 0x3E,
    bB = 0x1B;

void light(const int r, const int g, const int b, int br, int bg, int bb) {
  analogWrite(r, br);
  analogWrite(g, bg);
  analogWrite(b, bb);
}

int change(int brightness, int delta) {
  // change the brightness
  int t = brightness + delta;
  if (t < 0) {
    t += 255;
  } else if (t >= 255) {
    t -= 255;
  }
  return t;
}

void setup() {
  // setup RGB LED
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  // start led
  light(R, G, B, bR, bG, bB);
}

void loop() {
  //
  bR = change(bR, 3);
  bG = change(bG, 4);
  bB = change(bB, 5);
  light(R, G, B, bR, bG, bB);
  delay(100);
//  light(R, G, B, 0, 0, 0);
//  delay(1500);
}
