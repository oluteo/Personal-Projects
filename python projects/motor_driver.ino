int ena = 5;
int in1 = 7;
int in2 = 8;
int enb = 6;
int in3 = 9;
int in4 = 10;
void setup() {
  // put your setup code here, to run once:
pinMode(ena,OUTPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(enb,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
//digitalWrite(in1,LOW);
//digitalWrite(in2,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(ena,255);
analogWrite(enb,255);
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);

//for(int i =0; i<256; i++){
//analogWrite(ena,i);
//delay(500);
//}
}
