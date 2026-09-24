#include <Servo.h>   // Servo library
int gasSensor = A0;   // Gas sensor pin
int buzzer = 8;       // Buzzer pin
int servoPin = 11;    // Servo PWM pin (orange wire)
int threshold = 500;  // Gas level limit
Servo myServo;        // Servo object
void setup() {
  pinMode(buzzer, OUTPUT);
  myServo.attach(servoPin);   // Attach servo to pin 11
  myServo.write(0);           // Initial position
  Serial.begin(9600);
}
void loop() {
  int gasValue = analogRead(gasSensor);  // Read gas sensor
  Serial.println(gasValue);
  if (gasValue > threshold) {
    // Buzzer beep
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
    // Servo action
    myServo.write(90);   // Move servo when gas detected
  } else {
    digitalWrite(buzzer, LOW);
    myServo.write(0);    // Servo back to normal position
  }
}

