int tones1[]   = {1245,1319,1245,1319,988,1175,1047,880,1047,220,440,440,659,880,988,880,330,494,494,831,988,1047,988,220,440,440,1319,1245,1319,1245,1319,988,1175,1047,880,1047,220,440,440,659,880,-1337};//ALLWAYS end this with a -1337
int lengths1[] = {8,8,8,8,8,8,8,0,472,423,8,26,8,8,0,472,423,8,26,8,8,0,472,423,8,26,8,8,8,8,8,8,8,8,0,472,423,8,26,8,8,-1337};//ALLWAYS end this with a -1337
int timings1[] = {2400,2880,3360,3840,4320,4800,5280,5760,5768,6248,6720,7174,7680,8160,8640,8648,9128,9600,10054,10560,11040,11520,11528,12008,12480,12934,13440,13920,14400,14880,15360,15840,16320,16800,17280,17288,17768,18240,18694,19200,19680,-1337};//ALLWAYS end this with a -1337
int tones2[]   = {-1337};
int lengths2[] = {-1337};//end with -1337 on thses too
int timings2[] = {-1337};
long tOld;
long TNew;
int i = 0;
int j = 0;
int pin1 = 11;
int pin2 = 12;

void setup() {
  // put your setup code here, to run once:
pinMode(pin1,OUTPUT);
pinMode(pin2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
delay(2000);
play(pin1,pin2);
}

void play(int pin1,int pin2){
  tOld = millis();
  while(tones1[i != -1337]){
    if(millis()-tOld>timings1[i]){
      tone(pin1,tones1[i],lengths1[i]);
      i++;
    }
    
  }

  while(tones2[j != -1337]){
    if(millis()-tOld>timings2[j]){
      tone(pin2,tones2[j],lengths2[j]);
      j++;
    }
    delay(1);
  }
  
}
  
  
