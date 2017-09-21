void servoAttach(){
  servoL.attach(11);
  servoR.attach(10);
}  
  
void backward(int time) // Backward function
{
 
servoL.writeMicroseconds(1600); // Left wheel counterclockwise
servoR.writeMicroseconds(1400); // Right wheel clockwise
delay(time); // Maneuver for time ms

servoStop();
}

void forward(int time) // Backward function
{

servoL.writeMicroseconds(1400); // Left wheel clockwise
servoR.writeMicroseconds(1600); // Right wheel counterclockwise
delay(time); // Maneuver for time ms

servoStop();
}

void turnTL(int time) // Left turn function
{
servoL.writeMicroseconds(1400); // Left wheel clockwise
servoR.writeMicroseconds(1400); // Right wheel clockwise
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
servoL.writeMicroseconds(1600); // Left wheel counterclockwise
servoR.writeMicroseconds(1600); // Right wheel counterclockwise
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

