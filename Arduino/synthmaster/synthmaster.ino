#include <Wire.h>

boolean midiStatus = false;
int counter = 1;
int previousCounter = 1;
long previousMillis = 0;
boolean samplePlayed = false;

int switchStatus[] =  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0};
int switchChannel[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
int switchTiming[] =  {1,  1,  1,  1,  2,  2,  2,  2,  3,  3,  3,  3,  4,  4,  4,  4};

long interval = 1000;

void setup() {
  pinMode(13, OUTPUT);
  delay(150);
  Wire.begin(5);
  Wire.onReceive(receiveEvent);
  delay(1000);
}

void loop() {
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
    previousCounter = counter;
    if(previousCounter == 4) {
      counter = 1;
    } else {
      counter = previousCounter + 1;
    }
  }

  
  //PLAY SAMPLES
  for(int i=0; i<17; i++){
    if(counter == switchTiming[i] && samplePlayed == false) {
      if(switchStatus[i] > 0) {
        //play audio sample
        digitalWrite(13, HIGH);
        samplePlayed = true;
      } else {
        digitalWrite(13, LOW);
        samplePlayed = false;
      }
    }
  }
}
void receiveEvent (int howMany) {
  while(Wire.available() > 0) {
    char messageType = Wire.receive();
    int n = Wire.receive();
    int vp = Wire.receive();
    int c = Wire.receive();
    
    if(messageType == 'a' && midiStatus == true) {
      usbMIDI.sendControlChange(n, vp, c);
      delay(5);
    }
    if(messageType == 'n' && midiStatus == false) {
      for(int i=0; i<17; i++){
        if(switchChannel[i] = n){
          switchStatus[i] = 1;
        }
      }
      delay(5);
    }
    if(messageType == 'o' && midiStatus == false) {
      for(int i=0; i<17; i++){
        if(switchChannel[i] = n){
          switchStatus[i] = 0;
        }
      }
    delay(5);
  }
  } 
  usbMIDI.send_now();
}

