const int buzzerPin = 2;
int buzzerOn = LOW; // indicator for scoring
int buzzerReset = LOW; // indicator for resetting
long buzzerTime = millis();

void setupBuzzer(){
  pinMode(buzzerPin, OUTPUT);
}

void buzzerSystem(int state, long curTime) {
  switch(state){
    case 0:
      if (buzzerOn == LOW && buzzerReset == LOW){
        // Keep buzzer off in normal state
        noTone(buzzerPin);
        buzzerTime = curTime;
      }else if (buzzerOn == HIGH){
        // Turn on buzzer for 0.3s
        if (curTime - buzzerTime < 300){
          tone(buzzerPin, 2000);
        }else{
          noTone(buzzerPin);
          buzzerOn = LOW;
          buzzerTime = curTime;
        }
      }else{
        // Turn on buzzer of 1.5s
        if (curTime - buzzerTime < 1500){
          tone(buzzerPin, 3000);
        }else{
          noTone(buzzerPin);
          buzzerReset = LOW;
          buzzerTime = curTime;
        }
      }
      break;
    case 1:
      buzzerOn = HIGH;
      break;
    case 2:
      buzzerOn = LOW;
      buzzerReset = HIGH;
      break;
    default:
      noTone(buzzerPin);
      break;
      
  }
}
