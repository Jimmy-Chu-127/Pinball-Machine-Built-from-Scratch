const int piezo1Pin = A0; 
const int piezo2Pin = A1;
const int pThreshold = 100;

int p1Val;
int p2Val;

// Set up pins
void setupPiezoSensorSystem() {
  pinMode(piezo1Pin, INPUT);
  pinMode(piezo2Pin, INPUT);
}

// Detect if the pinball passes through
int piezoBallDetected() {
  p1Val = analogRead(piezo1Pin);
  p2Val = analogRead(piezo2Pin);
  if (p1Val > pThreshold || p2Val > pThreshold){
    return HIGH;
  }

  return LOW;
}
