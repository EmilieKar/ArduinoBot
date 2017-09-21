/* Code to allow BOE bot to move around a room using wisker sensors
 *  By Emilie Karon Klefbom
 *  September 14 2017
 *  v 1.0
 */

#include <Servo.h>

 Servo servoL;
 Servo servoR;
  int i = 0;
  int old = 0;

void setup() {
  tone(4, 3000, 1000);    // Play tone for 1 second
  delay(1000);            // Delay to finish tone
  pinMode(7, INPUT);      // Set right whisker pin to input
  pinMode(5, INPUT);      // Set left whisker pin to input
  pinMode(8, OUTPUT);     // Set right LED to pin 8
  pinMode(2,OUTPUT);      // Set left LED to pin 2
  Serial.begin(9600);     // Set data rate to 9600 bps
  servoAttach();
  
}


void loop(){
  byte wLeft = digitalRead(5);  // Copy left result to wLeft
  byte wRight = digitalRead(7); // Copy right result to wRight
  /*
  Serial.print(wLeft);          // Display left whisker state
  Serial.println(wRight);       // Display right whisker state
  */
  if (i >=4){
    turnDR(180);
    i = 0;
  }
  forward(50);
  
  if(wLeft == 0){               //Light up LED when left wisker makes contact
    digitalWrite(8, HIGH);
    backward(500);
    turnDR(40);
    if(old == 2){
      i++;
    }
    old = 1;
  }else{
    digitalWrite(8,LOW);
  }
  
  if(wRight == 0){              //Light up LED when right wisker makes contact
    digitalWrite(2, HIGH);
    backward(500);
    turnDL(40);
    if(old ==1){
      i++;
    }
    old = 2;
  }else{
    digitalWrite(2,LOW);
  }
  
}
