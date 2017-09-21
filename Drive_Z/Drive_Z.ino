/* Code for driving the BOE bot in a Z formation
 *  By Emilie Karon Klefbom  and David Johansson
 *  September 14 2017
 *  v 1.0
 */

 #include <Servo.h>
  int musicPin = 4;
 Servo servoL;
 Servo servoR;
 
void setup() {
  tone(musicPin, 500, 300);
  delay(1000);
  pinMode(musicPin,OUTPUT);
  servoAttach();
  
//20cm forward
straightAcceleration(1);
turnServos(100);
delay(100);

//120deg right
turnServos(10,100);
delay(1250);
pivitAcceleration(-1,125, false,true);

//50cm forward
straightAcceleration(1);
turnServos(100);
delay(1350);


//120 left
turnServos(100,10);
delay(1400);
pivitAcceleration(1,130, false,true);



//20cm forward
straightAcceleration(1);
turnServos(100);
delay(130);


//180deg turn
turnDR(175);


servoDisable();
playSong(musicPin); //THIS IS WHEN IT TURNS
delay(1000);
servoAttach();

//20cm forward
straightAcceleration(1);
turnServos(100);
delay(130);


//120deg right
turnServos(10,100);
delay(1270);
pivitAcceleration(-1,120, false,true);

//50cm forward
straightAcceleration(1);
turnServos(100);
delay(1350);


//120 left
turnServos(100,10);
delay(1400);
pivitAcceleration(1,115, false,true);



//20cm forward
straightAcceleration(1);
turnServos(100);
delay(100);


/*
turnServos(100);
delay(1000);
turnServos(10,100);
turnServos(10,100);
delay(1300);
pivitAcceleration(1,120, false,false);
straightAcceleration(1);
turnServos(100);
delay(100);

*/
tone(4,1000,100);
  

  servoDisable();

}

void loop() {
  // put your main code here, to run repeatedly:

}


