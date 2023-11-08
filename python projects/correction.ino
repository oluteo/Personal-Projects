//#include <MPU6050_tockn.h>  //make sure you conect SDA to arduino pin A4 and SCL to pin A5
//#include <Wire.h>
//#include<math.h>
//MPU6050 mpu6050(Wire);

int IN1 = 3;
int IN2 = 4;
int ENA = 10;
int ENB = 9;
int IN3 = 5;
int IN4 = 6;
//volatile float stepsmoved = 0.f;
//float theta = 0.0000;
//float angle_offset = 0.0000;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
//  Wire.begin();
//  mpu6050.begin();
//  mpu6050.calcGyroOffsets(true);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

//  attachInterrupt(digitalPinToInterrupt(2), countsteps, CHANGE);
//
//  for (int i = 0; i < 1000; i++) {
//    mpu6050.update();
//
//    angle_offset += mpu6050.getAngleZ();
//  }
//  angle_offset = angle_offset / 1000.00;
//  Serial.println("");
//  Serial.print("offset angle is: ");
//  Serial.println(angle_offset);



}

void loop() {
  // put your main code here, to run repeatedly:
 //
//Serial.print(check_angle());Serial.println(" degrees");

//goForward();
//delay(1000);
//stopNow();
//delay(1000);
//float startangle = check_angle();
//while (check_angle()-startangle < 120){
//  turnLeft();
  goForward();
//}
 //stopNow();
 // delay(1000);
}
void goForward() {
  analogWrite (ENA, 255);
  analogWrite (ENB, 255);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
}
//void countsteps() {
//  stepsmoved += 1;
//
//
//}
//void stopNow() {
//  analogWrite (ENA, 0);
//  analogWrite (ENB, 0);
//  digitalWrite (IN1, HIGH);
//  digitalWrite (IN2, LOW);
//  digitalWrite (IN3, LOW);
//  digitalWrite (IN4, HIGH);
//}
//void turnLeft() {
//  analogWrite (ENA, 179 );
//  analogWrite (ENB, 0);
//  digitalWrite (IN1, HIGH);
//  digitalWrite (IN2, LOW);
//  digitalWrite (IN3, LOW);
//  digitalWrite (IN4, LOW);
//}
//float check_angle(){
//    mpu6050.update();
//    float theta = 90+mpu6050.getAngleZ()-angle_offset;
//    theta = radians(theta);
//    float aa = int(100*theta) % 628;
//    theta = aa/100;
//    theta = degrees(theta);
//    return theta;
//}
