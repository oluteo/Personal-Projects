int trig = 10;
int echo = 9;
int buzzer = 2;
int red = 3;
int green = 4;
int yellow = 5;
int blue = 7;
int relay = 6;
void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  // put your main code here, to run repeatedly:
//  digitalWrite (trig, LOW);
//  delay(2);
 digitalWrite(red, HIGH);
//  digitalWrite(relay, HIGH);
  digitalWrite(trig, HIGH);
  delay(20);
  digitalWrite (trig, LOW);
  int period = pulseIn(echo, HIGH);
  int Height = (period *304)/2;
  Serial.print("Height = ");
  Serial.print(Height);
  Serial.println();

  //digitalWrite(green, HIGH);

  // if (Height <= 2 && Height >= 0 ) {
  //    digitalWrite(buzzer, LOW);
  //     digitalWrite(yellow,HIGH);
  //      digitalWrite(blue,LOW);
  //     Serial.print("this is a child");
  //     Serial.println();
  //      delay(3000);
  //
  //
  //  }
  //  else  {
  //    digitalWrite(buzzer, HIGH);
  //     digitalWrite(yellow,LOW);
  //      digitalWrite(blue,HIGH);
  //      Serial.print("this is not a child");
  //      Serial.println();
  //      delay(3000);
  //
  //  }
  //  delay(1000);
}
