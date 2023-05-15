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
        // Turn on buzzer for 1s
        if (curTime - buzzerTime < 1000){
          tone(buzzerPin, 1000);
        }else{
          noTone(buzzerPin);
          buzzerOn = LOW;
          buzzerTime = curTime;
        }
      }else{
        // Turn on buzzer of 3s
        if (curTime - buzzerTime < 3000){
          tone(buzzerPin, 200);
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
