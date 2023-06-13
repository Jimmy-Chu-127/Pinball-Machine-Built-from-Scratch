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
        // noTone(buzzerPin);
        digitalWrite(buzzerPin, LOW);
        buzzerTime = curTime;
      }else if (buzzerScore == HIGH){
        // Turn on buzzer for 0.1s
        if (curTime - buzzerTime < 100){
          // tone(buzzerPin, 1000);
          digitalWrite(buzzerPin, HIGH);
        }else{
          //noTone(buzzerPin);
          digitalWrite(buzzerPin, LOW);
          buzzerScore = LOW;
          buzzerTime = curTime;
        }
      }else if (buzzerRoundLost == HIGH){
        // Turn on buzzer for 0.5s
        if (curTime - buzzerTime < 500){
          // tone(buzzerPin, 2000);
          digitalWrite(buzzerPin, HIGH);
        }else{
          // noTone(buzzerPin);
          digitalWrite(buzzerPin, LOW);
          buzzerRoundLost = LOW;
          buzzerTime = curTime;
        }
      }else{
        // Turn on buzzer of 2s
        if (curTime - buzzerTime < 2000){
          //tone(buzzerPin, 3000);
          digitalWrite(buzzerPin, HIGH);
        }else{
          noTone(buzzerPin);
          digitalWrite(buzzerPin, LOW);
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
      // noTone(buzzerPin);
      digitalWrite(buzzerPin, LOW);
      break;
      
  }
}
