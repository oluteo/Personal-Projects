int rr =150;
int frog = 9;
void setup() {
  // put your setup code here, to run once:
pinMode(frog,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for (int yy=0; yy<190; yy++){
   analogWrite(frog,yy);
   delay(100);
}
delay(1000);
for (rr >0;--rr;){
   analogWrite(frog,rr);
   delay(22);
}
delay(1000);
}
