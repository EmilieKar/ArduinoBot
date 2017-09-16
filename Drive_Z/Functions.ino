

void turnServos(int speedL, int speedR){
  servoL.writeMicroseconds(1500-speedL);
  servoR.writeMicroseconds(1500+speedR);
}

void turnServos(int speed){
  turnServos(speed, speed);
}

void straightAcceleration(int dir){
  if(dir>0){
    for(int i = 0; i < 100; i+= 5){
    turnServos(i*dir);
    delay(50);
    }
  }else{
    for(int i = 0; i<100; i+=5){
      turnServos(100-i);
      delay(50);
    }
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

void pivitAcceleration(int dir, bool ad){
  if(dir>0 && ad){
    for(int i = 0; i<100; i+=5){
      turnServos(i, 5);
      delay(50);
    }
  }else if(dir <0 && ad){
    for(int i = 0; i<100; i+=5){
      turnServos(5, i);
      delay(50);
    }
  }else if(dir <0){
    for(int i = 0; i<100; i+=5){
      turnServos(5, 100-i);
      delay(50);
    }
  }else{
    for(int i = 0; i<100; i+=5){
      turnServos(100-i, 5);
      delay(50);
    }
  }
  
}
void drivePivit(int dir){
  pivitAcceleration(dir, true);
  delay(1000);
  pivitAcceleration(dir, false);
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
