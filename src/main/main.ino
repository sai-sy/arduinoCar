#include "Motor.h"
#include "IRSensor.h"
#include "Algorithms.h"

const int buttonPin = 22;
int buttonState = 0;
bool isOn = false; 

void startControl() {
    buttonState = digitalRead(buttonPin);
    if (buttonState == 1 && isOn == false) {
      Serial.println("turning on");
      isOn = true;
      delay(500);
    }
    else if (buttonState == 1 && isOn == true) 
    {
      Serial.println("turning off");
      isOn = false;
      delay(500);
    }
}

void setup(){
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  setSpeed();
  setupIR();
}


void loop(){
  startControl();

  if (isOn) {
    checkIR();
    move();
  }
  else {
    brake();
  }
}

