// for wavetable voice

const byte sine256[] PROGMEM = { // sine wavetable
  0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 4, 5, 5, 6, 7, 9, 10, 11, 12, 14, 15, 17, 18, 20, 21, 23, 25, 27, 29, 31, 33, 35, 37, 40, 42, 44, 47, 49, 52, 54, 57, 59, 62, 65, 67, 70, 73, 76, 79, 82, 85, 88, 90, 93, 97, 100, 103, 106, 109, 112, 115, 118, 121, 124, 128,
  128, 131, 134, 137, 140, 143, 146, 149, 152, 155, 158, 162, 165, 167, 170, 173, 176, 179, 182, 185, 188, 190, 193, 196, 198, 201, 203, 206, 208, 211, 213, 215, 218, 220, 222, 224, 226, 228, 230, 232, 234, 235, 237, 238, 240, 241, 243, 244, 245, 246,
  248, 249, 250, 250, 251, 252, 253, 253, 254, 254, 254, 255, 255, 255, 255, 255, 255, 255, 254, 254, 254, 253, 253, 252, 251, 250, 250, 249, 248, 246, 245, 244, 243, 241, 240, 238, 237, 235, 234, 232, 230, 228, 226, 224, 222, 220, 218, 215, 213, 211,
  208, 206, 203, 201, 198, 196, 193, 190, 188, 185, 182, 179, 176, 173, 170, 167, 165, 162, 158, 155, 152, 149, 146, 143, 140, 137, 134, 131, 128, 124, 121, 118, 115, 112, 109, 106, 103, 100, 97, 93, 90, 88, 85, 82, 79, 76, 73, 70, 67, 65,
  62, 59, 57, 54, 52, 49, 47, 44, 42, 40, 37, 35, 33, 31, 29, 27, 25, 23, 21, 20, 18, 17, 15, 14, 12, 11, 10, 9, 7, 6, 5, 5, 4, 3, 2, 2, 1, 1, 1, 0
};
//played like so

bool debug = true;

// for the sine waves
unsigned int Acc[3];
unsigned long freq[3];
unsigned int tune, pitch;
byte pot[] = {A1, A2, A3};
// from levitation osc.

const int trigIn = A2;  // Pin connected to the button and the trig in jack
const int sampleOrTrackPin = 4; //switch between 5v and GND to decide sample or track.
const int trigLed = A5;
const int intOrExtPin = 5;
const int signalInput = A7; // Input signal to sample or track.
int intOrExt = 1;

short i = 0;
int sample;

int enc_offset = 1;
// first prog, bank 2
int z = 0;
int y = 0;
int f = 0;

int prog = 1;
int bank = 1;
int banktotal = 2;
int pb1 = 1;
int pb1total = 44;
int pb2 = 1;
int pb2total = 28;

// these ranges are provisional and in schollz equations need to be reset
volatile int aMax = 99, aMin = 0, bMax = 99, bMin = 0, cMax = 256, cMin = 4;
long t = 0;
volatile int a, b, c;
volatile int offA, offB, offC;
volatile int result;
int timeToReadPots = 0;


// pot inputs
void knobs() {
  a = map(analogRead(A0), 0, 1023, aMin, aMax) + offA;
  b = map(analogRead(A3), 0, 1023, bMin, bMax) + offB;
  c = map(analogRead(A1), 0, 1023, cMin, cMax) + offC;
  //intOrExt = digitalRead(intOrExtPin); // A4
  if (debug) {
    //Serial.print("a:");
    //Serial.println(a);
    //Serial.print("b:");
    //Serial.println(b);
    //Serial.print("c:");
    //Serial.println(c);
  }
}
inline void setLimits(byte a1, byte a2, byte b1, byte b2, byte c1, byte c2) {
  aMax = a2; aMin = a1;
  bMax = b2; bMin = b1;
  cMax = c2; cMin = c1;
}
/**
    handle right button short release
*/
void onButtonReleased() {

  if (bank == 1)
  {
    if (pb1 < pb1total) {
      pb1++;
    } else if (pb1 == pb1total) {
      pb1 = 1;
    }
    prog = pb1;
  }
  else if (bank == 2) {
    if (pb2 < pb2total) {
      pb2++;
    } else if (pb2 == pb2total) {
      pb2 = 1;
    }
    prog = pb2;
  }

  if (debug) {
    Serial.println(bank);
    Serial.print("PROGRAM: ");
    Serial.println(prog);
  }
}

