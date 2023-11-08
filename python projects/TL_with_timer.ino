int Lane1Green = A5;
int Lane1Amber = A4;
int Lane1Red = A3;
int Lane4Green = A1;
int Lane4Amber = A0;
int Lane4Red = 13;
int Lane2Green = A2;
int Lane2Amber = 6;
int Lane2Red = 7;
int Lane3Green = 8;
int Lane3Amber = 9;
int Lane3Red = 10;
long int countdown = 0;
long int starttime = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(Lane4Green, OUTPUT);
  pinMode(Lane4Amber , OUTPUT);
  pinMode(Lane4Red , OUTPUT);
  pinMode(Lane1Green , OUTPUT);
  pinMode(Lane1Amber , OUTPUT);
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
  digitalWrite(Lane1Amber , LOW);
  digitalWrite(Lane1Red , HIGH);
  digitalWrite(Lane2Green , LOW);
  digitalWrite(Lane2Amber , LOW);
  digitalWrite(Lane2Red , HIGH);
  digitalWrite(Lane3Green , LOW);
  digitalWrite(Lane3Amber , LOW);
  digitalWrite(Lane3Red , HIGH);
  delay(5000);
  starttime = millis(); 
  Serial.begin(9600);
}
 void loop() {
  //LANE 1 MOVE

 
countdown = millis()-starttime; 
  if (countdown<10000) {
    Serial.print(" Message to Lane 1");Serial.println(int((13000-countdown)/1000));
    Serial.print(" Message to Lane 2");Serial.println(int((18000-countdown)/1000));
    Serial.print(" Message to Lane 3");Serial.println(int((36000-countdown)/1000));
    Serial.print(" Message to Lane 4");Serial.println(int((54000-countdown)/1000));
    
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
  }
else if (countdown>10000 && countdown<13000) {
    Serial.print(" Message to Lane 1");Serial.println(int((13000-countdown)/1000));
    Serial.print(" Message to Lane 2");Serial.println(int((18000-countdown)/1000));
    Serial.print(" Message to Lane 3");Serial.println(int((36000-countdown)/1000));
    Serial.print(" Message to Lane 4");Serial.println(int((54000-countdown)/1000));

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

    
}


else if (countdown>13000 && countdown<18000) {
    Serial.print(" Message to Lane 1");Serial.println(int((72000-countdown)/1000));
    Serial.print(" Message to Lane 2");Serial.println(int((18000-countdown)/1000));
    Serial.print(" Message to Lane 3");Serial.println(int((36000-countdown)/1000));
    Serial.print(" Message to Lane 4");Serial.println(int((54000-countdown)/1000));

    //LANE 1 STOP LANE 2 GET READY TO MOVE
    digitalWrite(Lane1Green, LOW);
    digitalWrite(Lane1Amber , LOW);
    digitalWrite(Lane1Red , HIGH);
    digitalWrite(Lane2Green , LOW);
    digitalWrite(Lane2Amber , HIGH);
    digitalWrite(Lane2Red , HIGH);
    digitalWrite(Lane3Green , LOW);
    digitalWrite(Lane3Amber , LOW);
    digitalWrite(Lane3Red , HIGH);
    digitalWrite(Lane4Green , LOW);
    digitalWrite(Lane4Amber , LOW);
    digitalWrite(Lane4Red , HIGH);

else if (countdown>18000 && countdown<28000) {
     Serial.print(" Message to Lane 1");Serial.println(int((72000-countdown)/1000));
    Serial.print(" Message to Lane 2");Serial.println(int((18000-countdown)/1000));
    Serial.print(" Message to Lane 3");Serial.println(int((36000-countdown)/1000));
    Serial.print(" Message to Lane 4");Serial.println(int((54000-countdown)/1000));
    //LANE 2 MOVE 
    digitalWrite(Lane1Green, LOW);
    digitalWrite(Lane1Amber , LOW);
    digitalWrite(Lane1Red , HIGH);
    digitalWrite(Lane2Green , HIGH);
    digitalWrite(Lane2Amber , LOW);
    digitalWrite(Lane2Red , LOW);
    digitalWrite(Lane3Green , LOW);
    digitalWrite(Lane3Amber , LOW);
    digitalWrite(Lane3Red , HIGH);
    digitalWrite(Lane4Green , LOW);
    digitalWrite(Lane4Amber , LOW);
    digitalWrite(Lane4Red , HIGH);
}

else if (countdown>28000 && countdown<31000) {
  next code.........
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
}

else if (countdown>31000 && countdown<36000) {
  next code.........
   //LANE 2 STOP LANE 3 GET READY TO MOVE
  digitalWrite(Lane2Green, LOW);
  digitalWrite(Lane2Amber , LOW);
  digitalWrite(Lane2Red , HIGH);
  digitalWrite(Lane3Green , LOW);
  digitalWrite(Lane3Amber , HIGH);
  digitalWrite(Lane3Red , HIGH);
  digitalWrite(Lane4Green , LOW);
  digitalWrite(Lane4Amber , LOW);
  digitalWrite(Lane4Red , HIGH);
  digitalWrite(Lane1Green , LOW);
  digitalWrite(Lane1Amber , LOW);
  digitalWrite(Lane1Red , HIGH);
}

else if (countdown>36000 && countdown<46000) {
  next code.........
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
}


else if (countdown>46000 && countdown<49000) {
  next code.........
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
}

else if (countdown>49000 && countdown<54000) {
  next code.........
  //LANE 3 STOP LANE 4 GET READY TO MOVE
  digitalWrite(Lane3Green, LOW);
  digitalWrite(Lane3Amber , LOW);
  digitalWrite(Lane3Red , HIGH);
  digitalWrite(Lane4Green , LOW);
  digitalWrite(Lane4Amber , HIGH);
  digitalWrite(Lane4Red , HIGH);
  digitalWrite(Lane1Green , LOW);
  digitalWrite(Lane1Amber , LOW);
  digitalWrite(Lane1Red , HIGH);
  digitalWrite(Lane2Green , LOW);
  digitalWrite(Lane2Amber , LOW);
  digitalWrite(Lane2Red , HIGH);
}


else if (countdown>54000 && countdown<64000) {
  next code.........
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
  
}

else if (countdown>64000 && countdown<67000) {
  next code.........
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
}

else if (countdown>67000 && countdown<72000) {
  next code.........
  //LANE 4 STOP LANE 1 GET READY TO MOVE
  digitalWrite(Lane4Green, LOW);
  digitalWrite(Lane4Amber , LOW);
  digitalWrite(Lane4Red , HIGH);
  digitalWrite(Lane1Green , LOW);
  digitalWrite(Lane1Amber , HIGH);
  digitalWrite(Lane1Red , HIGH);
  digitalWrite(Lane2Green , LOW);
  digitalWrite(Lane2Amber , LOW);
  digitalWrite(Lane2Red , HIGH);
  digitalWrite(Lane3Green , LOW);
  digitalWrite(Lane3Amber , LOW);
  digitalWrite(Lane3Red , HIGH);
}

else if(countdown>=72000){
  starttime = millis(); 
}
  
  
  
  
  
  
  
  //delay(10000);
  
  delay(3000);
  //LANE 1 STOP LANE 2 GET READY TO MOVE
  digitalWrite(Lane1Green, LOW);
  digitalWrite(Lane1Amber , LOW);
  digitalWrite(Lane1Red , HIGH);
  digitalWrite(Lane2Green , LOW);
  digitalWrite(Lane2Amber , HIGH);
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
  digitalWrite(Lane3Amber , HIGH);
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
  digitalWrite(Lane4Amber , HIGH);
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
  digitalWrite(Lane1Amber , HIGH);
  digitalWrite(Lane1Red , HIGH);
  digitalWrite(Lane2Green , LOW);
  digitalWrite(Lane2Amber , LOW);
  digitalWrite(Lane2Red , HIGH);
  digitalWrite(Lane3Green , LOW);
  digitalWrite(Lane3Amber , LOW);
  digitalWrite(Lane3Red , HIGH);
  delay(5000);




}
