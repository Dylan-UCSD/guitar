#include <Servo.h>
#define MAX_ANGLE 60
#define FRET_ANGLE 100

int interrupt[6] = {2,3,18,19,20,21};
int buttons[4] = {22,24,26,28};
int buttonsState[4] = {0,0,0,0};
Servo servoA,servoB,servoC,servoD,servoE,servoF;
Servo fret1,fret2,fret3,fret4,fret5,fret6,fret7,fret8;
Servo servoArray[6] = {servoA,servoB,servoC,servoD,servoE,servoF};
Servo servoNotes[8] = {fret1,fret2,fret3,fret4,fret5,fret6,fret7,fret8};
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
   if (millis() - buttonStartTime < debounce) { // Debounce
    return;
  }
  buttonStartTime = millis();
  Serial.print("Moving A servo");
  sendServo(&servoA);
}
void interrupterB(){
  if (millis() - buttonStartTime < debounce) { // Debounce
    return;
  }
  buttonStartTime = millis();
  Serial.print("Moving B servo");
  sendServo(&servoB);
}
void interrupterC(){
   if (millis() - buttonStartTime < debounce) { // Debounce
    return;
  }
  buttonStartTime = millis();
  Serial.print("Moving C servo");
  sendServo(&servoC);
}
void interrupterD(){
   if (millis() - buttonStartTime < debounce) { // Debounce
    return;
  }
  buttonStartTime = millis();
  Serial.print("Moving D servo");
  sendServo(&servoD);
}
void interrupterE(){
  if (millis() - buttonStartTime < debounce) { // Debounce
    return;
  }
  buttonStartTime = millis();
  Serial.print("Moving E servo");
  sendServo(&servoE);
}
void interrupterF(){
  if (millis() - buttonStartTime < debounce) { // Debounce
    return;
  }
  buttonStartTime = millis();
  Serial.print("Moving F servo");
  sendServo(&servoF);
}
void sendFret(Servo *serv){
  if(serv->read() == 0){
      serv->write(FRET_ANGLE);
   }else{
      serv->write(0);
   }
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
  for(int i = 0; i < (sizeof(servoNotes)/sizeof(servoNotes[0]));i+=2){
    servoArray[i].attach(i+10);
    servoArray[i+1].attach(i+10);
    servoArray[i].write(0);
    Serial.println(i);
  } 
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
  for(int i = 0; i < 4;i++){
    pinMode(buttons[i],INPUT);
   }
}

//int buttonState = 0;
void loop() {
  for(int i = 0; i < 4;i++){
    buttonsState[i] = digitalRead(buttons[i]);
    if(buttonsState[i] == 1){
      sendFret(servoNotes[i*2]);
    }
  }
   
}
