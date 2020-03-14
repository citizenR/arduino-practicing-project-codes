/*
  1、使用Arduino采用数字引脚给SR04的Trig引脚至少10μs的高电平信号，触发SR04模块测距功能；
  2、触发后，模块会自动发送8个40KHz的超声波脉冲，并自动检测是否有信号返回。这步会由模块内部自动完成。
  3、如有信号返回，Echo引脚会输出高电平，高电平持续的时间就是超声波从发射到返回的时间。
     此时，我们能使用pulseIn()函数获取到测距的结果，并计算出距被测物的实际距离。
*/
const int TRIG = 2;
const int ECHO = 8;
int pulse = 0; // 返回脉冲间隔
int len = 0;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  delay(1000);
  digitalWrite(TRIG, LOW);
  delayMicroseconds(4);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(8);
  pulse = pulseIn(ECHO, HIGH);
  len = pulse*0.17;
  Serial.print("pulse (us): ");
  Serial.print(pulse);
  Serial.print(" us, and about(mm): ");
  Serial.println(len);
}
