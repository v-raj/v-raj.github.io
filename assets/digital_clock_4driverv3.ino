/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test - this will drive 16 servos, one after the other

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815

  These displays use I2C to communicate, 2 pins are required to  
  interface. For Arduino UNOs, thats SCL -> Analog 5, SDA -> Analog 4

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include "RTClib.h"
#include <Adafruit_PWMServoDriver.h>

RTC_DS1307 rtc;

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0X40);
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0X41);
Adafruit_PWMServoDriver pwm3 = Adafruit_PWMServoDriver(0X42);
Adafruit_PWMServoDriver pwm4 = Adafruit_PWMServoDriver(0X43);
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  560// this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;
uint8_t degree =0;

void setServoDegree(uint8_t ser, uint8_t n, uint8_t degree);
void s1(int t);
void s2(int t);
void s3(int t);
void s4(int t);
void setup() {

  Serial.begin(9600);
  
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
  Serial.println("RTC is NOT running!");
  }
  pwm1.begin();
  pwm2.begin();
  pwm3.begin();
  pwm4.begin();
  
  
  pwm1.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  pwm2.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  pwm3.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  pwm4.setPWMFreq(60);  // Analog servos run at ~60 Hz updates


  yield();


  for( int s=1; s<=4;s++)
  {
    for(int k=0; k<=6; k++)
    {
      setServoDegree(s,k,0);
    }
  }

  
}

void loop() {
  
    DateTime now = rtc.now();
    int h1 =now.hour()/10;
    int h2=now.hour()%10;
    int m1= now.minute()/10;
    int m2= now.minute()%10;
    int sec1=now.second()/10;
    int sec2=now.second()%10;
    Serial.print(h1);
    Serial.print(h2);
    Serial.print(':');
    Serial.print(m1);
    Serial.print(m2);
     Serial.print(':');
    Serial.print(sec1);
    Serial.print(sec2);
    Serial.println();
    
  s1(2);
//     s2(sec1);
//     s3(m2);
//     s4(m1);
//     s1(5);
     s2(8);
     s3(8);
     s4(8);
     delay(1000);


//delay(10000);

   
}// loop ends

void setServoDegree(uint8_t ser, uint8_t n, uint8_t degree) {
   //degree = 45;
   int pulsedeg= map(degree, 0, 180, SERVOMIN, SERVOMAX);
        if(ser==1)
        {
          pwm1.setPWM(n, 0, pulsedeg ); // n is the servo number  pulsedegree is the 
        }
        else if(ser==2)
        {
          pwm2.setPWM(n, 0, pulsedeg ); 
        }      
        else if(ser==3)
        {
          pwm3.setPWM(n, 0, pulsedeg ); 
        }
         else if(ser==4)
        {
          pwm4.setPWM(n, 0, pulsedeg ); 
        }
        
               

}// function ends

