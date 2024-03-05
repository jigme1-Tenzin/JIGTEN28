#include <Stepper.h>

// Define the number of steps per revolution
const int stepsPerRevolution = 200;

// Initialize the stepper motor on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // Set the speed of the motor in RPM (adjust as needed)
  myStepper.setSpeed(60);
}

void loop() {
  // Step one revolution in one direction:
  myStepper.step(stepsPerRevolution);
  delay(500);  // Delay for visibility (adjust as needed)

  // Step one revolution in the other direction:
  myStepper.step(-stepsPerRevolution);
  delay(500);  // Delay for visibility (adjust as needed)
}
