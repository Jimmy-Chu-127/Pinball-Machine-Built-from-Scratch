int dataPin = 4;
int latchPin = 3; 
int clkPin = 2; 

byte digits[] = {
  B00000001, // 0
  B01001111, // 1
  B00010010, // 2
  B00000110, // 3
  B01001100, // 4
  B00100100, // 5
  B00100000, // 6
  B00001111, // 7
  B00000000, // 8
  B00000100  // 9
};

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clkPin, OUTPUT);
}

void loop() {
//  // For one-digit display (0 to 9)
//  for (byte i = 0; i <= 9; i++) {
//    digitalWrite(latchPin, HIGH);
//    shiftOut(dataPin, clkPin, LSBFIRST, digits[i]);
//    digitalWrite(latchPin, LOW);
//    delay(500);
//  }

  // For two-digit displays (0 to 99)
  for (byte i = 0; i <= 9; i++) {
    for (byte j = 0; j <= 9; j++){
      digitalWrite(latchPin, HIGH);
      shiftOut(dataPin, clkPin, LSBFIRST, digits[j]);
      shiftOut(dataPin, clkPin, LSBFIRST, digits[i]);
      digitalWrite(latchPin, LOW);
      delay(500);
    }
  }

//  // For four-digit displays (0 to 9999)
//  for (byte i = 0; i <= 9; i++) {
//    for (byte j = 0; j <= 9; j++){
//      for (byte k = 0; k <= 9; k++){
//        for (byte l = 0; l <= 9; l++){
//          digitalWrite(latchPin, HIGH);
//          shiftOut(dataPin, clkPin, LSBFIRST, digits[k]);
//          shiftOut(dataPin, clkPin, LSBFIRST, digits[l]);
//          shiftOut(dataPin, clkPin, LSBFIRST, digits[j]);
//          shiftOut(dataPin, clkPin, LSBFIRST, digits[i]);
//          digitalWrite(latchPin, LOW);
//          delay(500);
//        }
//      }
//    }
//  }
  
}
