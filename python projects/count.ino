#include <Servo.h>
Servo Servo1;

void setup() {
  // put your setup code here, to run once:
 Servo1.attach(9);
 Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
for (int i=0 ;i<100 ;i++){
   Servo1.write(0);
   delay(500);
   Servo1.write(80);
   delay (500);
   Serial.println(i);
}
delay (1000);

}
