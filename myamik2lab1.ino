/*
 * 
 * Madhava Sai Yamike - 675652145
 * Lab 1 - Get started with Arduino
  Blink
  "no references used"
  Use the onboard LED on pin 13, a red LED on a second digital pin of your choice, and a green LED on a third digital pin of your choice
  TA - Amir (1/24) 4:00 p.m lab

  
  
*/

// constants won't change. Used here to set a pin number:
const int ledPin =  13;// the number of the LED pin
const int redPin = 7 ;
const int greenPin = 8;

// Variables will change:
int ledState = LOW;
int ledState1 = LOW;
int ledState2= LOW;// ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long prevMillisec = 0;        // will store last time LED was updated

// constants won't change:
const long event = 1000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long curMillisec = millis();

  if (curMillisec - prevMillisec >= event) {
    // save the last time you blinked the LED
    prevMillisec = curMillisec;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW && ledState1 == LOW && ledState2 == LOW) {
      ledState = HIGH;
      digitalWrite(redPin,ledState1);
      digitalWrite(greenPin, ledState2);
      digitalWrite(ledPin, ledState);
    }
   
    else if (ledState == HIGH) {
      ledState = LOW;
      ledState1 = HIGH;
      digitalWrite(redPin, ledState1);
      digitalWrite(greenPin, ledState2);
      digitalWrite(ledPin, ledState);
    }
      
     else if (ledState1 == HIGH) {
      ledState1 = LOW;
      ledState2 = HIGH;
      digitalWrite(greenPin, ledState2);
      digitalWrite(redPin, ledState1);
      digitalWrite(ledPin, ledState);
    }
    else if (ledState2 == HIGH) {
      ledState2 = LOW;
      ledState = HIGH;
      digitalWrite(ledPin, ledState);
      digitalWrite(redPin, ledState1);
      digitalWrite(greenPin, ledState2);
    }
  }
}
