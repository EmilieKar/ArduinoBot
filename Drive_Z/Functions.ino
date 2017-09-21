

void turnServos(int speedL, int speedR){
  short Ltrim= -5;//trim is to conpensate for irregular movement
  short Rtrim= 0;//it works in straitacceleration,needs aditional testing
  servoL.writeMicroseconds(1500-speedL+Ltrim);
  servoR.writeMicroseconds(1500+speedR+Rtrim);
}

void turnServos(int speed){
  turnServos(speed, speed);
}

void turnAcceleration(int dir){
  if(dir>0){
    for(int i = 0; i < 100; i+= 5){
    turnServos(i*dir, -i*dir);
    delay(50);
    }
  }else{
    for(int i = 0; i<100; i+=5){
      turnServos(100-i, -(100-i));
      delay(50);
    }
  }
}

void driveTurn(int deg){

  
  turnAcceleration(1);
  turnServos(100,-100);
  if(deg>60){
    delay(deg / 0.176);
  }
  turnAcceleration(-1);
  servoStop();
  
}

void straightAcceleration(int dir){//the lenght of the acceleration is ~110mm at dir =1
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

void pivitAcceleration(int dir, bool ad){//ad acceleration or deaccerleration, if tru, acceerate
//the purpose of this class is to make a standard if you dont want to define deg
pivitAcceleration(dir,0,ad,true); 

}
void pivitAcceleration(int dir,int deg, bool ad,bool standStill){//ad acceleration or deaccerleration, if tru, acceerate
    //Standstill is if it's starting from a stand still, if true smooth acceleration of left wheel, else no acceleraton
  int  Aspeed=10; //acceleration speed
  int IttSpeed = 40; //speed of the itteration aka he delay time
  if(deg ==0){
    //if no deg number was given defaluts are set 
    // oryou might say they dont cahnge
    } else{
      Aspeed = (100/sqrt(deg));
      IttSpeed = sqrt(deg)*3;
      }
  if(dir>0 && ad){
    if(standStill){
    for(int i = 0; i<100; i+=Aspeed){
      turnServos(i, 5);
      delay(IttSpeed);
    }
    }else{
      for(int i = 0; i<90; i+=Aspeed){
        turnServos(100-i,100);
        delay(IttSpeed);
        
        }
      }
  }else if(dir <0 && ad){
    for(int i = 0; i<100; i+=Aspeed){
      turnServos(5, i);
      delay(IttSpeed);
    }
  }else if(dir <0){
    for(int i = 0; i<100; i+=Aspeed){
      turnServos(5, 100-i);
      delay(IttSpeed);
    }
  }else{
    for(int i = 0; i<100; i+=Aspeed){
      turnServos(100-i, 5);
      delay(IttSpeed);
    }
  }
  
}

void playSong( int musicPin){
short tones1[]   = {1175,1319,1480,1760,1480,1480,1319,1480,1319,1175,1480,1760,1976,2217,2093,1760,1480,1568,1480,1319,1175,1319,1480,1760,1480,1319,1175,1319,1175,1480,1760,1976,1760,1480,1480,1319,1175,1319,1175,1175,1319,1480,1480,1480,1760,1976,1760,1319,1175,1319,880,988,1109,1109,1175,988,-1337}; //allways end with -1337
short lengths1[] = {120,120,480,600,120,120,120,120,120,1200,480,240,960,240,480,240,720,120,120,720,120,120,480,480,120,360,360,120,1200,480,240,960,480,480,960,960,120,120,1680,120,120,240,240,240,80,80,80,240,240,240,120,120,240,480,240,240,-1337}; //allways end with -1337
int timings1[]   = {3840,3960,4080,4560,5160,5280,5400,5520,5640,5760,6960,7440,7680,8640,8880,9360,9600,10320,10440,10560,11280,11400,11520,12000,12480,12600,12960,13320,13440,14640,15120,15360,16320,16800,17280,18240,19200,19320,19440,23040,23160,23280,24240,24720,24960,25040,25120,25200,25440,25680,26880,27000,27120,27600,28080,28560,-1337}; //allways end with -1337


long tOld = millis();
int i =0;
  while(tones1[i != -1337] && millis()-tOld<22000 ){
    
  if(tones1[i != -1337] ){
    if(millis()-tOld>timings1[i]){
      tone(musicPin,tones1[i],lengths1[i]);
      i++;
    }
  }
  
  }
  }

void drivePivit(int dir, int deg){
  pivitAcceleration(dir, true);
  if(deg>60){
    delay(deg/2);
  }
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
