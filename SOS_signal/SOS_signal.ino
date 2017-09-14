/* Code to make an Arduino Uno send out an SOS signal from pin 13 
 * by Emilie Karon Klefbom 
 * september 14 2017
 * v 1.0
 */
 
int alternate;                  // variable to change the lenght of the blink
int sigalLenght;                // variable to define the lenght of the blink

void setup() {
 Serial.begin(9600);
 pinMode(13, OUTPUT);           //pin 13 is the defined output

 for(int i = 1; i<=5; i++){     //the SOS singal runs 5 times
  
    for(int i = 1; i <=3; i++){ //Makes the blink alernate from long and short blinks
    alternate = i;
    if(alternate%2==1){
      signalLenght =200;
    }else{
      signalLenght=1000;
    }
    for(int i =1; i <=3; i++){
      
    digitalWrite(13, HIGH);
    delay(signalLenght);
    digitalWrite(13, LOW);
    delay(100);                 // Delay between blinks
    }
    delay(500);                 //Delay between "letters"
    }
    delay(2000);                //Delay between runs 
  }
}

void loop() {
  
}
