#include <Servo.h>

Servo S1L, S1R, S2L, S2R, S3L, S3R, S4L, S4R;
Servo fretServos[8] = {S1L, S1R, S2L, S2R, S3L, S3R, S4L, S4R};
int fretArrLen = sizeof(fretServos) / sizeof(fretServos[0]);

Servo E, A, D, G, B, E2;
Servo stringServos[6] = {E, A, D, G, B, E2};

int fretAngle = 80;
int stringAngle = 30;

int buttonPin1 = 10;
int buttonPin2 = 11;
int buttonPin3 = 12;
int buttonPin4 = 13;

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < fretArrLen; i++){
    fretServos[i].attach(22+i);
    if(i%2 == 0){
      fretServos[i].write(180);
    }else{
      fretServos[i].write(0);
    }
  }

  pinMode(buttonPin1,INPUT);
  pinMode(buttonPin2,INPUT);
  pinMode(buttonPin3,INPUT);
  pinMode(buttonPin4,INPUT);
}

void loop() {
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  int buttonState3 = digitalRead(buttonPin3);
  int buttonState4 = digitalRead(buttonPin4);
  
  if(buttonState1 == 1){
      pressFret(&S1L, &S1R);
  }if(buttonState2 == 1){
      pressFret(&S2L, &S2R);
  }if(buttonState3 == 1){
      pressFret(&S3L, &S3R);
  }if(buttonState4 == 1){
      pressFret(&S4L, &S4R);
  }
  
  Serial.print("Buttonstate1 is ");
  Serial.println(buttonState1);
  Serial.print("Buttonstate2 is ");
  Serial.println(buttonState2);
  Serial.print("Buttonstate3 is ");
  Serial.println(buttonState3);
  Serial.print("Buttonstate4 is ");
  Serial.println(buttonState4);
  Serial.println();

  Serial.print("S1L is ");
  Serial.println(S1L.read());
  Serial.print("S1R is ");
  Serial.println(S1R.read());
  Serial.print("S2L is ");
  Serial.println(S2L.read());
  Serial.print("S2R is ");
  Serial.println(S2R.read());
  Serial.print("S3L is ");
  Serial.println(S3L.read());
  Serial.print("S3R is ");
  Serial.println(S3R.read());
  Serial.print("S4L is ");
  Serial.println(S4L.read());
  Serial.print("S4R is ");
  Serial.println(S4R.read());
  Serial.println();
  
  delay(500);
}

void playNote(int note, int duration){
  int fret = note%5 - 1;
  int string = note/5;

  if(fret > 0) pressFret(&fretServos[fret*2], &fretServos[fret*2+1]);
  playString(&stringServos[string]);
  delay(duration);
  if(fret > 0) pressFret(&fretServos[fret*2], &fretServos[fret*2+1]);
}

void pressFret(Servo *SL, Servo* SR){
  if(SL->read() == 180){
    SL->write(180-fretAngle);
    SR->write(fretAngle);
  }else{
    SL->write(180);
    SR->write(0);
  }
}

void playString(Servo *string){
  if (string->read() == 0){
    string->write(stringAngle);
  }else{
    string->write(0);
  }
}

// note must be of the form (Letter, Number) or (Letter, #, Number) ex. E1, G#2 are valid; C2#, A# is not
// only E1 to G#3 is valid
int noteToNum(String note){
  int num = 0;
  
  if(note.charAt(0) == 'C'){
    num = -4;
  }else if(note.charAt(0) == 'D'){
    num = -2;
  }else if(note.charAt(0) == 'E'){
    num = 0;
  }else if(note.charAt(0) == 'F'){
    num = 1;
  }else if(note.charAt(0) == 'G'){
    num = 3;
  }else if(note.charAt(0) == 'A'){
    num = 5;
  }else if(note.charAt(0) == 'B'){
    num = 7;
  }

  if(note.charAt(1) == '#'){
    num++;
    if(note.charAt(2) == '2'){
      num += 12;
    }else if(note.charAt(2) == '3'){
      num += 24;
    }
  }else if(note.charAt(1) == '2'){
    num += 12;
  }else if(note.charAt(1) == '3'){
    num += 24;
  }

  return num < 19 ? num : num+1;
}
