#include <Servo.h>

Servo S1L, S1R, S2L, S2R, S3L, S3R, S4L, S4R;
Servo fretServos[8] = {S1L, S1R, S2L, S2R, S3L, S3R, S4L, S4R};
int fretArrLen = sizeof(fretServos) / sizeof(fretServos[0]);

Servo E, A, D, G, B, E2;
Servo stringServos[6] = {E, A, D, G, B, E2};
int stringArrLen = sizeof(stringServos) / sizeof(stringServos[0]);

//Pirates of the Caribbean
/*String notes[][5] = {{"D2", "D2", "D2", "D2", ""}, {"D2", "D2", "D2", "D2", "D2"},
                           {"D2", "D2", "D2", "D2", ""}, {"D2", "D2", "D2", "D2", "D2"},
                           {"D2", "D2", "D2", "D2", ""}, {"D2", "D2", "D2", "A1", "C2"}, // end intro
                         
                           {"D2", "D2", "D2", "E2", ""}, {"F2", "F2", "F2", "G2", ""},
                           {"E2", "E2", "D2", "C2", ""}, {"C2", "D2", "A1", "C2", ""}, // end part 1
                           {"D2", "D2", "D2", "E2", ""}, {"F2", "F2", "F2", "G2", ""},
                           {"E2", "E2", "D2", "C2", ""}, {"D2", "A1", "C2", "", ""}, // end part 2
                           {"D2", "D2", "D2", "F2", ""}, {"G2", "G2", "G2", "A2", ""},
                           {"A#2", "A#2", "A2", "G2", ""}, {"A2", "D2", "D2", "E2", ""},
                           {"F2", "F2", "G2", "", ""}, {"A2", "D2", "D2", "F2", ""},
                           {"E2", "E2", "F2", "D2", ""}, {"E2", "A1", "C2", "", ""}, // end part 3
                         
                           {"D2", "D2", "D2", "E2", ""}, {"F2", "F2", "F2", "G2", ""},
                           {"E2", "E2", "D2", "C2", ""}, {"C2", "D2", "A1", "C2", ""}, // end part 1
                           {"D2", "D2", "D2", "E2", ""}, {"F2", "F2", "F2", "G2", ""},
                           {"E2", "E2", "D2", "C2", ""}, {"D2", "A1", "C2", "", ""}, // end part 2
                           {"D2", "D2", "D2", "F2", ""}, {"G2", "G2", "G2", "A2", ""},
                           {"A#2", "A#2", "A2", "G2", ""}, {"A2", "D2", "D2", "E2", ""},
                           {"F2", "F2", "G2", "", ""}, {"A2", "D2", "D2", "F2", ""},
                           {"E2", "E2", "F2", "D2", ""}, {"E2", "A1", "C2", "", ""}}; // end part 3

int durations[][5] = {{4, 8, 4, 8, 0}, {4, 8, 8, 8, 8},
                            {4, 8, 4, 8, 0}, {4, 8, 8, 8, 8},
                            {4, 8, 4, 8, 0}, {4, 8, 8, 8, 8}, // end intro
                          
                            {4, 4, 8, 8, 0}, {4, 4, 8, 8, 0},
                            {4, 4, 8, 8, 0}, {8, 3, 8, 8, 0}, // end part 1
                            {4, 4, 8, 8, 0}, {4, 4, 8, 8, 0},
                            {4, 4, 8, 8, 0}, {2, 8, 8, 0, 0}, // end part 2
                            {4, 4, 8, 8, 0}, {4, 4, 8, 8, 0},
                            {4, 4, 8, 8, 0}, {8, 3, 8, 8, 0},
                            {4, 4, 4, 0, 0}, {8, 3, 8, 8, 0},
                            {4, 4, 8, 8, 0}, {2, 8, 8, 0, 0}, // end part 3
                          
                            {4, 4, 8, 8, 0}, {4, 4, 8, 8, 0},
                            {4, 4, 8, 8, 0}, {8, 3, 8, 8, 0}, // end part 1
                            {4, 4, 8, 8, 0}, {4, 4, 8, 8, 0},
                            {4, 4, 8, 8, 0}, {2, 8, 8, 0, 0}, // end part 2
                            {4, 4, 8, 8, 0}, {4, 4, 8, 8, 0},
                            {4, 4, 8, 8, 0}, {8, 3, 8, 8, 0},
                            {4, 4, 4, 0, 0}, {8, 3, 8, 8, 0},
                            {4, 4, 8, 8, 0}, {2, 8, 8, 0, 0}}; // end part 3*/

