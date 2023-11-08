//Transmitter Code:

#include <SPI.h>
#include "RF24.h"

int x_axis = A0;
int y_axis = A1;
int xvalue;
int yvalue;
int data[2];

RF24 radio(9,10);
const uint64_t pipe=0xE8E8F0F0E1LL;

void setup() {
Serial.begin(9600);
radio.begin();
radio.openWritingPipe(pipe);
}

void loop() {{
xvalue=analogRead(x_axis);
xvalue=map(xvalue,0,1023,0,127);
data[0]=xvalue;
radio.write(data,1);

}
{
yvalue=analogRead(y_axis);
yvalue=map(yvalue,0,1023,128,255);
data[1]=yvalue;
radio.write(data,1);
}

Serial.print("x=");
Serial.println(xvalue);

Serial.print("Y=");
Serial.println(yvalue);
}
