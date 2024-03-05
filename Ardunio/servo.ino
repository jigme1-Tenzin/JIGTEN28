#include <Servo.h>

Servo myServo;  // Create a servo object

int pos = 0;    // Variable to store the servo position

void setup() {
  myServo.attach(12);  // Attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // Sweep from 0 to 180 degrees
    myServo.write(pos);                  // Tell servo to go to position in variable 'pos'
    delay(1);                           // Wait for 15ms for the servo to reach the position
  }
  
  for (pos = 180; pos >= 0; pos -= 1) { // Sweep from 180 to 0 degrees
    myServo.write(pos);                  // Tell servo to go to position in variable 'pos'
    delay(1);                           // Wait for 15ms for the servo to reach the position
  }
}
