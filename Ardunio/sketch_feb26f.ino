// Pin Definitions
const int enableA = 9;
const int Pin1 = 8;
const int Pin2 = 10;
const int enableB = 11;
const int Pin3 = 12;
const int Pin4 = 13;
const int trigPin = 2;   // Ultrasonic sensor 1 trig pin
const int echoPin = 3;   // Ultrasonic sensor 1 echo pin


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
  
  // Set ultrasonic sensor 1 pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Move the DC motors forward
  moveForward();
  
  // Check distance from ultrasonic sensor 1
  distance = getDistance(trigPin, echoPin);
  
  // If obstacle detected within 20cm from sensor 1, stop the car
  if (distance <= 20) {
    stopCar();
    delay(1000); // Brief delay to stop the car completely
  
}

// Function to move the car forward
void moveForward() {
  digitalWrite(Pin1, LOW);
  digitalWrite(Pin2, HIGH);
  digitalWrite(Pin3, LOW);
  digitalWrite(Pin4, HIGH);
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
