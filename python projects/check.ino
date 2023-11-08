#include <math.h>

float deg2rad = 180 / PI;
float THETA1 = 90 ;
float THETA2 = 90;
float L1 = 40;
float L2 = 40;
float x;
float y;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  x = L1 * cos(deg2rad*(THETA1)) - L2 * cos(deg2rad*(THETA1 + THETA2));

  y = L1 * sin(deg2rad*(THETA1)) - L2 * sin(deg2rad*(THETA1 + THETA2));
Serial.print ("x=");
Serial.print(x);
Serial.print("||");
Serial.print("y=");
Serial.println(y);
delay (2000);
}
