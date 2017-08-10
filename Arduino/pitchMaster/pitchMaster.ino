#include <Audio.h>
#include <Wire.h>


// GUItool: begin automatically generated code
AudioSynthWaveform       waveform2;      //xy=162.00000762939453,186.00000524520874
AudioSynthWaveform       waveform1;      //xy=163,114
AudioSynthWaveform       waveform3;      //xy=167,254
AudioSynthWaveform       waveform4;      //xy=171,323
AudioSynthWaveform       waveform6;      //xy=174.00000381469727,444.00001335144043
AudioSynthWaveform       waveform5;      //xy=175.00000381469727,389.0000114440918
AudioSynthWaveform       waveform8;      //xy=178.00000762939453,562.0000171661377
AudioSynthWaveform       waveform7;      //xy=181.00000762939453,499.0000147819519
AudioMixer4              mixer1;         //xy=504.0000648498535,166.00001907348633
AudioMixer4              mixer2;         //xy=535,416
AudioMixer4              mixer3;         //xy=737,278
AudioOutputAnalog        dac1;           //xy=917.0000267028809,277.00000858306885
AudioConnection          patchCord1(waveform2, 0, mixer1, 1);
AudioConnection          patchCord2(waveform1, 0, mixer1, 0);
AudioConnection          patchCord3(waveform3, 0, mixer1, 2);
AudioConnection          patchCord4(waveform4, 0, mixer1, 3);
AudioConnection          patchCord5(waveform6, 0, mixer2, 1);
AudioConnection          patchCord6(waveform5, 0, mixer2, 0);
AudioConnection          patchCord7(waveform8, 0, mixer2, 3);
AudioConnection          patchCord8(waveform7, 0, mixer2, 2);
AudioConnection          patchCord9(mixer1, 0, mixer3, 0);
AudioConnection          patchCord10(mixer2, 0, mixer3, 1);
AudioConnection          patchCord11(mixer3, dac1);
// GUItool: end automatically generated code


int address = 5;                //all tiles must have unique address
boolean midiStatus = true;

void setup() {
  pinMode(13, OUTPUT);
  dac1.analogReference(EXTERNAL);
  waveform1.begin(0.4, 200, WAVEFORM_SAWTOOTH);
  waveform2.begin(0.4, 200, WAVEFORM_SAWTOOTH);
  waveform3.begin(0.4, 200, WAVEFORM_SAWTOOTH);
  waveform4.begin(0.4, 200, WAVEFORM_SAWTOOTH);
  waveform5.begin(0.4, 200, WAVEFORM_SAWTOOTH);
  waveform6.begin(0.4, 200, WAVEFORM_SAWTOOTH);
  waveform7.begin(0.4, 200, WAVEFORM_SAWTOOTH);
  waveform8.begin(0.4, 200, WAVEFORM_SAWTOOTH);
  mixer1.gain(0, 0.75);
  mixer1.gain(1, 0.75);
  mixer1.gain(2, 0.75);
  mixer1.gain(3, 0.75);
  mixer2.gain(0, 0.75);
  mixer2.gain(1, 0.75);
  mixer2.gain(2, 0.75);
  mixer2.gain(3, 0.75);
  mixer3.gain(0, 0.75);
  mixer3.gain(1, 0.75);
  digitalWrite(13, HIGH);
  delay(150);
  //Wire.begin(5);
  //Wire.onReceive(receiveEvent);
  delay(1000);
  

}

void loop() {

}

/*void receiveEvent (int howMany) {
  while(Wire.available() > 0) {
    char messageType = Wire.receive();
    int n = Wire.receive();
    int vp = Wire.receive();
    int c = Wire.receive();
    
    if(messageType == 'a' && midiStatus == true) {
      if(n == 30) {
        waveform7.frequency(360 * vp + 0.25);
      }
      if(n == 31){
        waveform1.frequency(360 * vp + 0.25);
      }
      if(n == 32) {
        waveform2.frequency(360 * vp + 0.25);
      }
      if(n == 33) {
        waveform3.frequency(360 * vp + 0.25);
      }
      if(n == 34) {
        waveform4.frequency(360 * vp + 0.25);
      }
      if(n == 35) {
        waveform5.frequency(360 * vp + 0.25);
      }
      if(n == 36) {
        waveform6.frequency(360 * vp + 0.25);
      }
      if(n == 37) {
        waveform8.frequency(360 * vp + 0.25);
      }
      if(n == 38) {
        waveform1.amplitude(360 * vp + 0.25);
      }
      if(n == 39) {
        waveform2.amplitude(360 * vp + 0.25);
      }
      if(n == 40) {
        waveform3.amplitude(360 * vp + 0.25);
      }
      if(n == 41) {
        waveform4.amplitude(360 * vp + 0.25);
      }
      if(n == 42) {
        waveform5.amplitude(360 * vp + 0.25);
      }
      if(n == 43) {
        waveform6.amplitude(360 * vp + 0.25);
      }
      if(n == 44) {
        waveform8.amplitude(360 * vp + 0.25);
      }
      if(n == 45) {
        waveform7.amplitude(360 * vp + 0.25);
      }
      delay(5);
    }
    if(messageType == 'n' && midiStatus == true) {
      usbMIDI.sendNoteOn(n, vp, c);
      delay(5);
    }
    if(messageType == 'o' && midiStatus == true) {
      usbMIDI.sendNoteOff(n, vp, c);
      delay(5);
    }
    delay(5);
  }
  usbMIDI.send_now();
}*/

