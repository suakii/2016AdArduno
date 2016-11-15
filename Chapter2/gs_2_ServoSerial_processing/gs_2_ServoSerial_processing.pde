
import controlP5.*;
import processing.serial.*;

ControlP5 cp5;

int myColorBackground = color(0,0,0);
int knobValue = 100;

Knob servo;
Serial myPort;
void setup() {
  size(700,400);
  smooth();
  noStroke();
  
  cp5 = new ControlP5(this);
  println(Serial.list());
  
  servo = cp5.addKnob("knob")
               .setRange(0,180)
               .setValue(0)
               .setPosition(100,70)
               .setRadius(50)
               .setDragDirection(Knob.HORIZONTAL)
               ;
  myPort = new Serial(this, Serial.list()[0], 9600);       
  
}

void draw() {
  background(myColorBackground);
}


void knob(int theValue) {
  myColorBackground = color(theValue);
  sendMessage(theValue);
}


void keyPressed() {
  
}

void sendMessage(int theValue) {
    myPort.write(theValue);
    print("Send to Arduino: ");
    println(theValue);
}

void serialEvent(Serial p) {
  String message = myPort.readStringUntil(10);  
  if(message != null)
  {
    print("Received: ");
    println(message);
  }
}
