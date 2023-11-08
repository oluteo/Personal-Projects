int cursorPos;

int dig[4];
int SW = 2;
int buzzer=6;

//include LCD library

#include <LiquidCrystal.h>


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);




//main setup function runs once

void setup() {



  //setup lcd display

  lcd.begin(16, 2);

  lcd.print("Enter password:");

  lcd.setCursor(6, 1);

  lcd.print("0000");

  lcd.cursor();

  lcd.noBlink();

  lcd.setCursor(6, 1);
  //set values of variables
  cursorPos = 0;
  for (int i = 0; i <= 3; i++) {
    dig[i] = 0;
  }
  //blink LED on board
  digitalWrite(13, LOW);
  delay(500);
  digitalWrite(13, HIGH);
 pinMode (buzzer,OUTPUT);
}
//loop code runs continuously while Arduino has power
void loop() {
  SW_state = digitalRead(SW);
digitalWrite(buzzer,HIGH);
  if (digitalRead(13) == HIGH) ;
    while (digitalRead(13) == HIGH) { //anything in this loop will run until the joystick is pressed in
      int sensorX = analogRead(A0); //get readings for x,y-axis movement
      int sensorY = analogRead(A1);
      float angleX = sensorX * (180.0 / 1023.0); //convert value to angle
      float angleY = sensorY * (180.0 / 1023.0);
      if (angleX > 100) {
        moveRight();
        delay(500);

      } else if ( angleX < 70) {

        moveLeft();

        delay(500);

      } else {

        if (angleY > 105) {

          decrease(cursorPos);

          delay(250);

        } else if (angleY < 75) {

          increase(cursorPos);

          delay(250);

        }

      }

    }

  }



  //this runs once the button is presses
 if (SW_state ==0){
  checkCode();

  delay(2000);

  setup();
 }
}



void moveRight() {

  if (cursorPos == 3) {

    lcd.setCursor(6, 1);          // here in this part of the code we define controls of joystick

    cursorPos = 0;                //how  we can use every part of the move of joystick code here

  } else {                      //define that for every movement of the joystick change the direction

    int a = cursorPos + 7;       //change the numbers display on lcd for ok button click on joystick take in center and click the passcode will enter.

    lcd.setCursor(a, 1);

    cursorPos = cursorPos + 1;

  }

}



void moveLeft() {

  if (cursorPos == 0) {

    lcd.setCursor(9, 1);

    cursorPos = 3;

  } else {

    int b = cursorPos + 5;

    lcd.setCursor(b, 1);

    cursorPos = cursorPos - 1;

  }

}



void increase(int cursorPos) {

  if (dig[cursorPos] == 9) {

    dig[cursorPos] = 0;

  } else {

    dig[cursorPos] = dig[cursorPos] + 1;

  }

  int c = cursorPos + 6;

  lcd.setCursor(c, 1);

  lcd.print(dig[cursorPos]);

  lcd.setCursor(c, 1);

}



void decrease(int cursorPos) {

  if (dig[cursorPos] == 0) {

    dig[cursorPos] = 9;

  } else {

    dig[cursorPos] = dig[cursorPos] - 1;

  }

  int c = cursorPos + 6;

  lcd.setCursor(c, 1);

  lcd.print(dig[cursorPos]);

  lcd.setCursor(c, 1);

}

//change this part for your own passcode



//I've picked 1234....

void checkCode() {

  if (dig[0] == 4 && dig[1] == 4 && dig[2] == 1 && dig[3] == 1) { //Change '1', '2', '3', '4' on this line!!!!

    lcd.setCursor(4, 1);

    lcd.print("Welcome");
digitalWrite(buzzer,LOW);
    delay(6000);

  } else {

    lcd.setCursor(5, 1);
digitalWrite(buzzer,HIGH);
    lcd.print("Wrong!");

  }

}
