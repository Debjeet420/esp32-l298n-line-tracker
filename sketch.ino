// IR Sensor Pin Definitions (Pushbuttons)
#define LEFT_IR 18
#define RIGHT_IR 19

// L298N Direction Control Pins
#define IN1 25
#define IN2 26
#define IN3 27
#define IN4 14

void setup() {
  Serial.begin(115200);

  // Configure sensors with pull-down resistors
  pinMode(LEFT_IR, INPUT_PULLDOWN);
  pinMode(RIGHT_IR, INPUT_PULLDOWN);

  // Configure L298N output pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopRobot();
  Serial.println("Line Follower Ready.");
}

void loop() {
  int leftState = digitalRead(LEFT_IR);
  int rightState = digitalRead(RIGHT_IR);

  Serial.print("Left: ");
  Serial.print(leftState);
  Serial.print(" | Right: ");
  Serial.println(rightState);

  if (leftState == 0 && rightState == 0) {
    moveForward();  // Unpressed -> L FWD & R FWD LEDs glow Green
  } else if (leftState == 1 && rightState == 0) {
    turnLeft();     // Left pressed -> L REV glows Red, R FWD glows Green
  } else if (leftState == 0 && rightState == 1) {
    turnRight();    // Right pressed -> L FWD glows Green, R REV glows Red
  } else {
    stopRobot();    // Both pressed -> All LEDs turn OFF
  }

  delay(150);
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}