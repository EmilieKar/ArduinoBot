void servoAttach(){
  servoL.attach(11);
  servoR.attach(10);
}  
  
void backwards() // Backward function
{
 
servoL.writeMicroseconds(1600); // Left wheel counterclockwise
servoR.writeMicroseconds(1400); // Right wheel clockwise

}

void forward() // Backward function
{

servoL.writeMicroseconds(1450); // Left wheel clockwise
servoR.writeMicroseconds(1550-5); // Right wheel counterclockwise

}

void turnTL(int time) // Left turn function
{
servoL.writeMicroseconds(1450); // Left wheel clockwise
servoR.writeMicroseconds(1450); // Right wheel clockwise
delay(time); // Maneuver for time ms

}

void turnDL(int deg) // Right turn degrees
{
  int t = (deg / 0.176);
  t-=25;
  turnTL(t);
}

void turnTR(int time) // Right turn function
{
servoL.writeMicroseconds(1550); // Left wheel counterclockwise
servoR.writeMicroseconds(1550); // Right wheel counterclockwise
delay(time); // Maneuver for time ms

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



void maneuver (int speedL, int speedR){
  servoL.writeMicroseconds(1500 - speedL);
  servoR.writeMicroseconds(1500 + speedR);  

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

