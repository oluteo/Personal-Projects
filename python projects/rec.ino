#include <SPI.h>
#include "RF24.h"

int ena = 3;
int in1 = 4;
int  in2 = 5;
int enb = 6;
int  in3 = 7;
int  in4 = 8;

int data[2];

RF24 radio(9, 10); // CE,CSN:
const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup() {
  pinMode (ena, OUTPUT);
  pinMode (enb, OUTPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (in3, OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
}

void loop() {
  int data[1]=yvalue;
 int data[0] =  xvalue;
 
  if (radio.available()) {
    radio.read(data, 1);
    if (xvalue == 64 && yvalue == 188) {
      stopNow() ;
      Serial.println("stop");
    }
    if (xvalue > 64 && yvalue == 188) {
      moveForward();
      Serial.println("front");
    }
    if ( yvalue < 188 && xvalue == 64) {
      turnLeft();
      Serial.println("left");
    }


    if (xvalue < 64 && yvalue == 188) {
      moveBack();
      Serial.println("back");

    }

    if ( yvalue > 188  && xvalue == 64) {
      turnRight();
      Serial.println("right");
    }
    if (xvalue > 64 && yvalue < 188) {
      dioL);
      Serial.println("dioL");
    }
     if (xvalue >64 && yvalue > 188) {
      dioR();
      Serial.println("dioR");
    }
     if (xvalue <64 && yvalue < 188) {
      backL();
      Serial.println("backL");
    }
     if (xvalue < 64 && yvalue >188) {
      backR();
      Serial.println("backR");
    }
  }

}

void moveForward() {
  analogWrite(ena, 255);
  analogWrite(enb, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void stopNow() {
  analogWrite (ena, 0);
  analogWrite (enb, 0);
  digitalWrite (in1, HIGH);
  digitalWrite (in2, LOW);
  digitalWrite (in3, LOW);
  digitalWrite (in4, HIGH);
}
void moveBack() {
  analogWrite(ena, 255);
  analogWrite(enb, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void turnLeft() {
  analogWrite(ena, 255);
  analogWrite(enb, 0);
  digitalWrite(in1, HIGH);
  digitalWrite(in2,LOW );
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void turnRight() {
  analogWrite(ena, 0);
  analogWrite(enb, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void dioR() {
  analogWrite(ena, 0);
  analogWrite(enb, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay (1500);
  analogWrite(ena, 255);
  analogWrite(enb, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void dioL() {
  analogWrite(ena, 255);
  analogWrite(enb, 0);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay (1500);
  analogWrite(ena, 255);
  analogWrite(enb, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void backR() {
  analogWrite(ena, 255);
  analogWrite(enb, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay (1500);
  analogWrite(ena, 255);
  analogWrite(enb, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void backL() {
  analogWrite(ena, 0);
  analogWrite(enb, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay (1500);
  analogWrite(ena, 255);
  analogWrite(enb, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
