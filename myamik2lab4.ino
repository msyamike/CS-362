/*
 * Madhava Sai Yamike - 675652145
 * Lab 4 - Multiple inputs and outputs
 * In this lab we will be using 4 LEDS and a photoresistor. We will Put all 4 LEDs next to each (preferably the same color).  As the amount of light seen by the photoresistor decreases, increase the number of LEDs that are lit.  For example, if your circuit receives no light then all of the LEDs should light up.  As you continue to increase the amount of light, the number of LEDs that light up will decrease.  So when the photoresistor receives the half the amount of light, 2 LEDS should be lit up, and when there is no light, all 4 LEDs should be lit up.  
 * I assumed that I need to use the resistor for Buzzer but I learned that we can connect buzzer directly to Ardunio without using resistor.
 * References: https://www.arduino.cc/en/Reference/AnalogRead
 *             https://www.arduino.cc/en/Reference/Map
 *             https://www.arduino.cc/en/Reference/AnalogWrite
 * In person demonstration to TA - Huma (2/28) 4:00 p.m lab
 */
 
int led1 = 6;  // To setup LED1 in 6 pin
int led2 = 7; // To setup LED2 in 7 pin
int led3 = 8;  // To setup LED3 in 8 pin
int led4 = 9;  // To setup LED4 in 9 pin
int buzzer = 11;  // To setup the buzzer in 11 pin
int photoResistor = A0;  // To setup photoResistor in A0 pin
int potentiometer = A1;  // To setup Potentiometer in A1 pin
int readpotential = 0;
int testValue = 0;
int frequency = 0;


void setup() { // To setup the code to run once
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(buzzer,OUTPUT);

}

void loop() {  // This loop will execute the turning on and off of LED
  testValue = analogRead(photoResistor);
  readpotential = analogRead(potentiometer);
  if(testValue <= 50)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
  }
  else if(testValue <= 100)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
  }
  else if(testValue <= 150)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
  else if(testValue <= 200)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
  else
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
  frequency = map(readpotential,0,5,0,255);
  tone(buzzer,frequency);
  delay(500);
}
