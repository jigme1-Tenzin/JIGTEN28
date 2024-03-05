// Pin Definitions
const int enableA = 9;
const int Pin1 = 8;
const int Pin2 = 10;
const int enableB = 11;
const int Pin3 = 12;
const int Pin4 = 13;
const int trigPin = 2; // Ultrasonic sensor trig pin
const int echoPin = 3; // Ultrasonic sensor echo pin

// Variables
long duration;
int distance;

void setup() {
  // Set motor pins as output
  pinMode(enableA, OUTPUT);
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(Pin3, OUTPUT);
  pinMode(Pin4, OUTPUT);
  
  // Set ultrasonic sensor pins
  pinMode(trigPin, OUTPUT); // Set trig pin as output
  pinMode(echoPin, INPUT);   // Set echo pin as input
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Move the DC motors forward
  moveForward();
  
  // Check distance
  int dist = getDistance();
  
  // If obstacle detected within 20cm, stop the car
  if (dist <= 20) {
    stopCar();
    delay(1000); // Brief delay to stop the car completely
  }
}

// Function to move the car forward
void moveForward() {
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

// Function to measure distance using ultrasonic sensor
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Speed of sound in air is approximately 0.034 cm per microsecond

  // Print distance for debugging (optional)
  Serial.print("Distance: ");
  Serial.println(distance);

  return distance;
}
// Pin Definitions
const int enableA= 9;
const int Pin1 = 8;
const int Pin2 = 10;
const int enableB = 11;
const int Pin3 = 12;
const int Pin4 = 13;
const int trigPin = 2; // Ultrasonic sensor trig pin
const int echoPin = 3; // Ultrasonic sensor echo pin

// Variables
long duration;
int distance;

void setup() {
  // Set motor pins as output
  pinMode(enableA, OUTPUT);
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(Pin3, OUTPUT);
  pinMode(Pin4, OUTPUT);
  
  // Set ultrasonic sensor pins
  pinMode(trigPin, OUTPUT); // Set trig pin as output
  pinMode(echoPin, INPUT);   // Set echo pin as input
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Move the DC motors forward
  moveForward();
  
  // Check distance
  int dist = getDistance();
  
  // If obstacle detected within 20cm, stop the car
  if (dist <= 20) {
    stopCar();
    delay(1000); // Brief delay to stop the car completely
  }
}

// Function to move the car forward
void moveForward() {
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

// Function to measure distance using ultrasonic sensor
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Speed of sound in air is approximately 0.034 cm per microsecond

  // Print distance for debugging (optional)
  Serial.print("Distance: ");
  Serial.println(distance);

  return distance;
}
