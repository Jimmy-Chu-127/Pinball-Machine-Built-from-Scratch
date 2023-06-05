const int wheel1Pin = 9; 
const int wheel2Pin = 10;
// const int pot1Pin = A0;
// int pot1Val;

// Set up pins
void setupSpinningWheel() {
  pinMode(wheel1Pin, OUTPUT);
  pinMode(wheel2Pin, OUTPUT);
}

// Change the speed of the wheel according to the potentiometer reading
void setWheelSpeed() {
//  pot1Val = analogRead(pot1Pin);
//  int motorSpeed = map(pot1Val, 0, 1023, 0, 255);
//  analogWrite(wheel1Pin, motorSpeed);
  analogWrite(wheel1Pin, 255);
  analogWrite(wheel2Pin, 255);
}