// All notes test
/*String notes[][4] = {{"E1", "F1", "F#1", "G1"}, {"G#1", "A1", "A#1", "B1"},
                        {"C2", "C#2", "D2", "D#2"}, {"E2", "F2", "F#2", "G2"},
                        {"G#2", "A2", "A#2", "B2"}, {"C3", "C#3", "D3", "D#3"},
                        {"E3", "F3", "F#3", "G3"}};

int durations[][4] = {{4, 4, 4, 4}, {4, 4, 4, 4},
                         {4, 4, 4, 4}, {4, 4, 4, 4},
                         {4, 4, 4, 4}, {4, 4, 4, 4},
                         {4, 4, 4, 4}};*/

// Twinkle Twinkle
/*String notes[][4] = {{"A2", "A2", "E3", "E3"}, {"F#3", "F#3", "E3", ""},
                            {"D3", "D3", "C#3", "C#3"}, {"B2", "B2", "A2", ""},
                            {"E3", "E3", "D3", "D3"}, {"C#3", "C#3", "B2", ""},
                            {"E3", "E3", "D3", "D3"}, {"C#3", "C#3", "B2", ""}};

int durations[][4] = {{4, 4, 4, 4}, {4, 4, 2, 0},
                            {4, 4, 4, 4}, {4, 4, 2, 0},
                            {4, 4, 4, 4}, {4, 4, 2, 0},
                            {4, 4, 4, 4}, {4, 4, 2, 0}};*/

// Custom Song
String notes[][3] = {{"E1", "B2", "E3"}, {"E1", "B2", "E3"}, {"E1", "B2", "E3"}, {"E1", "B2", "E3"},
                           {"A1", "B2", "E3"}, {"A1", "B2", "E3"}, {"A1", "B2", "E3"}, {"A1", "B2", "E3"},
                           {"G2", "B2", "E3"}, {"G2", "B2", "E3"}, {"D2", "B2", "E3"}, {"D2", "B2", "E3"}};

int durations[][3] = {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}, {4, 4, 4},
                            {4, 4, 4}, {4, 4, 4}, {4, 4, 4}, {4, 4, 4},
                            {4, 4, 4}, {4, 4, 4}, {4, 4, 4}, {4, 4, 4}};

// Uncomment the notes and durations for the song you want played

const int BPM = 130;
const int numMeasures = sizeof(notes) / sizeof(notes[0]);
const int measureLen = sizeof(notes[0]) / sizeof(notes[0][0]);
int measureCount = 0;
int noteCount = 0;

int fretAngle = 40;
int fretStartAngle = 15;
int stringAngle = 40;

int buttonPin1 = 34;
int buttonPin2 = 35;
int buttonPin3 = 36;
int buttonPin4 = 37;

bool testing = false;

// Initialize all the servos and buttons
void setup() { 
  Serial.begin(9600);
  for (int i = 0; i < fretArrLen; i++) {
    fretServos[i].attach(22 + i);
    if (i % 2 == 0) {
      fretServos[i].write(180 - fretStartAngle);
    } else {
      fretServos[i].write(fretStartAngle);
    }
  }

  for (int i = 0; i < stringArrLen; i++) {
    stringServos[i].attach(53 - i);
    stringServos[i].write(5);
  }

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
}

