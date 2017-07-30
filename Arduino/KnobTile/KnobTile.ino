
//Button Tile
#include <Wire.h>

int address = 39;  // must have unique address
int channel = 1;

//SINUS FADE
int value, value2, value3 ;
int ledpin = 22;                           
int ledpin2 = 4; 
int ledpin3 = 3;
long time=0;

int periode = 2500;
int displace = 500;
int displaceTwo = 1000;


//PotVariables

int midiSend;
int analogPrev = 0;
int potPin = 23;
int analogReader = 0;

/*int buttonPin = 23;            // pin that switch is connected to

boolean buttonState = false;
boolean noteState = false;

*/

void setup() {
  pinMode(13, OUTPUT);
  //pinMode(buttonPin, INPUT_PULLUP);
  delay(500+address);
  digitalWrite(13, HIGH);
  delay(500);
  Wire.begin(address);
}

void loop() {
 /* time = millis();
 value = 128+127*cos(2*PI/periode*time);
 value2 = 128+127*cos(2*PI/periode*(displace-time));
 value3 = 128+127*cos(2*PI/periode*(displaceTwo-time));
 analogWrite(ledpin, value);           // sets the value (range from 0 to 255) 
 analogWrite(ledpin2, value2);           // sets the value (range from 0 to 255) 
 analogWrite(ledpin3, value3);
  
  if(digitalRead(buttonPin) == LOW) {
    buttonState = true;
  } else {
    buttonState = false;
  }
  if(noteState == false) {
    if(buttonState == true) {
      serialI2COut ('n', address, 100, 1);
      noteState = true;
    }
  } else {
    if(buttonState == false) {
      serialI2COut ('o', address, 100, 1);
      noteState = false;
    }
  }*/
  analogReader = analogRead(potPin);
  if(abs(analogReader - analogPrev) > 20) {
    midiSend = map(analogReader, 0, 1023, 0, 127);
    serialI2COut('a', address, midiSend, channel);
    analogPrev = analogReader;
  }
  delay(5); 
}

void serialI2COut (char type, int n, int vp, int c) {
  Wire.beginTransmission(5);
  Wire.send(type);
  Wire.send(n);
  Wire.send(vp);
  Wire.send(c);
  Wire.endTransmission();
}

  

