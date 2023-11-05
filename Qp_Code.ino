#include <Servo.h>
#define MAX_ANGLE 60

Servo servoA,servoB,servoC,servoD,servoE,servoF;
Servo servoArray[6] = {servoA,servoB,servoC,servoD,servoE,servoF};
int servoState[6] = {0,0,0,0,0,0};


void sendServo(Servo* serv){
    Serial.println(serv->read());
    if(serv->read() == 0){
      for(int pos = 0; pos <= MAX_ANGLE; pos++){
        serv->write(pos);  
        delay(5);
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
}
void moveAnyServos(Servo* servos,int* setStates){
  for(int pos = 0; pos <= MAX_ANGLE; pos++){
    for(int servoNum = 0; servoNum <6;servoNum++)
      servoWrite(&servos[servoNum],setStates[servoNum],servoState[servoNum],pos); 
    //delay(5); 
  }
 
}
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
 Serial.println(sizeof(servoArray)/sizeof(servoArray[0]));
 for(int i = 0; i <= 
 sizeof(servoArray)/sizeof(servoArray[0]);i++){
    servoArray[i].attach(i+3);
    servoArray[i].write(0);
    Serial.println(i);
  }
  
  
}
void loop() {
  // put your main code here, to run repeatedly:
  sendServo(&servoF);
  delay(500);
}
