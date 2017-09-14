/* Code to test the Arduino BOE bots wiskers sensors by reading bytes of the serial  monitor
 *  and lighting up LED, inspired by the BOE bot manual 
 *  By Emilie Karon Klefbom
 *  September 14 2017
 *  v 1.0
 */

void setup() {
  tone(4, 3000, 1000);    // Play tone for 1 second
  delay(1000);            // Delay to finish tone
  pinMode(7, INPUT);      // Set right whisker pin to input
  pinMode(5, INPUT);      // Set left whisker pin to input
  pinMode(8, OUTPUT);     // Set right LED to pin 8
  pinMode(2,OUTPUT);      // Set left LED to pin 2
  Serial.begin(9600);     // Set data rate to 9600 bps
}


void loop(){
  byte wLeft = digitalRead(5);  // Copy left result to wLeft
  byte wRight = digitalRead(7); // Copy right result to wRight
  Serial.print(wLeft);          // Display left whisker state
  Serial.println(wRight);       // Display right whisker state
  
  if(wLeft == 0){               //Light up LED when left wisker makes contact
    digitalWrite(8, HIGH);
  }else{
    digitalWrite(8,LOW);
  }
  
  if(wRight == 0){              //Light up LED when right wisker makes contact
    digitalWrite(2, HIGH);
  }else{
    digitalWrite(2,LOW);
  }
  
  delay(50);                    //Delay between updates
}
