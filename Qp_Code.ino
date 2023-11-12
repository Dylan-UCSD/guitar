#include <Servo.h>
#define MAX_ANGLE 60

Servo servoA,servoB,servoC,servoD,servoE,servoF;
Servo servoArray[6] = {servoA,servoB,servoC,servoD,servoE,servoF};
//Servo servoNotes[15] = {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o};
int servoState[6] = {0,0,0,0,0,0};
const int signalin = 12;
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
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
 Serial.println(sizeof(servoArray)/sizeof(servoArray[0]));
 for(int i = 0; i <= sizeof(servoArray)/sizeof(servoArray[0]);i++){
    servoArray[i].attach(i+3);
    servoArray[i].write(0);
    Serial.println(i);
  }
  pinMode(signalin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(signalin), interruptdetected, FALLING);
  /*for(int i = 0; i <= sizeof(servoArray)/sizeof(servoArray[0]);i++){
    servoArray[i].attach(i+3);
    servoArray[i].write(0);
    Serial.println(i);
  }*/ 
  //TODO initialize all of the servos for the notes.
  int arr[6] = {0,0,1,0,0,1};
  moveAnyServos(servoArray,arr);
}
int buttonState = 0;
void loop() {
  // put your main code here, to run repeatedly:
  //sendServo(&servoF);
  //delay(500);
  buttonState = digitalRead(signalin);
  if(buttonState == HIGH){
    if (millis() - buttonStartTime >= debounce) { // Debounce
      sendServo(&servoF);
    }
    buttonStartTime = millis();
  }
}
