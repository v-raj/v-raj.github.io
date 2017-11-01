#include <SoftwareSerial.h>
// ***
// *** Define the RX and TX pins. Choose any two
// *** pins that are unused. Try to avoid D0 (pin 5)
// *** and D2 (pin 7) if you plan to use I2C.
// ***
#define RX   4    // *** D3, Pin 2
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
char chr;
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
   pinMode(3, OUTPUT);
}



void loop()
{

    for (int i = 0; i < 50; ++i) {
      digitalWrite(3, HIGH);
      delayMicroseconds(2000);
      digitalWrite(3, LOW);
      delayMicroseconds(18000);
    }
  
    delay(2000);
  
    for (int i = 0; i < 50; ++i) {
      digitalWrite(3, HIGH);
      delayMicroseconds(1500);
      digitalWrite(3, LOW);
      delayMicroseconds(18500);
    }
     
  
}
