//Master Tile
#include <Wire.h>

int address = 5;                //all tiles must have unique address


//SINUS FADE
int value, value2, value3 ;
int ledpin = 6;                           // light connected to digital pin 10
int ledpin2 = 4; 
int ledpin3 = 3;
int ledpin4 = 9;
int ledpin5 = 10;
int ledpin6 = 16;

long time=0;

int periode = 2500;
int displace = 500;
int displaceTwo = 1000;


void setup() {
  delay(150);
  Wire.begin(5);
  Wire.onReceive(receiveEvent);
  delay(1000);

}

void loop() {
 /*  time = millis();
 value = 128+127*cos(2*PI/periode*time);
 value2 = 128+127*cos(2*PI/periode*(displace-time));
 value3 = 128+127*cos(2*PI/periode*(displaceTwo-time));
 analogWrite(ledpin, value);           // sets the value (range from 0 to 255) 
 analogWrite(ledpin2, value2);           // sets the value (range from 0 to 255) 
 analogWrite(ledpin3, value3);
 analogWrite(ledpin4, value);
 analogWrite(ledpin5, value2);
 analogWrite(ledpin6, value3);
*/
}

void receiveEvent (int howMany) {
  while(Wire.available() > 0) {
    char messageType = Wire.receive();
    int n = Wire.receive();
    int vp = Wire.receive();
    int c = Wire.receive();
    
    if(messageType == 'a') {
      usbMIDI.sendControlChange(n, vp, c);
      delay(5);
    }
    if(messageType == 'n') {
      usbMIDI.sendNoteOn(n, vp, c);
      delay(5);
    }
    if(messageType == 'o') {
      usbMIDI.sendNoteOff(n, vp, c);
      delay(5);
    }
    delay(5);
  } 
  usbMIDI.send_now();
}

