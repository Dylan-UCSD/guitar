#include <Servo.h>
#define MAX_ANGLE 60

int interrupt[8] = {2,3,18,19,20,21};
Servo servoA,servoB,servoC,servoD,servoE,servoF;
Servo servoArray[6] = {servoA,servoB,servoC,servoD,servoE,servoF};
//Servo servoNotes[15] = {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o};
int servoState[6] = {0,0,0,0,0,0};
const int signalin = 9;
int interruptNumber = 0;
unsigned long debounce = 100;     // Debounce delay for cleaner interrupt input
unsigned long buttonStartTime = 0;// Record button start time

void interruptdetected(){
  if (millis() - buttonStartTime < debounce) { // Debounce
    return;
  }
  buttonStartTime = millis();
  interruptNumber = interruptNumber + 1;    // Once the Arduino detects the right change in the interrupt pin, it will run this function
  Serial.print("Interrupt number: ");
  Serial.println(interruptNumber);
  sendServo(&servoF);
}
void sendServo(Servo* serv){
    Serial.println(serv->read());
    if(serv->read() == 0){
      for(int pos = 0; pos <= MAX_ANGLE; pos++){
        serv->write(pos);  
        //delay(5);
      }
    }else{
      for(int pos = MAX_ANGLE; pos >= 0; pos--){
        serv->write(pos);
        //delay(5);
      }  
    } 
}
void servoWrite(Servo* servo, int setState, int curState,int pos){
    if(setState == curState){
      return;
    }else{
      servo->write(pos);
    }
    Serial.print("Servo written to: ");
    Serial.println(pos);
}
void moveAnyServos(Servo* servos,int* setStates){
  for(int pos = 0; pos <= MAX_ANGLE; pos+=10){
    for(int servoNum = 0; servoNum <6;servoNum++)
      servoWrite(&servos[servoNum],setStates[servoNum],servoState[servoNum],pos); 
    //delay(5); 
  }
 
}
void interrupterA(){
  Serial.print("Moving A servo");
  sendServo(&servoA);
}
void interrupterB(){
  Serial.print("Moving B servo");
  sendServo(&servoB);
}
void interrupterC(){
  Serial.print("Moving C servo");
  sendServo(&servoC);
}
void interrupterD(){
  Serial.print("Moving D servo");
  sendServo(&servoD);
}
void interrupterE(){
  Serial.print("Moving E servo");
  sendServo(&servoE);
}
void interrupterF(){
  Serial.print("Moving F servo");
  sendServo(&servoF);
}
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
 Serial.println(sizeof(servoArray)/sizeof(servoArray[0]));
 for(int i = 1; i <= sizeof(servoArray)/sizeof(servoArray[0]);i++){
    servoArray[i].attach(i+3);
    servoArray[i].write(0);
    Serial.println(i);
  }
  /*pinMode(signalin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(signalin), interruptdetected, FALLING);*/
  /*for(int i = 0; i <= sizeof(servoArray)/sizeof(servoArray[0]);i++){
    servoArray[i].attach(i+3);
    servoArray[i].write(0);
    Serial.println(i);
  }*/ 
  //TODO initialize all of the servos for the notes.
  int arr[6] = {0,0,1,0,0,1};
  moveAnyServos(servoArray,arr);

  for(int i = 0; i < 6; i++){
       pinMode(interrupt[i],INPUT_PULLUP);
   }
  attachInterrupt(digitalPinToInterrupt(interrupt[0]),interrupterA,RISING);
  attachInterrupt(digitalPinToInterrupt(interrupt[1]),interrupterB,RISING);
  attachInterrupt(digitalPinToInterrupt(interrupt[2]),interrupterC,RISING);
  attachInterrupt(digitalPinToInterrupt(interrupt[3]),interrupterD,RISING);
  attachInterrupt(digitalPinToInterrupt(interrupt[4]),interrupterE,RISING);
  attachInterrupt(digitalPinToInterrupt(interrupt[5]),interrupterF,RISING);
}

//int buttonState = 0;
void loop() {
  // put your main code here, to run repeatedly:
   /*for(int i = 0; i > sizeof(servoArray)/sizeof(servoArray[0]);i++){
    sendServo(&(servoArray[i]));
    delay(2000);
   }*/
  /* buttonState = digitalRead(buttonPin);
   if(buttonState == HIGH){
      Serial.print("The button has turned high\n");
      digitalWrite(ledPin,HIGH);
    }else if(buttonState == LOW){
      Serial.print("The button has turned low\n"); 
      digitalWrite(ledPin,0); 
    }*/
   
  /*buttonState = digitalRead(signalin);
  if(buttonState == HIGH){
    if (millis() - buttonStartTime >= debounce) { // Debounce
      sendServo(&servoF);
    }
    buttonStartTime = millis();
  }*/
}