unsigned long getButtonPressDuration() {
  static unsigned long startTime = 0;  // Use static variable to retain state
  static bool buttonPressed = false;   // Use static variable to track button state

  if (digitalRead(trigIn) == LOW) {
    if (!buttonPressed) {  // Button press detected (LOW to HIGH transition)
      startTime = millis();
      buttonPressed = true;
    }
  } else {
    buttonPressed = false;  // Button released (HIGH to LOW transition)
  }

  if (buttonPressed) {
    return millis() - startTime;  // Return elapsed time if button is still pressed
  } else {
    return 0;  // Return 0 if button is not pressed
  }
}

// prog change button
void buttons() {
  while (digitalRead(trigIn) == LOW) {
    //change bank
    unsigned long pressDuration = getButtonPressDuration();
    if (pressDuration > 200) {
      onButtonReleased();
      digitalWrite (trigLed, HIGH);
      delay(400);
      digitalWrite (trigLed, LOW);

    }

  }
}

#include "bytebeats.h"


void setup() {
  // put your setup code here, to run once:
  //DDRD = // 0b11111111;//DDRD = DDRD | B11111100; //  // for serial we need a pin :) 0b11111111
  DDRB = 0b00011000;
  offA = 0; offB = 0; offC = 0;
  pinMode(trigLed, OUTPUT);
  pinMode(sampleOrTrackPin, INPUT_PULLUP);
  //pinMode(intOrExtPin, INPUT_PULLUP);
  pinMode(trigIn, INPUT_PULLUP);
  if (debug) {
    Serial.begin(57600);
    Serial.println(F("Started"));
  }

}

void loop() {
  // put your main code here, to run repeatedly:a
  if (timeToReadPots >= 50) {
    knobs();
    buttons();
    //adc();
    timeToReadPots = 0;
  } else {
    timeToReadPots++;
  }
  if (digitalRead(trigIn) == HIGH) {
    //We have a trig! Lets lock the sample value and send it.
    //light up the trigLed! We have a trig!
    //if(debug) Serial.println("trig");
    digitalWrite(trigLed, HIGH);
  } else {
    digitalWrite(trigLed, LOW);
  }
  
  t++; // this is our main var for generating beats

 //if (t > 65536) t = -65536;

  // the top switch is set to 'internal' source
  // we use it to change the frequency upwards

  enc_offset = analogRead(A3);

  // switch bank and choose voice
  switch (bank) {
    case 1:
      rythmical(pb1);
      break;
    case 2:
      melodious(pb2);
      break;
  }

  /*
     this plays a 3 part sine wave :)
    tune = 404 + analogRead(A6);
    tune = tune << 3;
    freq[0] = analogRead(A6) + tune;
    freq[1] = analogRead(A1)  + tune;
    freq[2] = analogRead(A2) + tune;
    for (int i = 0; i <= 3; i++) {
    Acc[i] += freq[i];
    }
    sample = ( pgm_read_byte(&sine256[Acc[0] >> 8])  + pgm_read_byte(&sine256[Acc[1] >> 8]) + pgm_read_byte(&sine256[Acc[2] >> 8]) ) / 3;
    //pgm_read_byte(&sine256[i++]);
  */


  // write the results out to dac
  PORTB = highByte(result);
  PORTB = lowByte(result);
  

  // we're using the sampleOrTrack switch for a bank switch
  if (digitalRead(sampleOrTrackPin) == LOW) {
    bank = 2;
  } else {
    bank = 1;
  }


  delayMicroseconds(enc_offset);

}
