const int slingshot1Pin = 7;
const int slingshot2Pin = 8;
const int slingshot1SwitchPin = 26;
const int slingshot2SwitchPin = 27; 

int slingshot1On = LOW;
int slingshot2On = LOW;
long s1OnTime = millis();
long s2OnTime = millis();

//Set up pins
void setupSlingshot() {
  pinMode(slingshot1Pin, OUTPUT);
  pinMode(slingshot2Pin, OUTPUT);
  pinMode(slingshot1SwitchPin, INPUT);
  pinMode(slingshot2SwitchPin, INPUT);
}

// Read from switch 1
int slingshot1Switch() {
  //Serial.println("s1: "+ String(digitalRead(slingshot1SwitchPin)));
  return digitalRead(slingshot1SwitchPin);
}

// Read from switch 2
int slingshot2Switch() {
  //Serial.println("s2: "+ String(digitalRead(slingshot2SwitchPin)));
  return digitalRead(slingshot2SwitchPin);
}

// Turn on and off slingshot 1

void slingshot1Shot(int state, long curTime){
  switch(state){
    case 0:
      if(slingshot1On == LOW){
        s1Off();
        s1OnTime = curTime;
      }else{
        // Turn on slingshot for 0.2s
        //Serial.println("s1 on");
        if(curTime - s1OnTime < 200){
          s1On();
        }else{
          s1Off();
          s1OnTime = curTime;
          slingshot1On = LOW;
        }
      }
      break;
      
    case 1:
      slingshot1On = HIGH;
      break;
      
    default:
      s1Off();
      break;
  }
}

// Turn on slingshot 1
void s1On() {
  digitalWrite(slingshot1Pin, HIGH);
}

// Turn off slingshot 1
void s1Off() {
  digitalWrite(slingshot1Pin, LOW);
}

// Turn on slingshot 2
void slingshot2Shot(int state, long curTime){
  switch(state){
    case 0:
      if(slingshot2On == LOW){
        s2Off();
        s2OnTime = curTime;
      }else{
        // Turn on slingshot for 0.2s
        //Serial.println("s2 on");
        if(curTime - s2OnTime < 200){
          s2On();
        }else{
          s2Off();
          s2OnTime = curTime;
          slingshot2On = LOW;
        }
      }
      break;
      
    case 1:
      slingshot2On = HIGH;
      break;
      
    default:
      s2Off();
      break;
  }
}

// Turn on slingshot 2
void s2On() {
  digitalWrite(slingshot2Pin, HIGH);
}

// Turn off slingshot 2
void s2Off() {
  digitalWrite(slingshot2Pin, LOW);
}
