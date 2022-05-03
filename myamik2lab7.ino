/*
 * Madhava Sai Yamike - 675652145
 * Lab 7 - Interrupts
 * In this lab we have to write a program for the arduino that utilizes interrupts. When no button has been pressed your 16x2 display should say something like "We have been waiting for X seconds", where X will be updated as time goes on
 * In this Lab I assumed that we can use any pins to make the circuit work but I realized that we need to use pin two and three to make the circuit work.
 * References: http://arduino.cc/en/Reference/attachInterrupt
               https://www.arduino.cc/en/Reference/Millis
 * In person demonstration to TA - Amir (4/4) 4:00 p.m lab
*/

#include <LiquidCrystal.h> // Library for LCD
LiquidCrystal lcd(12,11,9,8,7,6);  // To set the pins
int setBack = 2;
int interruptPin = 3;
int tracker = 0;
void setup() {  // To set up the number of rows & columns on LCD.
  lcd.begin(16, 2);
  pinMode(interruptPin,INPUT_PULLUP);
  pinMode(setBack,INPUT);
  attachInterrupt(digitalPinToInterrupt(3),start,CHANGE);
  attachInterrupt(digitalPinToInterrupt(2),setTo0,CHANGE);
}
int buttonVal = 0;
int intial = 0;

void setTo0()  // Function to set the time to 0
{
  lcd.clear();
  tracker = 0;
  buttonVal = 1;
}

void start()  // Function to restart the time.
{
  buttonVal = 0;
}

void loop()  // To run and stop the time.
{
  if(buttonVal != 1)
  {
  lcd.setCursor(0,0);
  lcd.print("We have been wai");
  lcd.setCursor(0,1);
  lcd.print("ting ");
  lcd.setCursor(6,1);
  lcd.print(tracker);
  lcd.setCursor(9,1);
  lcd.print("seconds");
  if(intial == 0)
  {
    buttonVal = digitalRead(setBack);
    intial = 1;
  }
  else
  {
    if(buttonVal)
    {
  
      lcd.print("Seconds");
    }
  }
   tracker++;
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("Interrupting...");
    lcd.setCursor(0,1); 
    lcd.print("Press button 2");
  }
  delay(1000);
  lcd.clear();
}  //end of program
