
#include <MPU6050_tockn.h>  //make sure you conect SDA to arduino pin A4 and SCL to pin A5
#include <Wire.h>
#include<math.h>
MPU6050 mpu6050(Wire);

float theta = 0.0000,angle_offset = 0.0000;
int leftside_in1 =7, leftside_in2 =8 , rightside_in3 =9, rightside_in4 =10, ena =5 , enb = 6; 

void setup() {
  // put your setup code here, to run once:
pinMode (ena, OUTPUT);
  pinMode (enb, OUTPUT);
  pinMode (leftside_in1, OUTPUT);
  pinMode (leftside_in2, OUTPUT);
  pinMode (rightside_in3, OUTPUT);
  pinMode (rightside_in4, OUTPUT);
  Serial.begin(9600);
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
correct();
delayMicroseconds(1000);
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

void correct(){
  if (check_angle() > 93) {
    analogWrite(ena, 200);
    analogWrite(enb, 0);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else if(check_angle()<87){
    analogWrite(ena, 0);
    analogWrite(enb, 200);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else {
    analogWrite(ena, 255);
    analogWrite(enb, 255);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  
  
  
  }
