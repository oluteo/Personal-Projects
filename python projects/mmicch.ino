int trig=9;
int echo=10;
int blue=9;
void setup() {
  // put your setup code here, to run once:
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(blue,OUTPUT);
Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(trig,HIGH);
 delay(55);
 digitalWrite(trig,LOW);
 int period =pulseIn(echo,HIGH);
 int distance = (period/2)/29.1;
 Serial.print ("distance =");
 Serial.println (distance);

 if (distance<=45 && distance>=0 ){
   digitalWrite(blue,HIGH);
}
else {
   digitalWrite(blue,LOW);
}
}
