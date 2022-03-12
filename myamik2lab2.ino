/*
 * Madhava Sai Yamike - 675652145
 * Lab 2 - Input and Output
 * we need to write a code to keep track of the number of button presses and algorithmically convert that number to a binary output. The code should NOT just be implementing a giant lookup table to translate to binary
 * I assumed that when do a downstate it should start from 7 without doing a upstate. I assumed that to change my LEDstate to binary I need to do bitwise operation but without that I can do with the help of %2.
 * References: https://www.arduino.cc/en/Tutorial/Button
 * TA - Amir (2/14) 4:00 p.m lab

  
  
*/

const int downButton = 2;  // This will decrease the bit count.
const int upButton= 3;  // This will increase the bit count.
const int greenLED = 10;  // 1's bit LED pin
const int redLED = 11;  // 2's bit LED pin 
const int blueLED = 12;  // 4's bit LED pin
int lightStat[3] = {0,0,0};  // Light series array.

int counter = 0;  // Set the counter to zero
int upStatus = LOW;  // To set the upstatus to low
int downStatus = LOW;  // To set the downstatus to low
void setup() { // This function will help us to initialize the LED pin as an output  
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(downButton, INPUT);
  pinMode(upButton, INPUT);
  digitalWrite(blueLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
}

void loop() {  
  // This will read the status of two buttons
  while(digitalRead(downButton)) {
    downStatus = HIGH;
  }
  while(digitalRead(upButton)) {
    upStatus = HIGH;
  }  
  // Condition to check if the Button was pressed and change the counter accordingly
  if (upStatus == HIGH) {
    counter++;
    if(counter > 7) counter = 0;
  }
  if (downStatus == HIGH){
    counter--;
    if(counter < 0) counter = 7; 
  }
  // To calculate the status of Binary bit
  int temp = 0;
  temp = counter;
  int j = 0;
  while(temp > 0) {
     lightStat[j] =  temp % 2;
     temp = temp / 2;
     j++;
  }
  // According to the calculated series array we will set the lights
    if (lightStat[0] == 0) {
        digitalWrite(greenLED, LOW);
    } else {
        digitalWrite(greenLED, HIGH);

    }
    if (lightStat[1] == 0) {
        digitalWrite(redLED, LOW);
    } else {
        digitalWrite(redLED, HIGH);

     }

    if (lightStat[2] == 0) {
        digitalWrite(blueLED, LOW);
    } else {
         digitalWrite(blueLED, HIGH);
     }  
  temp = 0;
  downStatus = LOW;
  upStatus = LOW;
  int i = 0;
  while (i < 3){
    lightStat[i] = 0;
    i++;
  }
}
