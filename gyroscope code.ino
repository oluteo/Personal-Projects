#include <MPU6050_tockn.h>  //make sure you conect SDA to arduino pin A4 and SCL to pin A5
#include <Wire.h>
#include<math.h>
MPU6050 mpu6050(Wire);

float theta = 0.0000;
float angle_offset = 0.0000;

void setup() {
  // put your setup code here, to run once:
  

  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

for (int i = 0; i < 1000;i++){
        mpu6050.update();
    
    angle_offset += mpu6050.getAngleZ();
   }
   angle_offset = angle_offset/1000.00;
   Serial.println("");
   Serial.print("offset angle is: ");
   Serial.println(angle_offset);
     



}

void loop() {

Serial.print(check_angle());Serial.println(" degrees");
}

float check_angle(){
    mpu6050.update();
    float theta = 90+mpu6050.getAngleZ()-angle_offset;
    theta = radians(theta);
    float aa = int(100*theta) % 628;
    theta = aa/100;
    theta = degrees(theta);
    return theta;
}
