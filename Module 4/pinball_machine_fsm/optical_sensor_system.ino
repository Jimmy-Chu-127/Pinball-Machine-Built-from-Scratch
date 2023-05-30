const int irLED1Pin = 11;
const int irRev1Pin = A3; 
int ir1Val;

const int irLED2Pin = 12;
const int irRev2Pin = A4; 
int ir2Val;

const int irLED3Pin = 13;
const int irRev3Pin = A5; 
int ir3Val;

const int threshold = 300;

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
  //Serial.println(ir1Val);
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

// Detect if the pinball passes through optical sensor circuit 3
int ir3BallDetected() {
  ir3Val = analogRead(irRev3Pin);
  
  if (ir3Val <= threshold){
    return LOW;
  }

  return HIGH;
}
