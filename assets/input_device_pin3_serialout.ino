#include <SoftwareSerial.h>
// ***
// *** Define the RX and TX pins. Choose any two
// *** pins that are unused. Try to avoid D0 (pin 5)
// *** and D2 (pin 7) if you plan to use I2C.
// ***
#define RX   1    // *** D3, Pin 2
#define TX   2  // *** D4, Pin 3

// These constants won't change.  They're used to give names

// ***
// *** Define the software based serial port. Using the
// *** name Serial so that code can be used on other
// *** platforms that support hardware based serial. On
// *** chips that support the hardware serial, just
// *** comment this line.
// ***
SoftwareSerial Serial(RX, TX);

// to the pins used:
const int analogInPin = 3;  // Analog input pin that the potentiometer is attached to
//const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
       // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
   pinMode(3, INPUT);
}

void loop() {
 
  sensorValue = analogRead(3);
  
  
  // print the results to the serial monitor:
 int s = sensorValue*2;
  Serial.println(s);

 
  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(1000);
}