void s1(int t)
{
  switch(t)
  {
  case 1:
  setServoDegree(1,0,0);
  setServoDegree(1,1,0);
  setServoDegree(1,2,0);
  setServoDegree(1,3,0);
  setServoDegree(1,4,0);
  setServoDegree(1,5,90);
  setServoDegree(1,6,90);
  break;
  
  case 2:
  setServoDegree(1,0,0);
  setServoDegree(1,1,90);
  setServoDegree(1,2,90);
  setServoDegree(1,3,90);
  setServoDegree(1,4,90);
  setServoDegree(1,5,90);
  setServoDegree(1,6,0);
  break;

   case 3:
  setServoDegree(1,0,0);
  setServoDegree(1,1,0);
  setServoDegree(1,2,90);
  setServoDegree(1,3,90);
  setServoDegree(1,4,90);
  setServoDegree(1,5,90);
  setServoDegree(1,6,90);
  break;

  case 4:
  setServoDegree(1,0,90);
  setServoDegree(1,1,0);
  setServoDegree(1,2,0);
  setServoDegree(1,3,90);
  setServoDegree(1,4,0);
  setServoDegree(1,5,90);
  setServoDegree(1,6,90);
  break;

  case 5:
  setServoDegree(1,0,90);
  setServoDegree(1,1,0);
  setServoDegree(1,2,90);
  setServoDegree(1,3,90);
  setServoDegree(1,4,90);
  setServoDegree(1,5,0);
  setServoDegree(1,6,90);
  break;

  
  case 6:
  setServoDegree(1,0,90);
  setServoDegree(1,1,90);
  setServoDegree(1,2,90);
  setServoDegree(1,3,90);
  setServoDegree(1,4,90);
  setServoDegree(1,5,0);
  setServoDegree(1,6,90);
  break;

  
  case 7:
  setServoDegree(1,0,0);
  setServoDegree(1,1,0);
  setServoDegree(1,2,90);
  setServoDegree(1,3,0);
  setServoDegree(1,4,0);
  setServoDegree(1,5,90);
  setServoDegree(1,6,90);
  break;

  
  case 8:
  setServoDegree(1,0,90);
  setServoDegree(1,1,90);
  setServoDegree(1,2,90);
  setServoDegree(1,3,90);
  setServoDegree(1,4,90);
  setServoDegree(1,5,90);
  setServoDegree(1,6,90);
  break;

  
  case 9:
  setServoDegree(1,0,90);
  setServoDegree(1,1,0);
  setServoDegree(1,2,90);
  setServoDegree(1,3,90);
  setServoDegree(1,4,90);
  setServoDegree(1,5,90);
  setServoDegree(1,6,90);
  break;

  
  case 0:
  setServoDegree(1,0,90);
  setServoDegree(1,1,90);
  setServoDegree(1,2,90);
  setServoDegree(1,3,0);
  setServoDegree(1,4,90);
  setServoDegree(1,5,90);
  setServoDegree(1,6,90);
  break;

  default:
  setServoDegree(1,0,0);
  setServoDegree(1,1,0);
  setServoDegree(1,2,0);
  setServoDegree(1,3,0);
  setServoDegree(1,4,0);
  setServoDegree(1,5,0);
  setServoDegree(1,6,0);
  break;
}
}

void s3(int t)
{
  switch(t)
  {
  case 1:
  setServoDegree(1,7,0);
  setServoDegree(1,8,0);
  setServoDegree(1,9,0);
  setServoDegree(1,10,0);
  setServoDegree(1,11,0);
  setServoDegree(1,12,90);
  setServoDegree(1,13,90);
  break;
  
  case 2:
  setServoDegree(1,7,0);
  setServoDegree(1,8,90);
  setServoDegree(1,9,90);
  setServoDegree(1,10,90);
  setServoDegree(1,11,90);
  setServoDegree(1,12,90);
  setServoDegree(1,13,0);
  break;

   case 3:
  setServoDegree(1,7,0);
  setServoDegree(1,8,0);
  setServoDegree(1,9,90);
  setServoDegree(1,10,90);
  setServoDegree(1,11,90);
  setServoDegree(1,12,90);
  setServoDegree(1,13,90);
  break;

  case 4:
  setServoDegree(1,7,90);
  setServoDegree(1,8,0);
  setServoDegree(1,9,0);
  setServoDegree(1,10,90);
  setServoDegree(1,11,0);
  setServoDegree(1,12,90);
  setServoDegree(1,13,90);
  break;

  case 5:
  setServoDegree(1,7,90);
  setServoDegree(1,8,0);
  setServoDegree(1,9,90);
  setServoDegree(1,10,90);
  setServoDegree(1,11,90);
  setServoDegree(1,12,0);
  setServoDegree(1,13,90);
  break;

  
  case 6:
  setServoDegree(1,7,90);
  setServoDegree(1,8,90);
  setServoDegree(1,9,90);
  setServoDegree(1,10,90);
  setServoDegree(1,11,90);
  setServoDegree(1,12,0);
  setServoDegree(1,13,90);
  break;

  
  case 7:
  setServoDegree(1,7,0);
  setServoDegree(1,8,0);
  setServoDegree(1,9,90);
  setServoDegree(1,10,0);
  setServoDegree(1,11,0);
  setServoDegree(1,12,90);
  setServoDegree(1,13,90);
  break;

  
  case 8:
  setServoDegree(1,7,90);
  setServoDegree(1,8,90);
  setServoDegree(1,9,90);
  setServoDegree(1,10,90);
  setServoDegree(1,11,90);
  setServoDegree(1,12,90);
  setServoDegree(1,13,90);
  break;

  
  case 9:
  setServoDegree(1,7,90);
  setServoDegree(1,8,0);
  setServoDegree(1,9,90);
  setServoDegree(1,10,90);
  setServoDegree(1,11,90);
  setServoDegree(1,12,90);
  setServoDegree(1,13,90);
  break;

  
  case 0:
  setServoDegree(1,7,90);
  setServoDegree(1,8,90);
  setServoDegree(1,9,90);
  setServoDegree(1,10,0);
  setServoDegree(1,11,90);
  setServoDegree(1,12,90);
  setServoDegree(1,13,90);
  break;

  default:
  setServoDegree(1,7,0);
  setServoDegree(1,8,0);
  setServoDegree(1,9,0);
  setServoDegree(1,10,0);
  setServoDegree(1,11,0);
  setServoDegree(1,12,0);
  setServoDegree(1,13,0);
  break;
}
}

