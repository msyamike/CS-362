/*
 * Madhava Sai Yamike - 675652145
 * Lab 5 - Communication
 *In this lab we have to get the date(mm/dd/yyyy) & time(hh/mm/ss) from the user via the serial monitor in the arduino software. The date includes day, month and year and Time includes hour, minutes and seconds
 * In this Lab I assumed that I need to write seperate cases to keep track of leap years but I used a library called TimeLib.h
 * References: http://arduino.cc/en/Reference/Serial#.UwYyzfldV8E
               http://arduino.cc/en/Serial/Available#.UwYy2PldV8E
               http://arduino.cc/en/Serial/ReadBytesUntil#.UwYy6_ldV8E
 * In person demonstration to TA - Amir (3/14) 4:00 p.m lab
*/

#include <Time.h>
#include <TimeLib.h>  // Library to set time
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Setting all the inputs 
int Month;
int Day;
int Year;
int Hours;
int Minutes;
int Seconds;
int Date =1;
int Time = 1;
void setup() {  // To setup number of rows and columns on LCD.
  lcd.begin(16, 2);
  Serial.begin(9600);
    int clear_buffer;
      Serial.println("Enter mm/dd/yyyy:");  // To print the prompt message on Serial Monitor
      while(Serial.available() == 0){}
      Month = Serial.parseInt();
      Day = Serial.parseInt();
      Year = Serial.parseInt();

      if(!(Month >= 1 && Month <= 12) && Date == 1)
      {
        Date = 0;
        Serial.println("Month is wrong");
        Serial.println(Month);
      }
      else if(!(Day >0 && Day <= 31 ) && Date == 1)
      {
        Date = 0;
        Serial.println("Day is wrong");
        Serial.println(Day);
      }

      while(Serial.available())
        clear_buffer = Serial.parseInt();

      Serial.println("Enter hh:mm:ss: ");  // For Minutes Error checking
      while(Serial.available() == 0){}
      Hours = Serial.parseInt();
      Minutes = Serial.parseInt();
      Seconds = Serial.parseInt();
      if(!(Hours >= 1 && Hours < 24) && Time == 1){  // For Hour Error checking
        Time = 0;
        Serial.println("Hours is wrong");
        Serial.println(Hours);
      }
      else if(!(Minutes >= 0 && Minutes <= 59)  && Time == 1){    // For Minutes Error checking
        Time = 0;
        Serial.println("Minutes is wrong");
        Serial.println(Minutes);
      }
      else if(!(Seconds >= 0 && Seconds <= 59)  && Time == 1){  // For Seconds Error checking
        Time = 0;
        Serial.println("Seconds is wrong");
        Serial.println(Seconds);
      }
      
      if(Time == 1 && Date == 1)  // If nothing is wrong to set the Time and Date
        setTime(Hours,Minutes,Seconds,Day,Month,Year);
}

void loop(){    // To execute when there is no wrong time to display
    if(Time == 0 || Date == 0) 
      return;
    lcd.setCursor(0,0);
    lcd.print("Date: ");
    lcd.setCursor(6,0);
    lcd.print(month());
    lcd.setCursor(8,0);
    lcd.print("/");
    lcd.setCursor(9,0);
    lcd.print(day());
    lcd.setCursor(11,0);
    lcd.print("/");
    lcd.setCursor(12,0);
    lcd.print(year());
  
    lcd.setCursor(0,1);
    lcd.print("Time: ");
    lcd.setCursor(6,1);
    lcd.print(hour());
    lcd.setCursor(8,1);
    lcd.print(":");
    lcd.setCursor(9,1);
    lcd.print(minute());
    lcd.setCursor(11,1);
    lcd.print(":");
    lcd.setCursor(12,1);
    lcd.print(second());
    
  delay(1000);
  lcd.clear();
}
