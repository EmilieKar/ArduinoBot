  #include <Servo.h>
 Servo servoL;
 Servo servoR;
 double lastTime,lastInc; 
 boolean lightsOff=true;
 int irLeft, irRight;
   int i = 0;
  int old = 0;
  boolean right;
  
 
void setup()                                 // Built-in initialization block
{

  tone(4, 3000, 1000);                       // Play tone for 1 second   
  delay(1000);                               // Delay to finish tone   
  pinMode(12, INPUT);  pinMode(9, OUTPUT);   // Left IR LED & Receiver
  pinMode(3, INPUT); pinMode(2, OUTPUT);      //Right IR
  Serial.begin(9600); 
  pinMode(7, OUTPUT);
 pinMode(6, OUTPUT);
 digitalWrite(6,LOW);
// digital
  servoAttach();


}
  
 
void loop()                                  // Main loop auto-repeats
{
  if(lightsOff){
    
  
  if(millis()>(lastTime+50)){                //makes a delay of 5ms 
    lastTime = millis();
    irLeft = irDetect(9, 12, 38000);       // Check for object                    // Display 1/0 no detect/detect
    irRight = irDetect(2, 3, 38000);       // Check for object
    Serial.print(irLeft);  
    Serial.println(irRight);
    
  }
 /* 
  if(irLeft==1 && irRight==1){
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    forward();
  }else if(irLeft==1 && irRight==0){
      maneuver(100,-100);
      digitalWrite(7,LOW);
      digitalWrite(6,HIGH);
  }else if(irLeft==0 && irRight==1){
      maneuver(-100,100);
      digitalWrite(7,HIGH);
      digitalWrite(6,LOW);
  }
  else{
    backwards();
    digitalWrite(7,HIGH);
    digitalWrite(6,HIGH);
    delay(100);
    
    }
    

*/

  if (i >=4){
    if(right){
      turnDL(80);

      }
      else{
      turnDR(80);

      }
      
    i = 0;
    
  }
  if(lastInc<millis()-300){       //if the last hit wall was 300ms ago, reset i
    i = 0;
    }
  if(irLeft==1 &&irRight==1){  
  forward();
  delay(20);
  }
  if(irLeft == 0 ){               //Light up LED when left wisker makes contact
    digitalWrite(7, HIGH);

    turnDR(20);
    if(i==0){
      right = false;
      }
    if(old == 2){
      i++;
      lastInc =millis();
    }
    old = 1;
  }else{
    digitalWrite(7,LOW);
  }
  
  if(irRight == 0){              //Light up LED when right wisker makes contact
    digitalWrite(6, HIGH);

    turnDL(20);
    if (i==0 ){
      right = true;
      }
    
    if(old ==1){
      i++;
      lastInc=millis();
    }
    old = 2;
  }else{
    digitalWrite(6,LOW);
  }
  // ------------------                                 
}
}


// IR Object Detection Function

int irDetect(int irLedPin, int irReceiverPin, long frequency)
{
  tone(irLedPin, frequency, 8);              // IRLED 38 kHz for at least 1 ms   
  delay(1);                                  // Wait 1 ms
  int ir = digitalRead(irReceiverPin);       // IR receiver -> ir variable   
  delay(1);                                  // Down time before recheck   
  return ir;                                 // Return 1 no detect, 0 detect
} 
