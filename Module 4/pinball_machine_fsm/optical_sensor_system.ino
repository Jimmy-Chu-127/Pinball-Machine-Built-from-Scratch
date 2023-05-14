const int irLED1Pin = 12;
const int irRev1Pin = A2; 
int ir1Val;

const int irLED2Pin = 13;
const int irRev2Pin = A3; 
int ir2Val;

const int threshold = 600;

// Set up pins
void setupOpticalSensorSystem() {
  pinMode(irLED1Pin, OUTPUT);
  pinMode(irRev1Pin, INPUT);
  pinMode(irLED2Pin, OUTPUT);
  pinMode(irRev2Pin, INPUT);
}

// Detect if the pinball passes through optical sensor circuit 1
int ir1BallDetected() {
  ir1Val = analogRead(irRev1Pin);
  
  if (ir1Val <= threshold){
    return LOW;
  }

  return HIGH;
}

// Detect if the pinball passes through optical sensor circuit 2
int ir2BallDetected() {
  ir2Val = analogRead(irRev2Pin);
  
  if (ir2Val <= threshold){
    return LOW;
  }

  return HIGH;
}
