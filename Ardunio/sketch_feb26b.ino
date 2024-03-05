// Pin Definitions
const int enableA = 9;
const int Pin1 = 8;
const int Pin2 = 10;
const int enableB = 11;
const int Pin3 = 12;
const int Pin4 = 13;
const int trigPin = 2;   // Ultrasonic sensor 1 trig pin
const int echoPin = 3;   // Ultrasonic sensor 1 echo pin
const int trigPin2 = 4;  // Ultrasonic sensor 2 trig pin
const int echoPin2 = 5;  // Ultrasonic sensor 2 echo pin
const int trigPin3 = 6;  // Ultrasonic sensor 3 trig pin
const int echoPin3 = 7;  // Ultrasonic sensor 3 echo pin

// Variables
long duration;
int distance;
long duration2;
int distance2;
long duration3;
int distance3;
bool obstacleAvoided = false;

void setup() {
  // Set motor pins as output
  pinMode(enableA, OUTPUT);
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(Pin3, OUTPUT);
  pinMode(Pin4, OUTPUT);
  
  // Set ultrasonic sensor 1 pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Set ultrasonic sensor 2 pins
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  // Set ultrasonic sensor 3 pins
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Move the DC motors forward
  moveForward();
  
  // Check distance from any ultrasonic sensor
  if (checkObstacle()) {
    stopCar();
    if (distance <= 15 && !obstacleAvoided) { // If obstacle detected by sensor 1 and not recently avoided
      obstacleAvoided = true;
      moveBackward();
      delay(1000); // Adjust delay for moving backward
    } else {
      obstacleAvoided = false;
      turnRight(); // If obstacle detected by other sensors or recently avoided sensor 1, turn right
      delay(1000); // Adjust delay for turning right
      moveForward();
      delay(1000);
      turnLeft();
      delay(1000);
    }
  }
}

// Function to move the car forward
void moveForward() {
  digitalWrite(Pin1, LOW);
  digitalWrite(Pin2, HIGH);
  digitalWrite(Pin3, LOW);
  digitalWrite(Pin4, HIGH);
  analogWrite(enableA, 150); // Adjust speed
  analogWrite(enableB, 150); // Adjust speed
}

// Function to move the car backward
void moveBackward() {
  digitalWrite(Pin1, HIGH);
  digitalWrite(Pin2, LOW);
  digitalWrite(Pin3, HIGH);
  digitalWrite(Pin4, LOW);
  analogWrite(enableA, 200); // Adjust speed
  analogWrite(enableB, 200); // Adjust speed
}

// Function to stop the car
void stopCar() {
  digitalWrite(Pin1, LOW);
  digitalWrite(Pin2, LOW);
  digitalWrite(Pin3, LOW);
  digitalWrite(Pin4, LOW);
}

// Function to turn the car right
void turnRight() {
  digitalWrite(Pin1, HIGH);  
  digitalWrite(Pin2, LOW); 
  
  digitalWrite(Pin3, LOW);   
  digitalWrite(Pin4, HIGH);  
}
void turnLeft() {
  digitalWrite(Pin1, LOW);  
  digitalWrite(Pin2, HIGH); 
  
  digitalWrite(Pin3, LOW);   
  digitalWrite(Pin4, HIGH);  
}
// Function to check obstacle from any ultrasonic sensor
bool checkObstacle() {
  distance = getDistance(trigPin, echoPin);
  if (distance <= 20) return true;
  
  distance2 = getDistance(trigPin2, echoPin2);
  if (distance2 <= 10) return true;
  
  distance3 = getDistance(trigPin3, echoPin3);
  if (distance3 <= 10) return true;
  
  return false;
}

// Function to measure distance using ultrasonic sensor
int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  
  // Print distance for debugging (optional)
  Serial.print("Distance: ");
  Serial.println(distance);
  
  return distance;
}