void loop() {
  // Read button values
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  int buttonState3 = digitalRead(buttonPin3);
  int buttonState4 = digitalRead(buttonPin4);

  // Testing code
  if (buttonState1 == 1) {
    //pressFret(&S1L, &S1R);
    //playString(3);
  } if (buttonState2 == 1) {
    //pressFret(&S2L, &S2R);
    playString(3);
    //playNote(noteToNum("A1"), noteToNum("A1"), 500);
  } if (buttonState3 == 1) {
    //pressFret(&S3L, &S3R);
    playString(4);
    //playNote(noteToNum("C2"), 0, 500);
  } if (buttonState4 == 1) {
    //pressFret(&S4L, &S4R);
    playString(5);
  }

  int noteNum = noteToNum(notes[measureCount][noteCount]);
  int noteDuration = durationToTime(durations[measureCount][noteCount]);

  int nextNoteCount = noteCount;
  int nextMeasureCount = measureCount;
  nextNoteCount++;
  if (nextNoteCount >= measureLen || durations[nextMeasureCount][nextNoteCount] == 0) {
    nextMeasureCount++;
    if (nextMeasureCount >= numMeasures) nextMeasureCount = 0;
    nextNoteCount = 0;
  }
  int nextNoteNum = noteToNum(notes[nextMeasureCount][nextNoteCount]);

  if (testing) delay(200);
  else playNote(noteNum, nextNoteNum, noteDuration); // Where the magic happens

  noteCount++;
  if (noteCount >= measureLen || durations[measureCount][noteCount] == 0) {
    measureCount++;
    if (measureCount >= numMeasures) measureCount = 0;
    noteCount = 0;
  }

  /*Serial.print("Buttonstate1 is ");
  Serial.println(buttonState1);
  Serial.print("Buttonstate2 is ");
  Serial.println(buttonState2);
  Serial.print("Buttonstate3 is ");
  Serial.println(buttonState3);
  Serial.print("Buttonstate4 is ");
  Serial.println(buttonState4);
  Serial.println();*/

  /*Serial.print("S1L is ");
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
  Serial.println();*/

  /*Serial.print("E is ");
  Serial.println(E.read());
  Serial.print("A is ");
  Serial.println(A.read());
  Serial.print("D is ");
  Serial.println(D.read());
  Serial.print("G is ");
  Serial.println(G.read());
  Serial.print("B is ");
  Serial.println(B.read());
  Serial.print("E2 is ");
  Serial.println(E2.read());
  Serial.println();*/
}

// Plays a specified note for duration in milliseconds
void playNote(int note, int nextNote, int duration) {
  int fret = note % 5;
  int string = note / 5;
  int nextFret = nextNote % 5;

  Serial.println(fret);
  Serial.println(string);
  Serial.println();

  if (fret > 0) pushFret(&fretServos[fret * 2 - 2], &fretServos[fret * 2 - 1]);
  delay(duration / 2);
  playString(string);
  delay(duration / 2);
  if (fret > 0 && nextFret != fret) releaseFret(&fretServos[fret * 2 - 2], &fretServos[fret * 2 - 1]);
  else if (nextFret > 0) pushFret(&fretServos[nextFret * 2 - 2], &fretServos[nextFret * 2 - 1]);
}

// Pushes a single fret
void pushFret(Servo *SL, Servo *SR) {
  SL->write(180 - fretAngle);
  SR->write(fretAngle);
}

// Releases a single fret
void releaseFret(Servo *SL, Servo *SR) {
  SL->write(180 - fretStartAngle);
  SR->write(fretStartAngle);
}

// Plays a specified string, given its index
void playString(int stringIndex) {
  int startAngle = 0;
  Servo string = stringServos[stringIndex];
  if (stringIndex == 1) startAngle = 5;
  if (string.read() < (startAngle + stringAngle) / 2) {
    string.write(stringAngle);
  } else {
    string.write(startAngle);
  }
}

// Converts a note from letter form to number form
// note must be of the form (Letter, Number) or (Letter, #, Number) 
// ex. A1, G#2 are valid; C2#, A# is not
// only E1 through G#3 is valid
int noteToNum(String note) {
  int num = 0;

  if (note.charAt(0) == 'C') {
    num = -4;
  } else if (note.charAt(0) == 'D') {
    num = -2;
  } else if (note.charAt(0) == 'E') {
    num = 0;
  } else if (note.charAt(0) == 'F') {
    num = 1;
  } else if (note.charAt(0) == 'G') {
    num = 3;
  } else if (note.charAt(0) == 'A') {
    num = 5;
  } else if (note.charAt(0) == 'B') {
    num = 7;
  }

  if (note.charAt(1) == '#') {
    num++;
    if (note.charAt(2) == '2') {
      num += 12;
    } else if (note.charAt(2) == '3') {
      num += 24;
    }
  } else if (note.charAt(1) == '2') {
    num += 12;
  } else if (note.charAt(1) == '3') {
    num += 24;
  }

  return num < 19 ? num : num + 1;
}

// Converts from a beat time to time in milliseconds
int durationToTime(int duration) {
  float BPS = BPM / 60.0;
  int fullDuration = 4000 / BPS;
  float actualDuration = 1 / (float) duration;
  return duration == 3 ? fullDuration * 3 / 8 : fullDuration * actualDuration;
}
