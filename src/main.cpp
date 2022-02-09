#include <Arduino.h>
#include <Stepper.h>

const uint8_t STEPPER_PIN_1 = 22;
const uint8_t STEPPER_PIN_2 = 23;
const uint8_t STEPPER_PIN_3 = 9;
const uint8_t STEPPER_PIN_4 = 10;


const int stepsPerRevolution = 3300;  // change this to fit the number of steps per revolution
// for your motor


// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);

int stepCount = 0;  // number of steps the motor has taken

void setup() {
  // nothing to do inside the setup
}

void loop() {
  int motorSpeed = 1023;
  // set the motor speed:
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution);
    delay(500);
    myStepper.step(-stepsPerRevolution);
  }
}