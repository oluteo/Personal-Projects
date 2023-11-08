int Lane4Green = 0;
int Lane4Amber = 1;
int Lane4Red = 2;
int Lane1Green = 3;
int Lane1Amber = 4;
int Lane1Red = 5;
int Lane2Green = 6;
int Lane2Amber = 7;
int Lane2Red = 8;
int Lane3Green = 9;
int Lane3Amber = 10;
int Lane3Red = 11;



void setup() {
  // put your setup code here, to run once:
pinMode(Lane4Green, OUTPUT);
pinMode(Lane4Amber , OUTPUT);
pinMode(Lane4Red , OUTPUT);
pinMode(Lane1Green , OUTPUT);
pinMode(Lane1Amber ,OUTPUT);
pinMode(Lane1Red , OUTPUT);
pinMode(Lane2Green , OUTPUT);
pinMode(Lane2Amber , OUTPUT);
pinMode(Lane2Red , OUTPUT);
pinMode(Lane3Green , OUTPUT);
pinMode(Lane3Amber , OUTPUT);
pinMode(Lane3Red , OUTPUT);




//let every lane stop
digitalWrite(Lane4Green, LOW);
digitalWrite(Lane4Amber , LOW);
digitalWrite(Lane4Red , HIGH);
digitalWrite(Lane1Green , LOW);
digitalWrite(Lane1Amber ,LOW);
digitalWrite(Lane1Red , HIGH);
digitalWrite(Lane2Green , LOW);
digitalWrite(Lane2Amber , LOW);
digitalWrite(Lane2Red , HIGH);
digitalWrite(Lane3Green , LOW);
digitalWrite(Lane3Amber , LOW);
digitalWrite(Lane3Red , HIGH);
delay(5000);

}
Void loop(){
//LANE 1 MOVE
digitalWrite(Lane1Green, HIGH);
digitalWrite(Lane1Amber , LOW);
digitalWrite(Lane1Red , LOW);
digitalWrite(Lane2Green , LOW);
digitalWrite(Lane2Amber , LOW);
digitalWrite(Lane2Red , HIGH);
digitalWrite(Lane3Green , LOW);
digitalWrite(Lane3Amber , LOW);
digitalWrite(Lane3Red , HIGH);
digitalWrite(Lane4Green , LOW);
digitalWrite(Lane4Amber , LOW);
digitalWrite(Lane4Red , HIGH);
delay(10000);
//LANE 1 GET READY TO STOP
digitalWrite(Lane1Green, LOW);
digitalWrite(Lane1Amber , HIGH);
digitalWrite(Lane1Red , LOW);
digitalWrite(Lane2Green , LOW);
digitalWrite(Lane2Amber , LOW);
digitalWrite(Lane2Red , HIGH);
digitalWrite(Lane3Green , LOW);
digitalWrite(Lane3Amber , LOW);
digitalWrite(Lane3Red , HIGH);
digitalWrite(Lane4Green , LOW);
digitalWrite(Lane4Amber , LOW);
digitalWrite(Lane4Red , HIGH);
delay(3000);
//LANE 1 STOP LANE 2 GET READY TO MOVE
digitalWrite(Lane1Green, LOW);
digitalWrite(Lane1Amber , LOW);
digitalWrite(Lane1Red , HIGH);
digitalWrite(Lane2Green , LOW);
digitalWrite(Lane2Amber ,HIGH);
digitalWrite(Lane2Red , HIGH);
digitalWrite(Lane3Green , LOW);
digitalWrite(Lane3Amber , LOW);
digitalWrite(Lane3Red , HIGH);
digitalWrite(Lane4Green , LOW);
digitalWrite(Lane4Amber , LOW);
digitalWrite(Lane4Red , HIGH);
delay(5000);








//LANE 2 MOVE
digitalWrite(Lane2Green, HIGH);
digitalWrite(Lane2Amber , LOW);
digitalWrite(Lane2Red , LOW);
digitalWrite(Lane3Green , LOW);
digitalWrite(Lane3Amber , LOW);
digitalWrite(Lane3Red , HIGH);
digitalWrite(Lane4Green , LOW);
digitalWrite(Lane4Amber , LOW);
digitalWrite(Lane4Red , HIGH);
digitalWrite(Lane1Green , LOW);
digitalWrite(Lane1Amber , LOW);
digitalWrite(Lane1Red , HIGH);
delay(10000);
//LANE 2 GET READY TO STOP
digitalWrite(Lane2Green, LOW);
digitalWrite(Lane2Amber , HIGH);
digitalWrite(Lane2Red , LOW);
digitalWrite(Lane3Green , LOW);
digitalWrite(Lane3Amber , LOW);
digitalWrite(Lane3Red , HIGH);
digitalWrite(Lane4Green , LOW);
digitalWrite(Lane4Amber , LOW);
digitalWrite(Lane4Red , HIGH);
digitalWrite(Lane1Green , LOW);
digitalWrite(Lane1Amber , LOW);
digitalWrite(Lane1Red , HIGH);
delay(3000);
//LANE 2 STOP LANE 3 GET READY TO MOVE
digitalWrite(Lane2Green, LOW);
digitalWrite(Lane2Amber , LOW);
digitalWrite(Lane2Red , HIGH);
digitalWrite(Lane3Green , LOW);
digitalWrite(Lane3Amber ,HIGH);
digitalWrite(Lane3Red , HIGH);
digitalWrite(Lane4Green , LOW);
digitalWrite(Lane4Amber , LOW);
digitalWrite(Lane4Red , HIGH);
digitalWrite(Lane1Green , LOW);
digitalWrite(Lane1Amber , LOW);
digitalWrite(Lane1Red , HIGH);
delay(5000);


//LANE 3 MOVE
digitalWrite(Lane3Green, HIGH);
digitalWrite(Lane3Amber , LOW);
digitalWrite(Lane3Red , LOW);
digitalWrite(Lane4Green , LOW);
digitalWrite(Lane4Amber , LOW);
digitalWrite(Lane4Red , HIGH);
digitalWrite(Lane1Green , LOW);
digitalWrite(Lane1Amber , LOW);
digitalWrite(Lane1Red , HIGH);
digitalWrite(Lane2Green , LOW);
digitalWrite(Lane2Amber , LOW);
digitalWrite(Lane2Red , HIGH);
delay(10000);
//LANE 3 GET READY TO STOP
digitalWrite(Lane3Green, LOW);
digitalWrite(Lane3Amber , HIGH);
digitalWrite(Lane3Red , LOW);
digitalWrite(Lane4Green , LOW);
digitalWrite(Lane4Amber , LOW);
digitalWrite(Lane4Red , HIGH);
digitalWrite(Lane1Green , LOW);
digitalWrite(Lane1Amber , LOW);
digitalWrite(Lane1Red , HIGH);
digitalWrite(Lane2Green , LOW);
digitalWrite(Lane2Amber , LOW);
digitalWrite(Lane2Red , HIGH);
delay(3000);
//LANE 3 STOP LANE 4 GET READY TO MOVE
digitalWrite(Lane3Green, LOW);
digitalWrite(Lane3Amber , LOW);
digitalWrite(Lane3Red , HIGH);
digitalWrite(Lane4Green , LOW);
digitalWrite(Lane4Amber ,HIGH);
digitalWrite(Lane4Red , HIGH);
digitalWrite(Lane1Green , LOW);
digitalWrite(Lane1Amber , LOW);
digitalWrite(Lane1Red , HIGH);
digitalWrite(Lane2Green , LOW);
digitalWrite(Lane2Amber , LOW);
digitalWrite(Lane2Red , HIGH);
delay(5000);


//LANE 4 MOVE
digitalWrite(Lane4Green, HIGH);
digitalWrite(Lane4Amber , LOW);
digitalWrite(Lane4Red , LOW);
digitalWrite(Lane1Green , LOW);
digitalWrite(Lane1Amber , LOW);
digitalWrite(Lane1Red , HIGH);
digitalWrite(Lane2Green , LOW);
digitalWrite(Lane2Amber , LOW);
digitalWrite(Lane2Red , HIGH);
digitalWrite(Lane3Green , LOW);
digitalWrite(Lane3Amber , LOW);
digitalWrite(Lane3Red , HIGH);
delay(10000);
//LANE 4 GET READY TO STOP
digitalWrite(Lane4Green, LOW);
digitalWrite(Lane4Amber , HIGH);
digitalWrite(Lane4Red , LOW);
digitalWrite(Lane1Green , LOW);
digitalWrite(Lane1Amber , LOW);
digitalWrite(Lane1Red , HIGH);
digitalWrite(Lane2Green , LOW);
digitalWrite(Lane2Amber , LOW);
digitalWrite(Lane2Red , HIGH);
digitalWrite(Lane3Green , LOW);
digitalWrite(Lane3Amber , LOW);
digitalWrite(Lane3Red , HIGH);
delay(3000);
//LANE 4 STOP LANE 1 GET READY TO MOVE
digitalWrite(Lane4Green, LOW);
digitalWrite(Lane4Amber , LOW);
digitalWrite(Lane4Red , HIGH);
digitalWrite(Lane1Green , LOW);
digitalWrite(Lane1Amber ,HIGH);
digitalWrite(Lane1Red , HIGH);
digitalWrite(Lane2Green , LOW);
digitalWrite(Lane2Amber , LOW);
digitalWrite(Lane2Red , HIGH);
digitalWrite(Lane3Green , LOW);
digitalWrite(Lane3Amber , LOW);
digitalWrite(Lane3Red , HIGH);
delay(5000);




} 