void s2(int t)
{
  switch(t)
  {
  case 1:
  setServoDegree(2,0,0);
  setServoDegree(2,1,0);
  setServoDegree(2,2,0);
  setServoDegree(2,3,0);
  setServoDegree(2,4,0);
  setServoDegree(2,5,90);
  setServoDegree(2,6,90);
  break;
  
  case 2:
  setServoDegree(2,0,0);
  setServoDegree(2,1,90);
  setServoDegree(2,2,90);
  setServoDegree(2,3,90);
  setServoDegree(2,4,90);
  setServoDegree(2,5,90);
  setServoDegree(2,6,0);
  break;

   case 3:
  setServoDegree(2,0,0);
  setServoDegree(2,1,0);
  setServoDegree(2,2,90);
  setServoDegree(2,3,90);
  setServoDegree(2,4,90);
  setServoDegree(2,5,90);
  setServoDegree(2,6,90);
  break;

  case 4:
  setServoDegree(2,0,90);
  setServoDegree(2,1,0);
  setServoDegree(2,2,0);
  setServoDegree(2,3,90);
  setServoDegree(2,4,0);
  setServoDegree(2,5,90);
  setServoDegree(2,6,90);
  break;

  case 5:
  setServoDegree(2,0,90);
  setServoDegree(2,1,0);
  setServoDegree(2,2,90);
  setServoDegree(2,3,90);
  setServoDegree(2,4,90);
  setServoDegree(2,5,0);
  setServoDegree(2,6,90);
  break;

  
  case 6:
  setServoDegree(2,0,90);
  setServoDegree(2,1,90);
  setServoDegree(2,2,90);
  setServoDegree(2,3,90);
  setServoDegree(2,4,90);
  setServoDegree(2,5,0);
  setServoDegree(2,6,90);
  break;

  
  case 7:
  setServoDegree(2,0,0);
  setServoDegree(2,1,0);
  setServoDegree(2,2,90);
  setServoDegree(2,3,0);
  setServoDegree(2,4,0);
  setServoDegree(2,5,90);
  setServoDegree(2,6,90);
  break;

  
  case 8:
  setServoDegree(2,0,90);
  setServoDegree(2,1,90);
  setServoDegree(2,2,90);
  setServoDegree(2,3,90);
  setServoDegree(2,4,90);
  setServoDegree(2,5,90);
  setServoDegree(2,6,90);
  break;

  
  case 9:
  setServoDegree(2,0,90);
  setServoDegree(2,1,0);
  setServoDegree(2,2,90);
  setServoDegree(2,3,90);
  setServoDegree(2,4,90);
  setServoDegree(2,5,90);
  setServoDegree(2,6,90);
  break;

  
  case 0:
  setServoDegree(2,0,90);
  setServoDegree(2,1,90);
  setServoDegree(2,2,90);
  setServoDegree(2,3,0);
  setServoDegree(2,4,90);
  setServoDegree(2,5,90);
  setServoDegree(2,6,90);
  break;

  default:
  setServoDegree(2,0,0);
  setServoDegree(2,1,0);
  setServoDegree(2,2,0);
  setServoDegree(2,3,0);
  setServoDegree(2,4,0);
  setServoDegree(2,5,0);
  setServoDegree(2,6,0);
  break;
}
}

