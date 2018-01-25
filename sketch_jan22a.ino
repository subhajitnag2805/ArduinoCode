
int randomNumber;
int Signal = -1;
//Set up - this is where you get things "set-up". It will only run once
void setup() {
  
  //setup serial communications through the USB
  Serial.begin(9600);
  pinMode(9, OUTPUT);           // set pin to input
      
}//close setup

void loop() { 
  
   while(!Serial.available());
     Signal = Serial.read();
     if(Signal == 5){
        generateRandomNumber();
     }
}

void generateRandomNumber(){
  for (int i = 0; i < 100; i++) {
       randomNumber = random(1,5);
       Serial.write(randomNumber);
       if(randomNumber >= 3){
           digitalWrite(9,HIGH);
       }else{
           digitalWrite(9,LOW);
       }
       delay(1000);
  }
}

