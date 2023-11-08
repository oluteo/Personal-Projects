#include <MPU6050_tockn.h>  //make sure you conect SDA to arduino pin A4 and SCL to pin A5
#include <Wire.h>
#include<math.h>
MPU6050 mpu6050(Wire);

float theta = 0.0000;
float angle_offset = 0.0000;
int ena = 5;
int in1 = 7;
int in2 = 8;
int enb = 6;
int in3 = 9;
int in4 = 10;
int data = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode (ena, OUTPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (enb, OUTPUT);
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
  correct ();
  // ctrl ();
  Serial.print(check_angle()); Serial.println(" degrees");
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
void correct () {
  if (check_angle() < 85) {
    analogWrite(ena, 0);
    analogWrite(enb, 200);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else if (check_angle() > 91) {
    analogWrite(ena, 200);
    analogWrite(enb, 0);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
  else {
    analogWrite(ena, 200);
    analogWrite(enb, 200);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }

}
//void ctrl (){
//if (check_angle() > 91) {
//  analogWrite(ena, 200);
//  analogWrite(enb, 0);
//  digitalWrite(in1, HIGH);
//  digitalWrite(in2, LOW);
//  digitalWrite(in3, LOW);
//  digitalWrite(in4, LOW);
//}
//else {
//  analogWrite(ena, 200);
//  analogWrite(enb, 200);
//  digitalWrite(in1, HIGH);
//  digitalWrite(in2, LOW);
//  digitalWrite(in3, HIGH);
//  digitalWrite(in4, LOW);
//}
//}
