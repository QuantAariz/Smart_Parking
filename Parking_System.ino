// Define pin numbers
const int trigPin = 7;         // Trigger pin of ultrasonic sensor
const int echoPin = 8;         // Echo pin of ultrasonic sensor
const int greenLEDPin = 9;     // Green LED pin
const int redLEDPin = 10;      // Red LED pin

// Define distance thresholds for parking space
const int parkingThreshold = 30;   // Distance in centimeters

void setup() {
  // Set sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set LED pins as outputs
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);

  // Initialize Serial communication
  Serial.begin(9600);
}

void loop() {
  // Measure distance using ultrasonic sensor
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check parking space status
  if (distance < parkingThreshold) {
    // Space occupied
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(redLEDPin, HIGH);
  } else {
    // Space available
    digitalWrite(greenLEDPin, HIGH);
    digitalWrite(redLEDPin, LOW);
  }

  // Small delay to avoid rapid switching
  delay(500);
}
