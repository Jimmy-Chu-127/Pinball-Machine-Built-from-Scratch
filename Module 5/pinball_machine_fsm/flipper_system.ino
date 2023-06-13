const int flipper1Pin = 5; 
const int flipper2Pin = 6;
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
  //Serial.println("f1: "+ String(digitalRead(flipper1ButtonPin)));
  return digitalRead(flipper1ButtonPin);
}

// Read from button 2
int flipper2Button() {
  //Serial.println("f2: "+ String(digitalRead(flipper2ButtonPin)));
  return digitalRead(flipper2ButtonPin);
}

// Turn on flipper 1
void flipper1Flip() {
  digitalWrite(flipper1Pin, HIGH);
  digitalWrite(flipper1Pin, LOW);
}

// Turn on flipper 1
void flipper1On() {
  digitalWrite(flipper1Pin, HIGH);
}

// Turn off flipper 1
void flipper1Off() {
  digitalWrite(flipper1Pin, LOW);
}

// Turn on flipper 2
void flipper2Flip() {
  digitalWrite(flipper2Pin, HIGH);
  digitalWrite(flipper2Pin, LOW);
}

// Turn on flipper 2
void flipper2On() {
  digitalWrite(flipper2Pin, HIGH);
}

// Turn off flipper 2
void flipper2Off() {
  digitalWrite(flipper2Pin, LOW);
}
