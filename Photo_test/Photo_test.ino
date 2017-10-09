#include <Servo.h>                           // Include servo library
 
Servo servoLeft;                             // Declare left and right servos
Servo servoRight;

float volts(int adPin)                       // Measures volts at adPin 
{                                            // Returns floating point voltage  
  return float(analogRead(adPin)) * 5.0 / 1024.0; 
  }   
  
void setup()                                 // Built-in initialization block
{
  Serial.begin(9600); // Set data rate to 9600 bps 
  servoLeft.attach(11);                      // Attach left signal to pin 13   
  servoRight.attach(10);   

  servoLeft.writeMicroseconds(1700);         // Full speed forward   
  servoRight.writeMicroseconds(1300);
  }
void loop()                                  // Main loop auto-repeats
{
  Serial.print("A3 = ");                     // Display "A3 = "
  Serial.print(volts(A3));                    // Display measured A3 volts   
  Serial.println(" volts");                  // Display " volts" & newline
  if(volts(A3) > 0.37)                        // If A3 voltage greater than 3.5
  {
    servoLeft.detach();                      // Stop servo signals     
    servoRight.detach();

}
}
                                             
 

