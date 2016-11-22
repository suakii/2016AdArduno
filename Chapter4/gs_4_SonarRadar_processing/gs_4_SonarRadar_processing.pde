import processing.serial.*;

Serial myPort;    // The serial port
String myString = null;  // Input string from serial port
int value;
boolean fail = false;

int rotation = 0;
int lengthValue = 0;
int[] lengthArray = new int[45];

int resolution = 150;

void setup() {
  size(720,360);
  surface.setResizable(true);
  ellipseMode(RADIUS);
  ellipseMode(CENTER);
  strokeWeight(1);
  stroke(255,0,0);
  // List all the available serial ports:
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 9600);
  myPort.bufferUntil('\n');
  
}

void draw() {
  background(0);
  pushMatrix();
  translate(width/2,height);
  drawRadar();
  int j = 0;
  stroke(0,255,255);
  strokeWeight(3);
  line(0,0,-max(width,height)*cos(radians(rotation)),-max(width,height)*sin(radians(rotation)));
  stroke(0,255,0);
  strokeWeight(1);
  for(int i : lengthArray){
    line(0,0,-(i*(width/resolution/2)*cos(radians(j))),-(i*(height/resolution))*sin(radians(j)));
    j++;
  }
  popMatrix();
}

void serialEvent(Serial p) {
  myString = p.readStringUntil('\n');
  if (myString != null) {
    
    myString = trim(myString);
    String[] list = split(myString, ',');
    rotation = int(list[0]);
    lengthValue = int(list[1]);
    
    if(rotation > 44)
    rotation = 89-rotation;
    
    lengthArray[rotation] = lengthValue; 
  }
}

void drawRadar(){
  stroke(0,255,0);
  line(0,0,-width/2,-height);
  line(0,0,0,-height);
  line(0,0,width/2,-height);
  noFill();
  arc(0,0, width/2, height, PI, PI+PI);
  arc(0,0, width, height*2, PI, PI+PI);
}
