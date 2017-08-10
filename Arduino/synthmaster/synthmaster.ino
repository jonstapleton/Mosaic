#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioPlayMemory          playMem3;       //xy=144.00000762939453,232.00000762939453
AudioPlayMemory          playMem4;       //xy=164.00000762939453,302.00000953674316
AudioPlayMemory          playMem1;       //xy=167,70
AudioPlayMemory          playMem2;       //xy=169.00000381469727,144.00000476837158
AudioMixer4              mixer1;         //xy=415,124
AudioOutputAnalog        dac1;           //xy=719,139
AudioConnection          patchCord1(playMem3, 0, mixer1, 2);
AudioConnection          patchCord2(playMem4, 0, mixer1, 3);
AudioConnection          patchCord3(playMem1, 0, mixer1, 0);
AudioConnection          patchCord4(playMem2, 0, mixer1, 1);
AudioConnection          patchCord5(mixer1, dac1);
// GUItool: end automatically generated code


boolean midiStatus = false;
int counter = 1;
int previousCounter = 1;
long previousMillis = 0;

int switchStatus[] =  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0};
int samplePlaying[] = {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0};
int switchChannel[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
int switchTiming[] =  {1,  1,  1,  1,  2,  2,  2,  2,  3,  3,  3,  3,  4,  4,  4,  4};

long intervalX = 1000;

void setup() {
  pinMode(13, OUTPUT);
  //digitalWrite(13, HIGH);
  delay(150);
  Wire.begin(5);
  Wire.onReceive(receiveEvent);
  delay(1000);
  Serial.print(counter);
  delay(1000);
  Serial.print(previousCounter);
}

void loop() {
  Serial.print(counter);

  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > intervalX) {
    previousMillis = currentMillis;
    previousCounter = counter;
    if(previousCounter > 3) {
      counter = 1;
    } else {
      counter = counter + 1;
      digitalWrite(13, LOW);
    }
  }
  for(int i=0; i<17; i++) {
    if(switchTiming[i] == counter && switchStatus[i] > 0) {
      //play(//data);
      Serial.print("playing");
      switchStatus[i] = 0;
    }
  }
}


  
void receiveEvent (int howMany) {
  if(Wire.available() > 0) {
    char messageType = Wire.receive();
    int n = Wire.receive();
    int vp = Wire.receive();
    int c = Wire.receive();
    
    if(messageType == 'a' && midiStatus == true) {
      usbMIDI.sendControlChange(n, vp, c);
      delay(5);
    }
    if(messageType == 'n' && midiStatus == false) {
      for(int s=0; s<17; s++){
        if(switchChannel[s] = n){
          switchStatus[s] = 1;
        }
      }
      delay(5);
    }
    if(messageType == 'o' && midiStatus == true) {
      for(int p=0; p<17; p++){
        if(switchChannel[p] = n){
          switchStatus[p] = 0;
        }
      }
      delay(5);
    }
    delay(5);
  } 
  usbMIDI.send_now();

}
