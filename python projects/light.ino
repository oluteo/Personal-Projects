int red = 3 ;
int yellow =4 ;
int green = 5;
// int means integer
// connect pins on the arduino board to their set colours
void setup() {
  // put your setup code here, to run once:
pinMode (red,OUTPUT);
pinMode (yellow,OUTPUT);
pinMode (green,OUTPUT);
//pinMode is used to set the pin on the arduino board
//we use OUTPUT because we want to send out signal
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(red,HIGH);
digitalWrite(yellow,LOW);
digitalWrite(green,LOW);
delay(1000);
// only the red light is on
digitalWrite(red,HIGH);
digitalWrite(yellow,HIGH);
digitalWrite(green,LOW);
delay(1000);
// only the red and yellow lights are on
digitalWrite(red,HIGH);
digitalWrite(yellow,HIGH);
digitalWrite(green,HIGH);
delay(1000);
// all lights are on
digitalWrite(red,LOW);
digitalWrite(yellow,HIGH);
digitalWrite(green,HIGH);
delay(1000);
// only the yellow and green lights are on
digitalWrite(red,LOW);
digitalWrite(yellow,LOW);
digitalWrite(green,HIGH);
delay(1000);
// only the green light is on
digitalWrite(red,LOW);
digitalWrite(yellow,HIGH);
digitalWrite(green,LOW);
delay(1000);
// only the yellow light is on
digitalWrite(red,HIGH);
digitalWrite(yellow,LOW);
digitalWrite(green,HIGH);
delay(1000);
// only the red and green lights are on
digitalWrite(red,LOW);
digitalWrite(yellow,LOW);
digitalWrite(green,LOW);
delay(1000);
//all lights are off
}
//we use delay(1000)to stop for 1 second because c++ counts in microseconds
