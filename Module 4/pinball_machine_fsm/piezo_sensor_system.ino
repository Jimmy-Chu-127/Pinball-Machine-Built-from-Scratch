const int piezo1Pin = A0; 
const int piezo2Pin = A1;
const int piezo3Pin = A2;
const int pThreshold = 100;

int p1Val;
int p2Val;
int p3Val;

// Set up pins
void setupPiezoSensorSystem() {
  pinMode(piezo1Pin, INPUT);
  pinMode(piezo2Pin, INPUT);
  pinMode(piezo3Pin, INPUT);
}

// Detect if the pinball passes through
int piezoBallDetected() {
  p1Val = analogRead(piezo1Pin);
  p2Val = analogRead(piezo2Pin);
  p3Val = analogRead(piezo3Pin);
  if (p1Val > pThreshold || p2Val > pThreshold || p3Val > pThreshold){
    return HIGH;
  }

  return LOW;
}
