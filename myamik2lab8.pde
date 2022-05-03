/*
 * Madhava Sai Yamike - 675652145
 * Lab 8 - Graphing sensor data on a PC
 * In this lab we need to connect two analog devices to the Arduino and plot the data received on the computer using processing and data could be displayed in two separate graphs or both on one graph.
 * In this Lab I assumed that we can use use Pinmode functions in the setup but later realised that without using these functions we can write the code. 
 * References: https://www.arduino.cc/en/Tutorial/BuiltInExamples/Graph
               https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing#introduction
 * In person demonstration to TA - Jay (4/11) 4:00 p.m lab
*/

import processing.serial.*;
boolean check = false;

// This is the port that connects to the arduino
Serial myPort;  // To set the serial port
int xPosition = 1;  // To set the horizontal position of the graph
float lightSensor;
float potentiometer;
float l1 = 0;
float p1 = 0;

void setup () {  // To set the window size
    size(1000, 1000);
    background(0);  // To set the initial background
    myPort = new Serial(this, Serial.list()[0], 9600);
    myPort.bufferUntil('\n');  // Unless we get a newline character don't generate a serialEvent()
}
void draw () {  // Function to draw the line
  stroke(0,255,0);  // line for photoresistor
  lightSensor = map(lightSensor,0, 1023, 0, height);
  line(xPosition - 1, height - l1, xPosition, height - lightSensor);
  l1 = lightSensor;  
  stroke(255,0,0);  // line for potentiometer
 potentiometer = map(potentiometer,0, 1023, 0, height);
  line(xPosition - 1, height - p1, xPosition, height - potentiometer);
  p1 = potentiometer;
  if (xPosition >= width) {  // Condition to go back to the beginning when it reaches the edge of the screen
    xPosition = 0;
    background(0);
  } else if(check) {
    xPosition++;  // To increment the horizontal position
  }
}

void serialEvent (Serial myPort) {
  String data = myPort.readStringUntil('\n');
  if(data != null){  // Condition to check if the data is vaild
    if(!check){  // Condition to check whether the arduino and processing connections are made.
      data = trim(data);  // To delete if there are any white spaces in the data
      if(data.equals("Hello")){
        check = true;          
        myPort.write('R');  // To send back confirmation signal back to arduino
      }
    }
    else{  // Condition to parse the data by a space and end marker.
      int st = data.indexOf(" ");
      int end   = data.indexOf("\n") -1;
      lightSensor   = int( trim( data.substring(0, st)));
      potentiometer   = int( trim( data.substring(st+1, end)));
    }
  }
}  // End
