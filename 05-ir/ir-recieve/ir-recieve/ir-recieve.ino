#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

const int IR = 2;
decode_results results;

IRrecv irrecv(IR);  // setup ir recive pin

void setup() {
  Serial.begin(9600);
  Serial.println("***IR Sensor!***");
  irrecv.enableIRIn();
}

void loop() {
  if(irrecv.decode(&results)){
     Serial.println(results.value);
//     delay(250);
     irrecv.resume();
  }
}
