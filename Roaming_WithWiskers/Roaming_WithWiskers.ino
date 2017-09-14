/* Code to allow BOE bot to move around a room using wisker sensors
 *  By Emilie Karon Klefbom
 *  September 14 2017
 *  v 1.0
 */
 
#include <Servo.h>      // Include the servo library

Servo servoL;           // Define servoL and servoR
Servo servoR;

byte wLeft = digitalRead(5),  //Define bytes that are read when the wiskers makes contact
     wRight = digitalRead(7),
     wLeftOld = 0,            //Define bytes for corner evasion
     wRightOld = 1;
     
int counter = 0;              // Define counter for corner navigation

void setup() {
  tone(4,3000,500);           //Play tone for 1 second
  pinMode(7, INPUT);          //Set right wisker to input
  pinMode(5, INPUT);          //Set left wisker to input
  
  delay(1000);                 //Wait 1 second before start
  
  servoAttach();              //Attach sevos
  
}

void loop() {
  
  if((wLeft == 0) && (wRight == 0)){
    backward(1000);
    turnTL(800);
  }else if(wLeft == 0){
    backward(1000);
    turnTR(400);
  }else if(wRight == 0){
    backward(1000);
    turnTL(400);
  }else{
    forward(20);
  }
  

}

void turnBR(int time, int deg, boolean motor){ // motor true = left, false = right
  if(motor){
    servoL.writeMicroseconds(1500 + deg);
    servoR.writeMicroseconds(1500);
  }else{
    servoL.writeMicroseconds(1500);
    servoR.writeMicroseconds(1500-deg);
  }

  delay(time);
  servoStop();
}

void forward(int time)          // Backward function
{
  servoL.writeMicroseconds(1300); 
  servoR.writeMicroseconds(1700); 
  delay(time);                    // Maneuver for time ms
  servoStop();
}

void turnTL(int time)           // Left turn function
{
  servoL.writeMicroseconds(1300); // Left wheel clockwise
  servoR.writeMicroseconds(1300); // Right wheel clockwise
  delay(time);                    // Maneuver for time ms
  servoStop();
}

void turnDL(int deg)            // Right turn degrees
{
  int t = (deg / 0.176);
  t-=25;
  turnTL(t);
}

void turnTR(int time) // Right turn function
{
  servoL.writeMicroseconds(1700); // Left wheel counterclockwise
  servoR.writeMicroseconds(1700); // Right wheel counterclockwise
  delay(time); // Maneuver for time ms
  servoStop();
}

void turnDR(int deg) // Right turn degrees
{
  int t = (deg / 0.176);
  t -=25;
  turnTR(t);
}

void turnDeg(int deg) // Right turn degrees
{
  if(deg >0 ){
  turnDR(deg);
  }
  else{
  turnDL(-deg);
    }
}


void maneuver (int speedL, int speedR, int time){
  servoL.writeMicroseconds(1500 + speedL);
  servoR.writeMicroseconds(1500 - speedR);  
  delay(time);
  servoStop();
}

void servoDisable()             // Halt servo signals
{
servoL.detach();                // Stop sending servo signals
servoR.detach();
}

void servoStop(){
  servoL.writeMicroseconds(1500);
  servoR.writeMicroseconds(1500);
}
void servoAttach(){
  servoL.attach(11);
  servoR.attach(10);
}

void backward(int time)           // Backward function
{
  servoL.writeMicroseconds(1700); // Left wheel counterclockwise
  servoR.writeMicroseconds(1300); // Right wheel clockwise
  delay(time);                    // Maneuver for time ms
  servoStop();
}
