#include <SoftwareSerial.h>
// Viraj Gandhi


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
SoftwareSerial Serial(RX, TX);

char id = 'a'; // the address of this Node
const int servopin = 0;  // Sevo Pin     
char chr;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
   pinMode(servopin, OUTPUT);
  // delay(5000);
   Serial.println("Node ");
   Serial.print(id);
   Serial.println("Online");
}



void loop()
{
  chr = Serial.read();
  if (chr == id) {   // if true next commands are or this Node.
         chr = Serial.read(); // we read recond character following it 

               if (chr == '1') {
                for (int i = 0; i < 30; ++i) {
                digitalWrite(servopin , HIGH);
                delayMicroseconds(2000);
                digitalWrite(servopin , LOW);
                delayMicroseconds(18000); 
                       }
//                 Serial.print("Node ");
//                 Serial.print(id);
//                 Serial.println(": ON");
//                   digitalWrite(servopin, HIGH);   // FOR DEBUGGING 
                }              
              else if (chr == '0')
              {
                for (int i = 0; i < 30; ++i) {
                  digitalWrite(servopin , HIGH);
                  delayMicroseconds(1000);
                  digitalWrite(servopin , LOW);
                  delayMicroseconds(19000);
                   }
               
//                 Serial.print("Node ");
//                 Serial.print(id);
//                 Serial.println(": OFF");
//                 digitalWrite(servopin, LOW);  // FOR DEBUGGING 
              }
              else
             {
             // digitalWrite(servopin, LOW);
             }
           }
           
                     
}
