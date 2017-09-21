/* Code for driving the BO bot in a Z formation
 *  By Emilie Karon Klefbom  and David Johansson
 *  September 14 2017
 *  v 1.0
 */

 #include <Servo.h>
  int musicPin = 3;
 Servo servoL;
 Servo servoR;
 
void setup() {
  tone(4, 500, 300);
  delay(1000);
  pinMode(musicPin,OUTPUT);
  servoAttach();
//20cm forward
straightAcceleration(1);
turnServos(100);
delay(100);

//120deg right
turnServos(10,100);
delay(1300);
pivitAcceleration(-1,135, false,true);

//50cm forward
straightAcceleration(1);
turnServos(100);
delay(1100);


//120 left
turnServos(100,10);
delay(1450);
pivitAcceleration(1,135, false,true);



//20cm forward
straightAcceleration(1);
turnServos(100);
delay(100);

//180deg turn
turnDR(180);

servoDisable();
//playSong(musicPin);
delay(1000);
servoAttach();

//20cm forward
straightAcceleration(1);
turnServos(100);
delay(100);


//120deg right
turnServos(10,100);
delay(1300);
pivitAcceleration(-1,125, false,true);

//50cm forward
straightAcceleration(1);
turnServos(100);
delay(1050);


//120 left
turnServos(100,10);
delay(1450);
pivitAcceleration(1,125, false,true);



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


