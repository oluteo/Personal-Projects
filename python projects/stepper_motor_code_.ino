s
#include <MPU6050_tockn.h>
#include <Wire.h>
#include <Stepper.h> //stepper motor libary.....
MPU6050 mpu6050(Wire);


// Define pin connections & motor's steps per revolution................
long timer = 0;
const int dirPin = 2;
const int stepPin = 3;
const int stepsPerRevolution = 360;
int potentiometer = A0;

void setup()
{
  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  Serial.begin(9600);
}


// delay (5000);
void loop()
{
  delay(5000);
  mpu6050.update();
  if(millis() - timer > 1000){
    
    Serial.println("=======================================================");
    Serial.print("temp : ");Serial.println(mpu6050.getTemp());
    Serial.print("accX : ");Serial.print(mpu6050.getAccX());
    Serial.print("\taccY : ");Serial.print(mpu6050.getAccY());
    Serial.print("\taccZ : ");Serial.println(mpu6050.getAccZ());
  
    Serial.print("gyroX : ");Serial.print(mpu6050.getGyroX());
    Serial.print("\tgyroY : ");Serial.print(mpu6050.getGyroY());
    Serial.print("\tgyroZ : ");Serial.println(mpu6050.getGyroZ());
  
    Serial.print("accAngleX : ");Serial.print(mpu6050.getAccAngleX());
    Serial.print("\taccAngleY : ");Serial.println(mpu6050.getAccAngleY());
  
    Serial.print("gyroAngleX : ");Serial.print(mpu6050.getGyroAngleX());
    Serial.print("\tgyroAngleY : ");Serial.print(mpu6050.getGyroAngleY());
    Serial.print("\tgyroAngleZ : ");Serial.println(mpu6050.getGyroAngleZ());
    
    Serial.print("angleX : ");Serial.print(mpu6050.getAngleX());
    Serial.print("\tangleY : ");Serial.print(mpu6050.getAngleY());
    Serial.print("\tangleZ : ");Serial.println(mpu6050.getAngleZ());
    Serial.println("=======================================================\n");
    timer = millis();
    
  }


    analogWrite (potentiometer,HIGH);
    digitalWrite(dirPin, HIGH);
// Set motor direction clockwise.......
 /* if (potentiometer == HIGH){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
    
  }*/
// Set motor direction anticlockwise......
 /* if (potentiometer == LOW){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
  }*/

  // Spin motor slowly.......
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    //delay(3);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(3000);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(5000);
    //delay(1000); // Wait a second
  }
  
  
  // Set motor direction counterclockwise
  digitalWrite(dirPin, LOW);

  // Spin motor quickly
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    //delay(1000);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(5000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(5000);
    digitalWrite (stepPin,HIGH);
  }
  delay(5000); // Wait a second
}