void s4(int t)
{
  switch(t)
  {
  case 1:
  setServoDegree(2,7,0);
  setServoDegree(2,8,0);
  setServoDegree(2,9,0);
  setServoDegree(2,10,0);
  setServoDegree(2,11,0);
  setServoDegree(2,12,90);
  setServoDegree(2,13,90);
  break;
  
  case 2:
  setServoDegree(2,7,0);
  setServoDegree(2,8,90);
  setServoDegree(2,9,90);
  setServoDegree(2,10,90);
  setServoDegree(2,11,90);
  setServoDegree(2,12,90);
  setServoDegree(2,13,0);
  break;

   case 3:
  setServoDegree(2,7,0);
  setServoDegree(2,8,0);
  setServoDegree(2,9,90);
  setServoDegree(2,10,90);
  setServoDegree(2,11,90);
  setServoDegree(2,12,90);
  setServoDegree(2,13,90);
  break;

  case 4:
  setServoDegree(2,7,90);
  setServoDegree(2,8,0);
  setServoDegree(2,9,0);
  setServoDegree(2,10,90);
  setServoDegree(2,11,0);
  setServoDegree(2,12,90);
  setServoDegree(2,13,90);
  break;

  case 5:
  setServoDegree(2,7,90);
  setServoDegree(2,8,0);
  setServoDegree(2,9,90);
  setServoDegree(2,10,90);
  setServoDegree(2,11,90);
  setServoDegree(2,12,0);
  setServoDegree(2,13,90);
  break;

  
  case 6:
  setServoDegree(2,7,90);
  setServoDegree(2,8,90);
  setServoDegree(2,9,90);
  setServoDegree(2,10,90);
  setServoDegree(2,11,90);
  setServoDegree(2,12,0);
  setServoDegree(2,13,90);
  break;

  
  case 7:
  setServoDegree(2,7,0);
  setServoDegree(2,8,0);
  setServoDegree(2,9,90);
  setServoDegree(2,10,0);
  setServoDegree(2,11,0);
  setServoDegree(2,12,90);
  setServoDegree(2,13,90);
  break;

  
  case 8:
  setServoDegree(2,7,90);
  setServoDegree(2,8,90);
  setServoDegree(2,9,90);
  setServoDegree(2,10,90);
  setServoDegree(2,11,90);
  setServoDegree(2,12,90);
  setServoDegree(2,13,90);
  break;

  
  case 9:
  setServoDegree(2,7,90);
  setServoDegree(2,8,0);
  setServoDegree(2,9,90);
  setServoDegree(2,10,90);
  setServoDegree(2,11,90);
  setServoDegree(2,12,90);
  setServoDegree(2,13,90);
  break;

  
  case 0:
  setServoDegree(2,7,90);
  setServoDegree(2,8,90);
  setServoDegree(2,9,90);
  setServoDegree(2,10,0);
  setServoDegree(2,11,90);
  setServoDegree(2,12,90);
  setServoDegree(2,13,90);
  break;

  default:
  setServoDegree(2,7,0);
  setServoDegree(2,8,0);
  setServoDegree(2,9,0);
  setServoDegree(2,10,0);
  setServoDegree(2,11,0);
  setServoDegree(2,12,0);
  setServoDegree(2,13,0);
  break;
}
}

void setSegment(int sno, int value)
{
 
  
}




