#define outputA 2

volatile int counter = 0;
float numberOfSlots = 20;
float wheelDiameter = 6.6;
float distancePerTick = PI * wheelDiameter / numberOfSlots;
float distance;
void setup() {
  
  Serial.begin (115200);
  Serial.println("Starting Encoder Counts");

   attachInterrupt(digitalPinToInterrupt(2),readEncoder, CHANGE);
}
void loop() {
  distance = counter * distancePerTick;5
  Serial.println(distance);
}


  void readEncoder()
  {
    counter++;
  }
