  #include <Servo.h>
 Servo servoL;
 Servo servoR;
 double lastTime; 
 boolean lightsOff=true;
 int irLeft, irRight;
 
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

  if(irLeft==1 && irRight==1){
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    forward();
  }else if(irLeft==1 && irRight==0){
      maneuver(90,-10);
      digitalWrite(7,LOW);
      digitalWrite(6,HIGH);
  }else if(irLeft==0 && irRight==1){
      maneuver(-10,90);
      digitalWrite(7,HIGH);
      digitalWrite(6,LOW);
  }
  else{
    backwards();
    digitalWrite(7,HIGH);
    digitalWrite(6,HIGH);
    delay(100);
    
    }
    

                                 
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
