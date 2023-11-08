#include <MPU6050.h>
#include<Wire.h>
const int MPU6050_addr = 0x68;
int16_t GyroX, GyroY, GyroZ;
#define outputA 2

volatile int counter = 0;
float numberOfSlots = 20;
float wheelDiameter = 6.6;
float distancePerTick = PI * wheelDiameter / numberOfSlots;
float distance;
int trig = 12;
int echo = 11;
int in1 = 4;
int in2 = 5;
int ena = 6;
int enb = 9;
int in3 = 8;
int in4 = 7;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
  pinMode (echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (ena, OUTPUT);
  pinMode (enb, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
pinMode (outputA, INPUT);
Serial.println("Starting Encoder Counts");

   attachInterrupt(digitalPinToInterrupt(2),readEncoder, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite (ena, 255);
  analogWrite(enb, 255);
   int distance_moved = counter * distancePerTick;
   Serial.println(distance_moved);
  Serial.println(distance_moved);
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_addr, 14, true);
  GyroX = Wire.read() << 8 | Wire.read();
  GyroY = Wire.read() << 8 | Wire.read();
  GyroZ = Wire.read() << 8 | Wire.read();
  Serial.print(" || GyroX = "); Serial.print(GyroX);
  Serial.print(" || GyroY = "); Serial.print(GyroY);
  Serial.print(" || GyroZ = "); Serial.println(GyroZ);
  digitalWrite (trig, HIGH);
  delay(96);
  digitalWrite (trig, LOW);

  int period = pulseIn (echo, HIGH);
  int distance = (period / 2) / 29.1;
  Serial.print("time =");
  Serial.println (period);
  Serial.print("distance =");
  Serial.println (distance);
  Serial.println();

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  if (distance_moved=100){
     digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  distance_moved=0;
 
  }
  else{
     digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  }

  if (GyroZ >= 120) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  else {
    analogWrite (ena, 102);
    analogWrite(enb, 0);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }

  if (distance <= 10 && distance >= 0) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
  else {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

  }
 

}
 void readEncoder()
  {
    counter++;
  }
