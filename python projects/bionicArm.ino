#include <Servo.h>
int thumb = 3;
int index = 5;
int middle = 6;
int ring = 9;
int pinky = 10;
int wrist = 11;
int emg = A0;
int CL =0;
float err;
Servo Servo1, Servo2, Servo3, Servo4, Servo5, Servo6 ;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  (emg,INPUT);
  Servo1.attach(thumb);
  Servo2.attach(index);
  Servo3.attach(middle);
  Servo4.attach(ring);
  Servo5.attach(pinky);
  Servo6.attach(wrist);

//  Servo1.write(180);
//  Servo5.write(180);
//  Servo2.write(180);
//  Servo3.write(180);
//  Servo4.write(180);
//  delay (3000);
   err = analogRead(emg);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Servo3.write(0);
//  Servo6.write(180);
//  delay (1000);
//  Servo6.write(0);
//float sensorValue = analogRead(emg);
//Serial.println(sensorValue);
//   if(sensorValue > 600){
//     if( CL== 2){
//         openArm();
//        delay(2000);
//       CL =1;
//      }
//
//      else{
//        closeArm();
//        delay(2000);
//       CL =2;
//      }
//  }
//  else{
//    
//  }
//  
 // if(sensorValue > 590){
//    closeArm();
//  }
//  
//    if(sensorValue > 500&&sensorValue < 550){
//   fcku();
//  }
//  
//  else {
//    openArm();
//  }
  delay(100); 
  delay (1000);
  closeArm();
  delay (2000);
  one();
  delay (1000);
  two();
  delay (1000);
  three();
  delay (900);
  four();
  delay (900);
  openArm();
  delay (2000);
}

void openArm() {
  Servo1.write(180);
  Servo2.write(180);
  Servo3.write(180);
  Servo4.write(180);
  Servo5.write(180);
}
void closeArm() {
  Servo1.write(0);
  Servo2.write(0);
  Servo3.write(0);
  Servo4.write(0);
  Servo5.write(0);
}
void gun() {
  Servo1.write(120);
  Servo2.write(120);
  Servo3.write(0);
  Servo4.write(0);
  Servo5.write(0);
}
void pointing() {
  Servo1.write(90);
  Servo2.write(180);
  Servo3.write(0);
  Servo4.write(0);
  Servo5.write(0);
}
void directing() {
  Servo1.write(0);
  Servo2.write(150);
  Servo3.write(0);
  Servo4.write(0);
  Servo5.write(0);
}
void phone() {
  for (int angle = 180; angle < 39; angle = -10 ) {
    Servo1.write(45);
    Servo2.write(40);
    Servo3.write(40);
    Servo4.write(40);
    Servo5.write(40);
  }
}
void four() {
  Servo1.write(0);
  Servo2.write(180);
  Servo3.write(180);
  Servo4.write(180);
  Servo5.write(180);
}
void three() {
  Servo1.write(0);
  Servo2.write(180);
  Servo3.write(180);
  Servo4.write(180);
  Servo5.write(0);
}
void two() {
  Servo1.write(170);
  delay (500);
  Servo2.write(180);
  Servo3.write(180);
  delay (500);
  Servo1.write(0);
  Servo4.write(0);
  Servo5.write(0);
}
void one() {
  Servo1.write(170);
  delay (500);
  Servo2.write(180);
  delay (500);
  Servo1.write(0);
  Servo3.write(0);
  Servo4.write(0);
  Servo5.write(0);
}
void spman() {
  Servo1.write(180);
  Servo2.write(180);
  Servo3.write(0);
  Servo4.write(0);
  Servo5.write(180);
}
void fcku() {
  Servo1.write(0);
  Servo2.write(0);
  Servo3.write(175);
  Servo4.write(0);
  Servo5.write(0);
}
void ok() {
  Servo1.write(10);
  Servo2.write(10);
  Servo3.write(80);
  Servo4.write(90);
  Servo5.write(100);
}
