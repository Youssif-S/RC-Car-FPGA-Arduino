	 


const int prox0Echo = 4;    // Back Echo
const int prox1Echo = 6;    // Left Echo
const int prox2Echo = 8;    // Forward Echo
const int prox3Echo = 10;   // Right Echo

const int prox0Trig = 5;    // Back Trig
const int prox1Trig = 7;    // Left Trig
const int prox2Trig = 9;    // Forward Trig
const int prox3Trig = 11;   // Right Trig

// Define Output pins
const int backSig = 2;
const int leftSig = 3;
const int frontSig = 12;
const int rightSig = 13;

int duration0, duration1, duration2, duration3;
float distance0, distance1, distance2, distance3;

void setup() {
  Serial.begin(9600);

  // Initialize Trigger Pins as OUTPUT and set them LOW
  pinMode(prox0Trig, OUTPUT);
  digitalWrite(prox0Trig, LOW);
  pinMode(prox1Trig, OUTPUT);
  digitalWrite(prox1Trig, LOW);
  pinMode(prox2Trig, OUTPUT);
  digitalWrite(prox2Trig, LOW);
  pinMode(prox3Trig, OUTPUT);
  digitalWrite(prox3Trig, LOW);

  // Initialize Echo Pins as INPUT
  pinMode(prox0Echo, INPUT);
  pinMode(prox1Echo, INPUT);
  pinMode(prox2Echo, INPUT);
  pinMode(prox3Echo, INPUT);

  // Initialize Signal Pins as OUTPUT
  pinMode(backSig, OUTPUT);
  pinMode(leftSig, OUTPUT);
  pinMode(frontSig, OUTPUT);
  pinMode(rightSig, OUTPUT);
}

void loop() {
  // Measure Back Distance
  digitalWrite(prox0Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(prox0Trig, LOW);
  duration0 = pulseIn(prox0Echo, HIGH);
  distance0 = duration0 / 58.0;

  // Measure Left Distance
  digitalWrite(prox1Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(prox1Trig, LOW);
  duration1 = pulseIn(prox1Echo, HIGH);
  distance1 = duration1 / 58.0;

  // Measure Forward Distance
  digitalWrite(prox2Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(prox2Trig, LOW);
  duration2 = pulseIn(prox2Echo, HIGH);
  distance2 = duration2 / 58.0;

  // Measure Right Distance
  digitalWrite(prox3Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(prox3Trig, LOW);
  duration3 = pulseIn(prox3Echo, HIGH);
  distance3 = duration3 / 58.0;

  // Variables to store signal states
  bool backState = LOW;
  bool leftState = LOW;
  bool frontState = LOW;
  bool rightState = LOW;

  // Determine the minimum distance direction and set signals accordingly
  if (distance0 < distance1 && distance0 < distance2 && distance0 < distance3) {
    backState = HIGH;
  } else if (distance1 < distance0 && distance1 < distance2 && distance1 < distance3) {
    leftState = HIGH;
  } else if (distance2 < distance0 && distance2 < distance1 && distance2 < distance3) {
    frontState = HIGH;
  } else if (distance3 < distance0 && distance3 < distance1 && distance3 < distance2) {
    rightState = HIGH;
  }

  // Update Signal Pins
  digitalWrite(backSig, backState);
  digitalWrite(leftSig, leftState);
  digitalWrite(frontSig, frontState);
  digitalWrite(rightSig, rightState);

  // Print all distance measurements to Serial
  Serial.print("Back: ");
  Serial.print(distance0);
  Serial.print(" cm\t");

  Serial.print("Left: ");
  Serial.print(distance1);
  Serial.print(" cm\t");

  Serial.print("Forward: ");
  Serial.print(distance2);
  Serial.print(" cm\t");

  Serial.print("Right: ");
  Serial.print(distance3);
  Serial.print(" cm\t");

  // Print Signal States
  Serial.print("BackSig: ");
  Serial.print(backState == HIGH ? "HIGH" : "LOW");
  Serial.print("\t");

  Serial.print("LeftSig: ");
  Serial.print(leftState == HIGH ? "HIGH" : "LOW");
  Serial.print("\t");

  Serial.print("FrontSig: ");
  Serial.print(frontState == HIGH ? "HIGH" : "LOW");
  Serial.print("\t");

  Serial.print("RightSig: ");
  Serial.println(rightState == HIGH ? "HIGH" : "LOW");

  // Small delay to avoid flooding the serial monitor
  delay(200);
}

