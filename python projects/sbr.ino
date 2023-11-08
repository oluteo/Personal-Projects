


#include <MPU6050_tockn.h>
#include <Wire.h>
#include<math.h>
MPU6050 mpu6050(Wire);
float Turning = 0.00;

#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN4 9
#define IN3 10

float signF;
float signB;

int instance = 0;
int kp = 8;
int ki = 1;
int CF;
int CB;

float theta = 0.0000;
float angle_offset = 0.0000;
float nextdrive = -90.00;
long int timer = 0;
long int starttime;
float prevError = 0;
float currentTime;
float prevTime;

void setup() {
  // put your setup code here, to run once:
  // delay(10000);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

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


  //  stop_now();


  //while(check_angle()>0.00){
  //    go_right(90);
  //   }

  // starttime = millis();
  // while(millis()-starttime<1000){
  //showxandy();
  // drive_straight(0.00);
  // }
  // stop_now();
  //delay(5000);

 // prevTime = millis();
}

void loop() {
 
 balance(90.00);
 
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

void balance(int spd1, int spd2) {
  analogWrite(ENA, abs(spd1));
  analogWrite(ENB, abs(spd2));

  if (spd1 >= 0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
  else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }

  if (spd2 >= 0) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
  else {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }

  Turning = 0.00;
}

void go_backward(int spd) {
  analogWrite(ENA, spd);
  analogWrite(ENB, spd);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Turning = 2.00;
}

void go_left(int spd) {
  analogWrite(ENA, spd);
  analogWrite(ENB, spd);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Turning = 1.00;
}

void go_right(int spd) {
  analogWrite(ENA, spd);
  analogWrite(ENB, spd);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Turning = 1.00;
}



void stop_now() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Turning = 0.00;
}


void balance(float angle_dsrd) {
  Serial.print(check_angle());Serial.println(" degrees");
  float ang = check_angle();
  float err = ang - angle_dsrd;
//  currentTime = millis();
//  float changeInTime = currentTime - prevTime;
//  prevTime = currentTime;
//  err = angle_dsrd - check_angle();
//  float errorSum =+ err * changeInTime;
  CF = 170 + kp * err ;
  CB = 170 - kp * err ;  
 Serial.print(CF);
 Serial.print("   ");
 Serial.println(CB);
  CF = constrain(CF, -190, 190);
  CB = constrain(CB, -190, 190);
  signF = float(CF / abs(CF));
  signB = float(CB / abs(CB));
  balance(CF, CB);
  //Serial.print ("Error: ");
  //Serial.println(err);
  //Serial.print ("Speeds: ");
  //Serial.print(CF);
  //Serial.print("   ");
  //Serial.println(CB);
 if (check_angle()>92&& check_angle()<88){
 stop_now();
 }
 else {
   
 }
}
