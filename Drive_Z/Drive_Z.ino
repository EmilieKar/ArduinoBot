/* Code for driving the BO bot in a Z formation
 *  By Emilie Karon Klefbom 
 *  September 14 2017
 *  v 1.0
 */

 #include <Servo.h>

 Servo servoL;
 Servo servoR;
 
void setup() {
  tone(4, 500, 1000);
  delay(1000);

  servoAttach();
pivitAcceleration(1, false);
tone(4,500,1000);
  
/*
driveStraight(17.5);
drivePivit(-1,50);
driveStraight(35);
drivePivit(1,1300);
driveStraight(17.5);

turnDR(180);

delay(1000);
driveStraight(17.5);
drivePivit(-1,50);
driveStraight(35);
drivePivit(1,1300);
driveStraight(17.5);
*/
  servoDisable();

}

void loop() {
  // put your main code here, to run repeatedly:

}


