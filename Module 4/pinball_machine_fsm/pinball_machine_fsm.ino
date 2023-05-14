// Set up timers
long nowTime;

long flipper1Time = millis();
long flipper2Time = millis(); 

long slingshot1Time = millis();
long slingshot2Time = millis(); 

long piezoTime = millis();
 
long displayTime = millis();
long ir1Time = millis();
long ir2Time = millis();

// Define states
enum FSMState {
  ON,
  SCORE,
  RESET
};
FSMState currentState;

int ledState;
int buzzerState;
int score = 0;

// Define functions
void displayCurrentScore(){
  if(nowTime - displayTime > 20){
    displayTime = nowTime;
  }else if(nowTime - displayTime < 10){
    setDisplay(1, score / 10);
  }else{
    setDisplay(2, score % 10);
  }
}

void setup() {
  setupDisplay();
  setupOpticalSensorSystem();
  setupPiezoSensorSystem();
  setupFlipper();
  setupSlingshot();
  setupSpinningWheel();
  setupBuzzer();
  setupLED();

  currentState = RESET;
}

void loop() {
  nowTime = millis();
  
  switch (currentState) {
    case ON:
      // Check the optical scoring system and the corresponding timer
      if (ir1BallDetected() == HIGH && nowTime - ir1Time > 300 ){
        currentState = SCORE;
        ir1Time = nowTime;
      }

      // Check the piezo sensor system and the corresponding timer
      if (piezoBallDetected() == HIGH && nowTime - piezoTime > 300){
        currentState = SCORE;
        piezoTime = nowTime;
      }

      // Check flipper1 system and the corresponding timer
      if (flipper1Button() == HIGH && nowTime - flipper1Time > 300){
        flipper1Flip();
        flipper1Time = nowTime;
      }

      // Check flipper2 system and the corresponding timer
      if (flipper2Button() == HIGH && nowTime - flipper2Time > 300){
        flipper2Flip();
        flipper2Time = nowTime;
      }

      // Check slingshot1 system and the corresponding timer
      if (slingshot1Switch() == HIGH && nowTime - slingshot1Time > 300){
        slingshot1Shot();
        slingshot1Time = nowTime;
      }

      // Check slingshot2 system and the corresponding timer
      if (slingshot2Switch() == HIGH && nowTime - slingshot2Time > 300){
        slingshot2Shot();
        slingshot2Time = nowTime;
      }

      // Check the resetting system and the corresponding timer
      if (ir2BallDetected() == HIGH && nowTime - ir2Time > 300 ){
        currentState = RESET;
        ir2Time = nowTime;
      }
      
      ledState = 0;
      buzzerState = 0;
      
      break;

    case SCORE:
      // Score increases, LEDs blink, buzzer rings
      score++; 
      currentState = ON; // return to ON state

      ledState = 1;
      buzzerState = 1;   
      
      break;

    case RESET:
      score = 0;
      currentState = ON; // return to ON state

      ledState = 2;
      buzzerState = 2;
      
      break;
  }

  displayCurrentScore();
  setWheelSpeed();
  ledSystem(ledState);
  buzzerSystem(buzzerState);
}
