#include <MPU6050_tockn.h>
#include <Wire.h>
#include<math.h>
MPU6050 mpu6050(Wire);


int trig = 8;
int echo = 7;
int ena = 10;
int in1 = 3;
int in2 = 4;
int enb = 9;
int in3 = 5;
int in4 = 6;
float theta = 0.0000;
float angle_offset = 0.0000;
float degree = 0.f;
volatile float stepsmoved = 0.f ;
float distance = 0.f;
void setup() {
  // put your setup code here, to run once:
  pinMode (echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode (ena, OUTPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (enb, OUTPUT);



  attachInterrupt(digitalPinToInterrupt(2), countsteps, CHANGE);
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  for (int i = 0; i < 1000; i++) {
    mpu6050.update();

    angle_offset += mpu6050.getAngleZ();
  }
  angle_offset = angle_offset / 1000.00;
  Serial.println("");
  Serial.print("offset angle is: ");
  Serial.println(angle_offset);

}

void loop() {
  // put your main code here, to run repeatedly:
  degree = check_angle();
  Serial.print(" degrees =");
  Serial.print( degree);

  distance = getDistance();
  Serial.print("distance =");
  Serial.print(distance);
  Serial.println();

  Serial.print("stepsmoved = ");
  Serial.println (stepsmoved);

  if ( stepsmoved < 200) {
    goForward ();
  }
  else {
    turnLeft ();
  
  if (degree > 120 && degree <122) {
  stopNow();
    stepsmoved = 0;
  }
  else {
     turnLeft();
}
//  if (degree > 240 && degree < 242) {
//    delay (000);
//    stopNow();
//    stepsmoved = 0;
//  }
//  else {
//    turnLeft();
//  }
//  //stopNow ();
//  //delay (1000);
//  if (degree = 360 ) {
//    delay (000);
//    stopNow();
//    stepsmoved = 0;
//  }
//  else {
//    turnLeft();
// }
 }
//
//  if (distance <= 10 && distance >= 0) {
//    stopNow();
//  }
//  else {
//    goForward();
//  }

}
void hggcvkhbu() {
  delay(1000);
  stopNow();
  delay(1000);

  float startangle = check_angle();

  while (check_angle() - startangle < 120) {
    turnLeft();
  }
  stopNow();
  delay(100);
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  delay(1000);
}



void goForward() {
  analogWrite(ena, 255);
  analogWrite(enb, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void countsteps() {
  stepsmoved += 1;

}

void stopNow() {
  analogWrite (ena, 0);
  analogWrite (enb, 0);
  digitalWrite (in1, LOW);
  digitalWrite (in2, LOW);
  digitalWrite (in3, LOW);
  digitalWrite (in4, LOW);
}

void turnLeft() {
  analogWrite (ena, 0);
  analogWrite (enb, 124);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

float check_angle() {
  mpu6050.update();
  float theta = 90 + mpu6050.getAngleZ() - angle_offset;
  theta = radians(theta);
  float aa = int(100 * theta) % 628;
  theta = aa / 100;
  theta = degrees(theta);
  return theta;
}

float getDistance() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  float period = pulseIn(echo, HIGH);
  float distance = (period / 2) / 29.1;
  return distance;
}
