
#include "globals.h"
#include "debug.h"
#include "LowPower.h"   //https://github.com/rocketscream/Low-Power/archive/master.zip




void setup() {
  // turn on LED to signal the start of the calibration period:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  // initialize the LED and mosfet pins as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPinTop, OUTPUT);
  pinMode(ledPinIr, OUTPUT);
  pinMode(fet1, OUTPUT);
  pinMode(fet2, OUTPUT);

  // Turn on all of the LED and IR pins :

  digitalWrite(ledPinTop, HIGH);
  digitalWrite(ledPinIr, HIGH);

  Serial.begin(9600);
}

void loop()
{
  // read the state of the pushbutton value:
  int reading = digitalRead(buttonPin);

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState)
    {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH)
      {
        digitalWrite(ledPinIr, HIGH);
        digitalWrite(ledPin, HIGH);
        sensorValue = analogRead(sensorPin);

        Serial.println(sensorValue);
        digitalWrite(fet1, HIGH);   //  FIRE!!!

        digitalWrite(ledPinTop, HIGH);  // prep for eye indicate
        delay(50);   // wait for sear to fire
        digitalWrite(fet2, HIGH);  //  open ram
        delay(20);  // wait for bolt to open
        digitalWrite(ledPin, LOW);
        // Check eye/limit reading
        if (sensorValue <= sensorSensitivity  )
        {

          digitalWrite(ledPinIr, LOW);
          digitalWrite(ledPinTop, LOW);  // indicate eye is blocked
          delay(20);          // ball drop delay
          digitalWrite(fet2, LOW);    // close ram

        }
        else
        {
          digitalWrite(ledPinTop, HIGH);  // indicate eye is open
          count = 0;
          while (analogRead(sensorPin) >= sensorSensitivity  )
          {
            // do nothing
            count++;
            Serial.println(count);

            if ( count > eyeDelay )
            {
              goto bailout;
            }
          }
bailout:
          delay(10);          // ball drop delay
          digitalWrite(fet2, LOW);    // close ram
          digitalWrite(ledPinTop, LOW);
          digitalWrite(ledPinIr, LOW);

        }
      }
    }
  }
  // set the LED:


  lastButtonState = reading;

  // delay in between reads for stability



}

