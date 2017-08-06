
#ifndef GLOBALS_H
#define GLOBALS_H


// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 4;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int ledPinTop =  2;      // the number of the LED pin
const int ledPinIr =  3;      // the number of the LED pin
const int fet1 =  10;      // the number of the LED pin
const int fet2 =  11;      // the number of the LED pin
const int sensorPin = A3;    // pin that the sensor is attached to
const int sensorSensitivity = 800;    // 0-1000   variable for reading the IR status

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int sensorValue = 0;         // the sensor value
int sensorValue2 = 0;         // the sensor value
int ledState = HIGH;         // the current state of the output pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are unsigned long's because the time, measured in miliseconds,
// will quickly become a bigger number than can't be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 20;    // the debounce time; increase if the output flickers
unsigned long eyeDelay = 500;    // cycles before we close the bolt on no ball detection

int count = 0;   // the previous reading from the input pin
#endif



/*
 * NOTES
 * 
 * LOWER POWER VARIBLES
  SLEEP_15MS
  SLEEP_30MS
  SLEEP_60MS
  SLEEP_120MS
  SLEEP_250MS
  SLEEP_500MS
  SLEEP_1S
  SLEEP_2S
  SLEEP_4S
  SLEEP_8S
*/
