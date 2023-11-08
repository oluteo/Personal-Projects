#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

#define outputA 2

volatile int counter = 0;
float numberOfSlots = 20;
float wheelDiameter = 6.6;
float distancePerTick = PI * wheelDiameter / numberOfSlots;
float distance ;
float ultraDistance= 0.0;
int trig = 12;
int echo = 3;
int in1 = 7;
int in2 = 8;
int ena = 5;
int ena2 = 6;
int in3 = 10;
int in4 = 9;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (ena, OUTPUT);
  pinMode (ena2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (outputA, INPUT);
  Serial.println("Starting Encoder Counts");
  
  attachInterrupt(digitalPinToInterrupt(2), readEncoder, CHANGE);  
}

void loop() {
  // put your main code here, to run repeatedly:
  // ultraDistance = getUltraDistance();
  // Serial.print("Distance: ");
  // Serial.println(ultraDistance);
  goForward();
}



void readEncoder()
   {
     counter++;
  }

float getAngle(){
  mpu6050.update();
  float angle = mpu6050.getAngleZ();
  return angle;
  }


  // digitalWrite (trig, HIGH);
  // delay(50);
  // digitalWrite (trig, LOW);
  // float period = pulseIn (echo , HIGH);
  // float distance = (period / 2) / 29.1;
  // return distance;
  // }

float getDistance(){
    int distance  = counter * distancePerTick;
    return distance;
  }


void goForward(){
  analogWrite (ena , 255);
  analogWrite (ena2 , 255);
  digitalWrite (in1, HIGH);
  digitalWrite (in2 , LOW);
  digitalWrite (in3 , HIGH);
  digitalWrite (in4 , LOW);
  }

void goBackward(){
   analogWrite (ena , 255);
  analogWrite (ena2 , 255);
  digitalWrite (in1, LOW);
  digitalWrite (in2 , HIGH);
  digitalWrite (in3 , LOW);
  digitalWrite (in4 , HIGH);
  }

void Stop(){
    analogWrite (ena , 0);
  analogWrite (ena2 , 0);
  digitalWrite (in1, LOW);
  digitalWrite (in2 , LOW);
  digitalWrite (in3 , LOW);
  digitalWrite (in4 , LOW);
  }

void turnRight(){
    digitalWrite (in1 , HIGH);
    analogWrite (ena , 255);
    digitalWrite (in2 , LOW);
    analogWrite (ena2 , 255);
    digitalWrite (in3 , LOW);
    digitalWrite (in4 , LOW);
  }

void turnLeft(){
    digitalWrite (in1 , LOW);
    analogWrite (ena , 255);
    digitalWrite (in2 , LOW);
    analogWrite (ena2 , 255);
    digitalWrite (in3 , HIGH);
    digitalWrite (in4 , LOW);
  }
