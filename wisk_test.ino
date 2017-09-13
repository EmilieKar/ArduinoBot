void setup() {
  tone(4, 3000, 1000); // Play tone for 1 second
delay(1000); // Delay to finish tone
pinMode(7, INPUT); // Set right whisker pin to input
pinMode(5, INPUT); // Set left whisker pin to input
pinMode(8, OUTPUT);
pinMode(2,OUTPUT);
Serial.begin(9600); // Set data rate to 9600 bps
}
void loop() // Main loop auto-repeats
{
byte wLeft = digitalRead(5); // Copy left result to wLeft
byte wRight = digitalRead(7); // Copy right result to wRight
Serial.print(wLeft); // Display left whisker state
Serial.println(wRight); // Display right whisker state

if(wLeft == 0){
  digitalWrite(8, HIGH);
}else{
  digitalWrite(8,LOW);
}

if(wRight == 0){
  digitalWrite(2, HIGH);
}else{
  digitalWrite(2,LOW);
}
delay(50); 
}
