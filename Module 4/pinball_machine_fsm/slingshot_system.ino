const int slingshot1Pin = 7;
const int slingshot2Pin = 8;
const int slingshot1SwitchPin = 26;
const int slingshot2SwitchPin = 27; 

//Set up pins
void setupSlingshot() {
  pinMode(slingshot1Pin, OUTPUT);
  pinMode(slingshot2Pin, OUTPUT);
  pinMode(slingshot1SwitchPin, INPUT);
  pinMode(slingshot2SwitchPin, INPUT);
}

// Read from switch 1
int slingshot1Switch() {
  return digitalRead(slingshot1SwitchPin);
}

// Read from switch 2
int slingshot2Switch() {
  return digitalRead(slingshot2SwitchPin);
}

// Turn on slingshot 1
void slingshot1Shot() {
  digitalWrite(slingshot1Pin, HIGH);
  digitalWrite(slingshot1Pin, LOW);
}

// Turn on slingshot 2
void slingshot2Shot() {
  digitalWrite(slingshot2Pin, HIGH);
  digitalWrite(slingshot2Pin, LOW);
}
