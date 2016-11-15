import processing.serial.*;

Serial myPort;
short portIndex = 0;
PFont f;  // Font object declaration
public static final char HEADER = 'H';

// Part 1. LED control
public static int button4 = 0;
public static int button5 = 0;
public static int button6 = 0;
public static int button7 = 0;

public static final char LED_TAG = 'L';
public static int  LED4 = 4;
public static int  LED5 = 5;
public static int  LED6 = 6;
public static int  LED7 = 7;

public static int  ON = 1;
public static int  OFF = 0;

void setup() {
  size (200,225);
  f = createFont("Georgia-Bold", 20, true); // font creating for text

  String portName = Serial.list()[portIndex];
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  background(255);
 
// Structure Setup
  stroke(0);  // outer line of polygon, 0: black, 255: LED5
  fill(0);
  line(100,0,100,200);
  line(0,100,200,100);
  line(0,200,200,200);
  line(0,225,200,225);
 
// Text Setup 
  textFont(f,16);
  fill(0);
  textAlign(CENTER);

// Part 1. LED control
  text("LED4",50,95);
  text("LED5",150,95);
  text("LED6",50,195);
  text("LED7",150,195);
  text("You are the BEST",100,220);

// Button Setup

// Part 1. LED control
  if (button4 == ON) {
    fill(255,0,0);   // LED1
    ellipse(50,50,50,50);
  } else {
    fill(125,125,125);
    ellipse(50,50,50,50);
  }
  if (button5 == ON) {
    fill(0,255,0);  // LED2
    ellipse(150,50,50,50);
  } else {
    fill(125,125,125);
    ellipse(150,50,50,50);
  } 
  if (button6 == ON) {
    fill(0,0,255);  // LED3
    ellipse(50,150,50,50);
  } else {
    fill(125,125,125);
    ellipse(50,150,50,50);  
  }
  if (button7 == ON) {
    fill(255,255,255);  // LED4
    ellipse(150,150,50,50);
  } else {
    fill(125,125,125);  // GRAY
    ellipse(150,150,50,50);
  }
}

void mousePressed() 
{

// Part 1. LED control  
  if (mouseX <100 && mouseY <100) {
      println("LED4 Clicked");
      if (button4 == ON) {
        button4 = OFF;
      }
      else if (button4 == OFF) {
        button4 = ON;
      }
      sendMessage(LED_TAG, LED4, button4);
    }
    if (mouseX >100 && mouseX <200 && mouseY <100) {
      println("LED5 Clicked");
      if (button5 == ON) {
        button5 = OFF;
      }
      else if (button5 == OFF) {
        button5 = ON;
      }
      sendMessage(LED_TAG, LED5, button5);
    }
    if (mouseX <100 && mouseY >100 && mouseY <200) {
      println("LED6 Clicked");
      if (button6 == ON) {
        button6 = OFF;
      }
      else if (button6 == OFF) {
        button6 = ON;
      }
      sendMessage(LED_TAG, LED6, button6);
    }
    if (mouseX >100 && mouseX <200 && mouseY >100 && mouseY <200) {
      println("LED7 Clicked");
      if (button7 == ON) {
        button7 = OFF;
      }
      else if (button7 == OFF) {
        button7  = ON;
      }
      sendMessage(LED_TAG, LED7, button7);
    }
}
void sendMessage(char tag, int led, int button)
{
  print("Send to Arduino: ");
  println("H " + tag + " 0 " + led + " 0 " + button);
  myPort.write(HEADER);//H
  myPort.write(tag);//L
  myPort.write(0);  // msb
  myPort.write(led);  // lsb 1,2,3,4
  myPort.write(0);  // msb
  myPort.write(button);  // lsb  0, 1
}
void serialEvent(Serial p)
{
  String message = myPort.readStringUntil(10);  
  if(message != null)
  {
    print("Received: ");
    println(message);
  
  int []data = int(split(message, ','));
    
    print(data[0]);
    print(",");
    println(data[1]);
    
    if (data[0] == 4) {
      if (data[1] == 1)
        button4 = ON;
      else
        button4 = OFF;
    }
     if (data[0] == 5) {
      if (data[1] == 1)
        button5 = ON;
      else
        button5 = OFF;
    }
     if (data[0] == 6) {
      if (data[1] == 1)
        button6 = ON;
      else
        button6 = OFF;
    }
     if (data[0] == 7) {
      if (data[1] == 1)
        button7 = ON;
      else
        button7 = OFF;
    }
  }
}