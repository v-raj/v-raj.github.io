/*
By Viraj Gandhi
Fabacademy 2017

*/
import controlP5.*;
import processing.serial.*;

ControlP5 cp5;   // we need a object of class controlP5


Textlabel myTextlabelA;  // Defining THe lable of type Textlabel
Textlabel myTextlabelB;
Textlabel myTextlabelC;
Textlabel myTextlabelV;



Serial myPort;  // Create object from Serial class

void setup() {
   //***** Enebling serial to send data to arduino
 String portName = Serial.list()[0]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);
  
  size(660,430);
  noStroke();
  cp5 = new ControlP5(this); 
  

 /*
 Below we declare Toggle button and we add it.
 The positon elemnt sets it X Y positon 
 The Background Colour is the Base colour or the Delault colour of the Button

 */

  cp5.addToggle("ServoA").setPosition(20,20).setSize(200,200)
    .setCaptionLabel("")  // kept empty because it will add text below our button in very tiny font which i didnt wated 
     .setColorBackground(color(177,255,50))  //The Background Colour is the Base colour or the Delault colour of the Button
     .setColorActive(color(177,255,50))   // Triggers when we hover over it
     .setColorForeground(color(211,211,211)); // this colour activates when we press it
  
  cp5.addToggle("ServoB").setPosition(230,20).setSize(200,200)
    .setCaptionLabel("")
     .setColorBackground(color(255, 153, 0))
     .setColorActive(color(255, 153, 0))
     .setColorForeground(color(211,211,211));
     
     cp5.addToggle("ServoC").setPosition(440,20).setSize(200,200)
    .setCaptionLabel("")
    .setColorBackground(color(255,105,180))
     .setColorActive(color(255,105,180))
     .setColorForeground(color(211,211,211));
     
     
     myTextlabelA = cp5.addTextlabel("label")
                    .setText("A")              
                    .setPosition(100,210)
                    .setColor(color(255,255,255))
                    .setFont(createFont("Agency FB",100))
                    ;
  myTextlabelB = cp5.addTextlabel("label2")
                    .setText("B")
                    .setPosition(300,210)
                    .setColor(color(255,255,255))
                    .setFont(createFont("Agency FB",100))
                    ;                                      

   myTextlabelC = cp5.addTextlabel("label3")
                    .setText("C")
                      .setPosition(500,210)
                    .setColor(color(255,255,255))
                    .setFont(createFont("Agency FB",100))
                    ;
  
  myTextlabelV = cp5.addTextlabel("label4")
                    .setText("Viraj Gandhi")
                      .setPosition(20,330)
                    .setColor(color(255,255,255))
                    .setFont(createFont("Agency FB",30))
                    ;
     myTextlabelV = cp5.addTextlabel("label5")
                    .setText("Interface Assginment Fabacademy 2017 "+"\n"+ "Servo Controller Via Serial Communication")
                      .setPosition(20,360)
                    .setColor(color(255,255,255))
                    .setFont(createFont("Agency FB",20))
                    ;

}

void draw() {
  background(color(44, 62, 80));  //rgb()

}
// THis function is for debuging
public void controlEvent(ControlEvent theEvent) {
  println(theEvent.getController().getName());

}



public void ServoA(int theValue) {
  println("Button A Pressed: "+theValue);
  myPort.write("a"+theValue+"\n");
myTextlabelA.setText("A"+theValue);
}

public void ServoB(int theValue) {
  println("Button B Pressed: "+theValue);
  myPort.write("b"+theValue+"\n");
 myTextlabelB.setText("B"+theValue);
}

public void ServoC(int theValue) {
  println("Button C Pressed: "+theValue);
  myPort.write("c"+theValue+"\n");  
  myTextlabelC.setText("C"+theValue);
}