#include "BluetoothSerial.h"
#include <ESP32Servo.h>
#define servomotor 18

Servo servo;
BluetoothSerial bt;

void setup() {
  
  bt.begin("Rallonge");
  servo.attach(servomotor); 
  servo.write(91);
}

void loop() {
  if(bt.available()){
    char c = bt.read();
    if(c=='1'){
      servo.write(0);
      delay(1000);
      servo.write(91);
    }
    else if (c=='0') {
      servo.write(180);
      delay(1000);
      servo.write(91);
    }
  }
}
