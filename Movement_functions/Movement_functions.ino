/* Collections of functions for moving the BOE bot
 *  By: Emilie Karon Klefbom
 *  September 14 2017
 *  
 */
#include <Servo.h>

Servo servoL;
Servo servoR;

void setup() {
  // put your setup code here, to run once:
  tone(4, 500, 1000);
  delay(3000);

  servoAttach();
  int t = accelerate(1);
  forward(800-t);
  deccelerate(1);

  turnDL(120);
  accelerate(1);
  forward(1200-t);
  deccelerate(1);

  turnDR(120);

  accelerate(1);
  forward(800-t);
  deccelerate(1);
 

  servoDisable();

}

void loop() {
  // put your main code here, to run repeatedly:

}

void servoAttach(){
  servoL.attach(11);
  servoR.attach(10);
}

int accelerate(int speed){ //returns time (how long it was running)
  int  time = 0;
  int trim= 5; //how long the delay in each itteration is
  if(speed>0){ //If speed is posetive
    for(int i = 0;i<200; i = i + speed){
      servoL.writeMicroseconds(1500-i);
      servoR.writeMicroseconds(1500+i);
      delay(trim);
      time= time +trim;
     }
    }
  else{
    for(int i = 0; i>-200; i = i + speed){
      servoL.writeMicroseconds(1500-i);
      servoR.writeMicroseconds(1500+i);
      delay(trim);
      time= time +trim;
     }
    }
    return time;
    }



int deccelerate(int speed){
  int time = 0;
  int trim = 5;
  if(speed<0){ //If speed is posetive
    for(int i = 0;i<200; i = i - speed){
      servoL.writeMicroseconds(1700-i);
      servoR.writeMicroseconds(1300+i);
      delay(trim);
      time= time +trim;
     }
    }
  else{
    for(int i = 0; i<-200; i = i + speed){
      servoL.writeMicroseconds(1300-i);
      servoR.writeMicroseconds(1700+i);
      delay(trim);
      time= time +trim;
     }
    }
    return time;
    }
  
  
void backward(int time) // Forward function
{
 
servoL.writeMicroseconds(1700); // Left wheel counterclockwise
servoR.writeMicroseconds(1300); // Right wheel clockwise
delay(time); // Maneuver for time ms

servoStop();
}

void forward(int time) // Backward function
{

servoL.writeMicroseconds(1300); // Left wheel clockwise
servoR.writeMicroseconds(1700); // Right wheel counterclockwise
delay(time); // Maneuver for time ms

servoStop();
}

void turnTL(int time) // Left turn function
{
servoL.writeMicroseconds(1300); // Left wheel clockwise
servoR.writeMicroseconds(1300); // Right wheel clockwise
delay(time); // Maneuver for time ms
servoStop();
}

void turnDL(int deg) // Right turn degrees
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

void servoDisable() // Halt servo signals
{
servoL.detach(); // Stop sending servo signals
servoR.detach();
}

void servoStop(){
  servoL.writeMicroseconds(1500);
  servoR.writeMicroseconds(1500);
}

