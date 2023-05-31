int powerButtonPin = 30;

void setupPower(){
  pinMode(powerButtonPin, INPUT);
}

void powerButtonOn(){
  return digitalRead(powerButtonPin); //check if the system is turned on
}
