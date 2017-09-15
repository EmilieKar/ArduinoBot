int tones[]   = {1568,1760,1397,698,-1337};//ALLWAYS end this with a -1337
int lengths[] = {960,960,960,960,-1337};//ALLWAYS end this with a -1337
int timings[] = {0,960,1920,2880,-1337};//ALLWAYS end this with a -1337
long tOld;
long TNew;
int i = 0;
int pin = 11;

void setup() {
  // put your setup code here, to run once:
pinMode(pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
delay(2000);
play(pin);
}

void play(int pin){
  tOld = millis();
  while(tones[i != -1337]){
    if(millis()-tOld>timings[i]){
      tone(pin,tones[i],lengths[i]);
      i++;
    }
    delay(1);
  }
}
  
  
