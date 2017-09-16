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

driveStraight(50);
drivePivit(1);
driveStraight(50);
drivePivit(-1);

  servoDisable();

}

void loop() {
  // put your main code here, to run repeatedly:

}


