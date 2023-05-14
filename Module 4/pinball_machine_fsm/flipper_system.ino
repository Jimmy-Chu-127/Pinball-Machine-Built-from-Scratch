const int flipper1Pin = 2; 
const int flipper2Pin = 3;
const int flipper1ButtonPin = 22;
const int flipper2ButtonPin = 23; 

//Set up pins
void setupFlipper() {
  pinMode(flipper1Pin, OUTPUT);
  pinMode(flipper2Pin, OUTPUT);
  pinMode(flipper1ButtonPin, INPUT);
  pinMode(flipper2ButtonPin, INPUT);
}

// Read from button 1
int flipper1Button() {
  return digitalRead(flipper1ButtonPin);
}

// Read from button 2
int flipper2Button() {
  return digitalRead(flipper2ButtonPin);
}

// Turn on flipper 1
void flipper1Flip() {
  digitalWrite(flipper1Pin, HIGH);
  digitalWrite(flipper1Pin, LOW);
}

// Turn on flipper 2
void flipper2Flip() {
  digitalWrite(flipper2Pin, HIGH);
  digitalWrite(flipper2Pin, LOW);
}
