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
long ir3Time = millis();

// Define states
enum FSMState {
  ON,
  OFF,
  SCORE,
  RESET
};
FSMState currentState;

int ledState;
int buzzerState;
int servoState;
int score = 0;
int roundCnt = 3;

int slingshot1State;
int slingshot2State;

// Define functions
//void displayCurrentScore(){
//  if(nowTime - displayTime > 20){
//    displayTime = nowTime;
//  }else if(nowTime - displayTime < 10){
//    setDisplay(1, score / 10);
//  }else{
//    setDisplay(2, score % 10);
//  }
//}

void setup() {
  Serial.begin(9600);
  setupDisplay();
  setupOpticalSensorSystem();
  setupPiezoSensorSystem();
  setupFlipper();
  setupSlingshot();
  setupSpinningWheel();
  setupBuzzer();
  setupLED();
  setupServo();
  setupPower();

  currentState = ON;
}

void loop() {
  //Serial.println(2);
  nowTime = millis();
//  if (powerButtonOn() == HIGH){
//    currentState = ON;
//  }else{
//    currentState = OFF;
//  }
  
  switch (currentState) {
    case OFF:
      return;   
    case ON:
      // Check the optical scoring system and the corresponding timer
      if (ir1BallDetected() == HIGH && nowTime - ir1Time > 300){
        currentState = SCORE;
        ir1Time = nowTime;
      }
//
      if (ir2BallDetected() == HIGH && nowTime - ir2Time > 300){
        currentState = SCORE;
        ir2Time = nowTime;
      }

      // Check the piezo sensor system and the corresponding timer
      if (piezoBallDetected() == HIGH && nowTime - piezoTime > 1000){
        currentState = SCORE;
        piezoTime = nowTime;
      }

      // Check flipper1 system and the corresponding timer
//      if (flipper1Button() == HIGH && nowTime - flipper1Time > 300){
//        flipper1Flip();
//        flipper1Time = nowTime;
//      }
      if (flipper1Button() == HIGH){
        flipper1On();
      }else{
        flipper1Off();
      }

      // Check flipper2 system and the corresponding timer
//      if (flipper2Button() == HIGH && nowTime - flipper2Time > 300){
//        flipper2Flip();
//        flipper2Time = nowTime;
//      }
      if (flipper2Button() == HIGH){
        flipper2On();
      }else{
        flipper2Off();
      }

      // Check slingshot1 system and the corresponding timer
      if (slingshot1Switch() == HIGH && nowTime - slingshot1Time > 300){
        slingshot1Time = nowTime;
        slingshot1State = 1;
      }else{
        slingshot1State = 0;
      }
      
//      if (slingshot1Switch == HIGH){
//        slingshot1On();
//      }else{
//        slingshot1Off();
//      }

      // Check slingshot2 system and the corresponding timer
      if (slingshot2Switch() == HIGH && nowTime - slingshot2Time > 300){
        slingshot2Time = nowTime;
        slingshot2State = 1;
      }else{
        slingshot2State = 0;
      }
      
//      if (slingshot2Switch == HIGH){
//        slingshot2On();
//      }else{
//        slingshot2Off();
//      }      

      // Check the resetting system and the corresponding timer
      if (ir3BallDetected() == HIGH && nowTime - ir3Time > 5000 ){
          //Serial.println("Detected");
          roundCnt = roundCnt-1;
          if(roundCnt == 0){
            currentState = RESET;
            buzzerState = 2; // ring for 1.5s
            servoState = 1; // round lost state
          }else{
            currentState = ON;
            buzzerState = 1; // ring for 0.3s
            servoState = 1; // round lost state
          }
        ir3Time = nowTime;
      }else{
        buzzerState = 0;
        servoState = 0;
      }
      
      ledState = 0;
      
      break;

    case SCORE:
      // Score increases, LEDs blink, buzzer rings
      score++; 
      currentState = ON; // return to ON state

      ledState = 1;
      buzzerState = 3; // ring for 0.1s
      servoState = 0;
      
      break;

    case RESET:
      score = 0;
      roundCnt = 3; // reset round count
      currentState = ON; // return to ON state

      ledState = 2;
      buzzerState = 2; // ring for 1.5s
      servoState = 1; // round lost state
      
      break;
  }

//  displayCurrentScore();
//  Serial.println(score);
//  if(servoState == 1){
//  Serial.println(servoState);
//  }
  slingshot1Shot(slingshot1State, nowTime);
  slingshot2Shot(slingshot2State, nowTime);
  
  setDisplay(score);
  setWheelSpeed();
  ledSystem(ledState, nowTime);
  buzzerSystem(buzzerState, nowTime);
  servoSystem(servoState, nowTime);
  Serial.println(roundCnt);
  //Serial.println("-------------------------------");
}
