void backward(int time) // Backward function
{
  servoL.writeMicroseconds(1700); // Left wheel counterclockwise
  servoR.writeMicroseconds(1300); // Right wheel clockwise
  delay(time); // Maneuver for time ms
  
  servoStop();
}

void turnServos(int speedL, int speedR){
  servoL.writeMicroseconds(1500-speedL);
  servoR.writeMicroseconds(1500+speedR);
}

void turnServos(int speed){
  turnServos(speed, speed);
}

void straightAcceleration(int dir){
  for(int i = 0; i < 100; i+= 5){
    turnServos(i*dir);
    delay(50);
  }
  
}

void driveStraight(double distance){
  int dir = 0;
  if(distance>0){
    dir = 1;
  }else{
    dir = -1;
  }

  int time = int((distance-17.5)/(0.0155));
  
  straightAcceleration(dir);
  turnServos(100);
  
  delay(time);

  straightAcceleration(-dir);
  servoStop();
  
}

void forward(int time) // Forward function
{
  servoL.writeMicroseconds(1300); // Left wheel clockwise
  servoR.writeMicroseconds(1700); // Right wheel counterclockwise
  delay(time); // Maneuver for time ms
  
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
void servoAttach(){
  servoL.attach(11);
  servoR.attach(10);
}
