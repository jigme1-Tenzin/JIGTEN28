#include <Servo.h>

// Define the pin to which the servo is connected
const int servoPin = 9;

// Create a servo object
Servo myServo;

void setup() {
  // Attach the servo to the pin
  myServo.attach(servoPin);
}

void loop() {
  // Move the servo to position 0 degrees
  myServo.write(0);
  delay(1000); // Wait for 1 second

  // Move the servo to position 90 degrees
  myServo.write(180);
  delay(1000); // Wait for 1 second

  // Move the servo to position 180 degrees
  myServo.write(180);
  delay(1000); // Wait for 1 second
}
