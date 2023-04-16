#include <Servo.h>

Servo servo;

int potPin0 = A0;
int servoPin = 9;

int potPin1 = A1;
int motorPin = 10;

int inputPin = 3;
int solPin = 4;


void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  
  pinMode(motorPin,OUTPUT);
  
  pinMode(inputPin, INPUT);
  pinMode(solPin, OUTPUT);
}

void loop() {
  // Read potentiometer 0 and write value to the servo
  int potValue0 = analogRead(potPin0);
  int servoAngle = map(potValue0, 0, 1023, 0, 180); 
  servo.write(servoAngle);

  // Read potentiometer 1 and write value to the motor
  int potValue1 = analogRead(potPin1);
  int motorSpeed = map(potValue1, 0, 1023, 0, 255);
  analogWrite(motorPin, motorSpeed);

  // Read inputPin and write value to the solenoid
  int inputPinVal = digitalRead(inputPin);
  if (inputPinVal == HIGH){
    digitalWrite(solPin, HIGH);
  }else{
    digitalWrite(solPin, LOW);
  }

  // Display the values
  Serial.print("potentiometer 0 = ");
  Serial.print(potValue0);
  Serial.print("\t potentiometer 1 = ");
  Serial.print(potValue1);
  Serial.print("\t D3 pin = ");
  Serial.println(inputPinVal);

  delay(10);
}
