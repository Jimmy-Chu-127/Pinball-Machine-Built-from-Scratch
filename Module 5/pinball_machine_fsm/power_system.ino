int powerButtonPin = 30;

void setupPower(){
  pinMode(powerButtonPin, INPUT);
}

int powerButtonOn(){
  //Serial.println("Power: " + String(digitalRead(powerButtonPin)));
  return digitalRead(powerButtonPin); //check if the system is turned on
}
