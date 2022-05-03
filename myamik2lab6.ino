/*
 * Madhava Sai Yamike - 675652145 & Kalpkumar Shah - 656968033(Partner)
 * Lab 6 - Serial Communication
 *In this lab we have to demonstrate transmission of data over a serial connection
 * In this Lab I assumed that circuit will work without batteries but realized that the connections should be developed between arduino's with the batteries 
 * References: http://arduino.cc/en/Reference/Serial#.UwYyzfldV8E
               http://arduino.cc/en/Serial/Available#.UwYy2PldV8E
               http://arduino.cc/en/Serial/ReadBytesUntil#.UwYy6_ldV8E
 * In person demonstration to TA - Michael (3/28) 2:00 p.m lab
*/


// start code
const int button = 11;
const int led = 3;

// Variable used
int curr = 0;
int prev = 0;
int check = 0;

// start Setup
void setup() 
{
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
} // end start

// start Loop
void loop() {
  // Reading from digital pin.
  curr = digitalRead(button);

  // If button is pressed
  if(curr == HIGH)
  {  
    // if the previous and current are not same state
    if(prev != curr)
    {
      Serial.write(1);
      curr = LOW;
      delay(200); // adding delay to make it stable
    }
  }
  prev = curr;

  // Serial read checking
  if(Serial.available() > 0)
  {
    int reading = Serial.read();
    if(reading)  // If Serial.read() is true
    {
      check = ~check;
      digitalWrite(led, check);
    }   
  }0
} // end loop
// end code
