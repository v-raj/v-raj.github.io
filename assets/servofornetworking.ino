#include <SoftwareSerial.h>
// ***
// *** Define the RX and TX pins. Choose any two
// *** pins that are unused. Try to avoid D0 (pin 5)
// *** and D2 (pin 7) if you plan to use I2C.
// ***


#define TX   3  // PB3, Pin 2 on attiny45 leg
#define RX   4  // PB4, Pin 3 on attiny45 leg

// These constants won't change.  They're used to give names

// ***
// *** Define the software based serial port. Using the
// *** name Serial so that code can be used on other
// *** platforms that support hardware based serial. On
// *** chips that support the hardware serial, just
// *** comment this line.
// ***
SoftwareSerial mySerial(RX, TX);


char chr;
void setup() {
  // initialize serial communications at 9600 bps:
  mySerial.begin(9600);
   pinMode(3, OUTPUT);
}



void loop()
{
  char chr = mySerial.read();
  mySerial.read();
  if (chr == 'a') {
    for (int i = 0; i < 50; ++i) {
      digitalWrite(3, HIGH);
      delayMicroseconds(2000);
      digitalWrite(3, LOW);
      delayMicroseconds(18000);
    }
  }
  else if (chr == '0')
  {
    for (int i = 0; i < 50; ++i) {
      digitalWrite(3, HIGH);
      delayMicroseconds(1000);
      digitalWrite(3, LOW);
      delayMicroseconds(19000);
    }
   
  }
  else
  {
    
  }
}
