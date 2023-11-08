#include <SPI.h>
#include <MFRC522.h>


#define SS_PIN 10
#define RST_PIN 9
#define BUZZER 5 //buzzer pin
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
//Servo myServo; //define servo name
int relay = 3;
int door = 1;
void setup()
{
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  //myServo.attach(3);
  //myServo.write(0);
  pinMode(BUZZER, OUTPUT);
  digitalWrite (BUZZER, LOW);
  Serial.println("Put your card to the reader...");
  Serial.println();
  pinMode(relay, OUTPUT);
}
void loop()
{
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
   Serial.println ("stage 1");
   return;
    
  }
  
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
     Serial.println ("stage 2");
     return;
   
  }
Serial.println ("entering stage 3");
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();

  if (content.substring(1) == "35 64 D6 C3") //change here the UID of the card/cards that you want to give access
 {
    Serial.println("Authorized access");
    Serial.println();
    //digitalWrite(relay, HIGH);
    //digitalWrite (BUZZER, LOW);
   // delay(1500);
//     door = 1;
//      Serial.println("door =");
//      Serial.println(door);
       if(door == 2){
        digitalWrite(relay, LOW);
        delay(500);
        door=1;
      }

      else{
        digitalWrite(relay, HIGH);
        delay(500);
        door=2;
      }
      

  }

  else   {
    Serial.println(" Access denied");
    digitalWrite(BUZZER, HIGH);
   delay (500);
   digitalWrite(BUZZER, LOW);
  }
  delay (100);
}
