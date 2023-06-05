const int buzzerPin = 2;
int buzzerRoundLost = LOW; // indicator for round lost
int buzzerReset = LOW; // indicator for resetting
int buzzerScore = LOW; // indicator for scoring
long buzzerTime = millis();

void setupBuzzer(){
  pinMode(buzzerPin, OUTPUT);
}

void buzzerSystem(int state, long curTime) {
  switch(state){
    case 0:
      if (buzzerRoundLost == LOW && buzzerReset == LOW && buzzerScore == LOW){
        // Keep buzzer off in normal state
        noTone(buzzerPin);
        buzzerTime = curTime;
      }else if (buzzerScore == HIGH){
        // Turn on buzzer for 0.1s
        if (curTime - buzzerTime < 100){
          tone(buzzerPin, 1000);
        }else{
          noTone(buzzerPin);
          buzzerScore = LOW;
          buzzerTime = curTime;
        }
      }else if (buzzerRoundLost == HIGH){
        // Turn on buzzer for 0.3s
        if (curTime - buzzerTime < 1500){
          tone(buzzerPin, 2000);
        }else{
          noTone(buzzerPin);
          buzzerRoundLost = LOW;
          buzzerTime = curTime;
        }
      }else{
        // Turn on buzzer of 1.5s
        if (curTime - buzzerTime < 3000){
          tone(buzzerPin, 3000);
        }else{
          noTone(buzzerPin);
          buzzerReset = LOW;
          buzzerTime = curTime;
        }
      }
      break;
    case 1:
      buzzerRoundLost = HIGH;
      buzzerReset = LOW;
      buzzerScore = LOW;
      break;
    case 2:
      buzzerRoundLost = LOW;
      buzzerReset = HIGH;
      buzzerScore = LOW;
      break;
    case 3:
      buzzerScore = HIGH;
      buzzerRoundLost = LOW;
      buzzerReset = LOW;
      break;
    default:
      noTone(buzzerPin);
      break;
      
  }
}
