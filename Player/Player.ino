short tones1[]   = {1175,1319,1480,1760,1480,1480,1319,1480,1319,1175,1480,1760,1976,2217,2093,1760,1480,1568,1480,1319,1175,1319,1480,1760,1480,1319,1175,1319,1175,1480,1760,1976,1760,1480,1480,1319,1175,1319,1175,1175,1319,1480,1480,1480,1760,1976,1760,1319,1175,1319,880,988,1109,1109,1175,988,-1337}; //allways end with -1337
short lengths1[] = {120,120,480,600,120,120,120,120,120,1200,480,240,960,240,480,240,720,120,120,720,120,120,480,480,120,360,360,120,1200,480,240,960,480,480,960,960,120,120,1680,120,120,240,240,240,80,80,80,240,240,240,120,120,240,480,240,240,-1337}; //allways end with -1337
int timings1[]   = {3840,3960,4080,4560,5160,5280,5400,5520,5640,5760,6960,7440,7680,8640,8880,9360,9600,10320,10440,10560,11280,11400,11520,12000,12480,12600,12960,13320,13440,14640,15120,15360,16320,16800,17280,18240,19200,19320,19440,23040,23160,23280,24240,24720,24960,25040,25120,25200,25440,25680,26880,27000,27120,27600,28080,28560,-1337}; //allways end with -1337

//Acctually channel 2
short tones3[]    = {880,880,1175,1175,1109,1175,880,1175,1175,1109,880,740,740,659,659,587,587,-1337};
short lenghts3[]  = {1920 , 1920 , 1920 , 960 , 960 , 1920 , 1920 , 1920 , 960 , 960 , 1920 , 480 , 480 , 480 , 480 , 480 , 480 ,-1337};
int timings3[]    = {3840 , 5760 , 7680 , 9600 , 10560 , 11520 , 13440 , 15360 , 17280 , 18240 , 19200 , 23520 , 24000 , 25440 , 25920 , 27360 , 27840 ,-1337};
//tones 2 is acctualy channel 3
short tones2[]   = {294 , 440 , 587 , 440 , 294 , 440 , 587 , 370 , 440 , 587 , 440 , 370 , 294 , 370 , 294 , 392 , 294 , 392 , 294 , 440 , 294 , 440 , 440 , 294 , 440 , 587 , 440 , 294 , 370 , 440 , 587 , 440 , 392 , 294 , 392 , 587 , 440 , 494 , 370 , 494 , 440 , 440 , 294 , 440 , 587 , 440 , 294 , 440 , 587 , 440 , 587 , 587 , 554 , 554 , 494 , 494 , 587 , 587 ,-1337}; //allways end with -1337
short lengths2[] = {480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 240 , 240 , 960 , 480 , 480 , 480 , 480 , 480 , 240 , 240 , 480 , 480 , 480 , 480 , 240 , 240 , 480 , 480 , 480 , 240 , 240 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 , 480 ,-1337}; //allways end with -1337
int timings2[]   = {0 , 480 , 960 , 1440 , 1920 , 2400 , 2880 , 3840 , 4320 , 4800 , 5280 , 5760 , 6240 , 6720 , 7200 , 7680 , 8160 , 8640 , 9120 , 9600 , 9840 , 10080 , 11040 , 11520 , 12000 , 12480 , 12960 , 13440 , 13680 , 13920 , 14400 , 14880 , 15360 , 15840 , 16080 , 16320 , 16800 , 17280 , 17760 , 18000 , 18240 , 18720 , 19200 , 19680 , 20160 , 20640 , 21120 , 21600 , 22080 , 22560 , 23520 , 24000 , 25440 , 25920 , 27360 , 27840 , 32160 , 32640 ,-1337}; //allways end with -1337
long tOld;

int i = 0;
int j = 0;

int pin1 = 4;
int pin2 = 3;


void setup() {
  // put your setup code here, to run once:
pinMode(pin1,OUTPUT);
pinMode(pin2,OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
delay(2000);
play(pin1);
}

void play(int pin1){


  tOld = millis();
  while(tones1[i != -1337]  ){
    
  if(tones1[i != -1337]){
    if(millis()-tOld>timings1[i]){
      tone(pin1,tones1[i],lengths1[i]);
      i++;
    }
  }




	


    
  
  delay(1);
}
  }
  
  
  
