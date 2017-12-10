/*
  PingSensor

  by Emilie Karon KLefbom
  07/12/2017
*/

#include <Servo.h>
 Servo servoL;
 Servo servoR;
 Servo servoH;

 //Last seen distance
 int front, left, right;
 const int pingPin = 7;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);

  //Attach all motors
  servoAttach();

  // Play tone for 1 second   
  tone(4, 3000, 1000); 
  delay(1000);  
}

void loop() {
  servoH.write(0);
  delay(300);
  right = check();
  rightcheck();
  servoH.write(90);
  delay(300);
  front = check();
  frontcheck();
  servoH.write(180);
  delay(300);
  left = check();
  leftcheck();
  servoH.write(90);
  delay(300);
  front = check();
  frontcheck();
  forward();
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  return microseconds / 29 / 2;
}

int check(){
  // establish variables for duration of the ping, and the distance result
  // in centimeters:
  long duration, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the detector: a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  return cm;
}

//If an object is closer than 10cm in front then
//compare left right and turn 
void frontcheck(){
  if(front < 10){
    if(left > right){
      turnDL(90);
    }else if(right > left){
      turnDR(90);
    }
  }
}

//if an object is closer than 18cm on the left: turn right
void leftcheck(){
  if(left < 10){
    turnDR(30);
    Serial.print("left");
  }
}

//if an object is closer than 18cm on the right: turn left
void rightcheck(){
  if(right < 10){
    turnDL(30);
    Serial.print("right");
  }
}

