//Mux_Shield_AnalogIn_Example
//http://mayhewlabs.com/arduino-mux-shield

/*
This example shows how to read and store all 48 pins as analog inputs into arrays and print the results over serial.
Multiplexer pin inputs that do not have a voltage reading (i.e nothing connected) will have erratic values.

To simplify this code further, one might use nested for loops or function calls.
*/

//Give convenient names to the control pins
// See Arduino define Reference: http://arduino.cc/en/Reference/Define
#define CONTROL0 5    
#define CONTROL1 4
#define CONTROL2 3
#define CONTROL3 2

//Create arrays for data from the the MUXs
//See the Arduino Array Reference: http://www.arduino.cc/en/Reference/Array
/* ## int specifies that elements of the array will be integers
   ## mux0array is the name of the array
   ## [16] indicates that the array will contain 16 elements
*/
int mux0array[16];
int mux1array[16];
int mux2array[16];

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  12;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

// starting to setup millis
unsigned long time;

void setup()
{
  //Set MUX control pins to output
  pinMode(CONTROL0, OUTPUT);
  pinMode(CONTROL1, OUTPUT);
  pinMode(CONTROL2, OUTPUT);
  pinMode(CONTROL3, OUTPUT);
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);  
  
  //Open the serial port at 28800 bps
  Serial.begin(9600);
  //Setting bps to 28800 causes serial monitor to function only on Mac
  //Setting bps to 9600 allows serial monitor to function correctly on Mac and Ubuntu
}
  

void loop()
{
  // for millis
  time = millis();
  
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {    
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
  
  //This for loop is used to scroll through and store the 16 inputs on the FIRST multiplexer
  for (int i=0; i<16; i++)
  {
    //The following 4 commands set the correct logic for the control pins to select the desired input
    //See the Arduino Bitwise AND Reference: http://www.arduino.cc/en/Reference/BitwiseAnd
    //See the Aruino Bitshift Reference: http://www.arduino.cc/en/Reference/Bitshift
    digitalWrite(CONTROL0, (i&15)>>3); 
    digitalWrite(CONTROL1, (i&7)>>2);  
    digitalWrite(CONTROL2, (i&3)>>1);  
    digitalWrite(CONTROL3, (i&1));     
    
    //Read and store the input value at a location in the array
    mux0array[i] = analogRead(0);
  }
  
  //This for loop is used to scroll through the SECOND multiplexer
  for (int i=0; i<16; i++)
  {
    digitalWrite(CONTROL0, (i&15)>>3); 
    digitalWrite(CONTROL1, (i&7)>>2);  
    digitalWrite(CONTROL2, (i&3)>>1);  
    digitalWrite(CONTROL3, (i&1));     
    mux1array[i] = analogRead(1);
  }
  
  //This for loop is used to scroll through the THIRD multiplexer
  for (int i=0; i<16; i++)
  {
    digitalWrite(CONTROL0, (i&15)>>3); 
    digitalWrite(CONTROL1, (i&7)>>2);  
    digitalWrite(CONTROL2, (i&3)>>1);  
    digitalWrite(CONTROL3, (i&1));     
    mux2array[i] = analogRead(2);
  }
  
  
  
  /*
  The following lines are for printing out results of
  arrays 0, 1, and 2 in one row separated by commas
  */
  Serial.print(mux0array[0]); // flower position 1
  Serial.print(",");
  Serial.print(mux0array[1]); // flower position 2
  Serial.print(",");
  Serial.print(mux0array[2]); // flower position 3
  Serial.print(",");
  Serial.print(mux0array[3]); // flower position 4
  Serial.print(",");
  Serial.print(mux0array[4]); // flower position 5
  Serial.print(",");
  Serial.print(mux0array[5]); // flower position 6
  Serial.print(",");
  Serial.print(mux0array[6]); // flower position 7
  Serial.print(",");
  Serial.print(mux0array[7]); // flower position 8
  Serial.print(",");
  Serial.print(mux0array[8]); // flower position 9
  Serial.print(",");
  Serial.print(mux0array[9]); // flower position 10
  Serial.print(",");
  Serial.print(mux0array[10]); // flower position 11
  Serial.print(",");
  Serial.print(mux0array[11]); // flower position 12
  Serial.print(",");
  Serial.print(mux0array[12]); // flower position 13
  Serial.print(",");
  Serial.print(mux0array[13]); // flower position 14
  Serial.print(",");
  Serial.print(mux0array[14]); // flower position 15
  Serial.print(",");
  Serial.print(mux0array[15]); // flower position 16
  Serial.print(",");
  Serial.print(mux1array[0]); // flower position 17
  Serial.print(",");
  Serial.print(mux1array[1]); // flower position 18
  Serial.print(",");
  Serial.print(mux1array[2]); // flower position 19
  Serial.print(",");
  Serial.print(mux1array[3]); // flower position 20
  Serial.print(",");
  Serial.print(mux1array[4]); // flower position 21
  Serial.print(",");
  Serial.print(mux1array[5]); // flower position 22
  Serial.print(",");
  Serial.print(mux1array[6]); // flower position 23
  Serial.print(",");
  Serial.print(mux1array[7]); // flower position 24
  Serial.print(",");
  Serial.print(mux1array[8]); // flower position 25
  Serial.print(",");
  Serial.print(mux1array[9]); // flower position 26
  Serial.print(",");
  Serial.print(mux1array[10]); // flower position 27
  Serial.print(",");
  Serial.print(mux1array[11]); // flower position 28
  Serial.print(",");
  Serial.print(mux1array[12]); // flower position 29
  Serial.print(",");
  Serial.print(mux1array[13]); // flower position 30
  Serial.print(",");
  Serial.print(mux1array[14]); // flower position 31
  Serial.print(",");
  Serial.print(mux1array[15]); // flower position 32
  Serial.print(",");
  Serial.print(mux2array[0]); // flower position 33
  Serial.print(",");
  Serial.print(mux2array[1]); // flower position 34
  Serial.print(",");
  Serial.print(mux2array[2]); // flower position 35
  Serial.print(",");
  Serial.print(mux2array[3]); // Flower position 36. This should now complete all 36 flowers in the array.  All others could be deleted unless more flowers are added to the setup.
  Serial.print(",");
  Serial.print(mux2array[4]);
  Serial.print(",");
  Serial.print(mux2array[5]);
  Serial.print(",");
  Serial.print(mux2array[6]);
  Serial.print(",");
  Serial.print(mux2array[7]);
  Serial.print(",");
  Serial.print(mux2array[8]);
  Serial.print(",");
  Serial.print(mux2array[9]);
  Serial.print(",");
  Serial.print(mux2array[10]);
  Serial.print(",");
  Serial.print(mux2array[11]);
  Serial.print(",");
  Serial.print(mux2array[12]);
  Serial.print(",");
  Serial.print(mux2array[13]);
  Serial.print(",");
  Serial.print(mux2array[14]);
  Serial.print(",");
  Serial.print(mux2array[15]);
  Serial.print(",");
  Serial.print(digitalRead(buttonState)); // Read the pin (state of the buttom) and display the value
  Serial.print(",");
  Serial.print(time); // Display the time (in ms) since the serial monitor became active
  Serial.println();
  
  // Set the delay (in ms) between samples.  A delay of 500 yeilds a sampling
  // rate of 2 Hz.
  delay (250);
}
