int dataPin = 4;
int latchPin = 3; 
int clkPin = 2;
int displayOnePin = 9;
int displayTwoPin = 10; 
//int displayThreePin = 11;
//int displayFourPin = 12; 

// byte digits[] = {
//   B00000001, // 0
//   B01001111, // 1
//   B00010010, // 2
//   B00000110, // 3
//   B01001100, // 4
//   B00100100, // 5
//   B00100000, // 6
//   B00001111, // 7
//   B00000000, // 8
//   B00000100  // 9
// };

const byte digits[] = {
  B01111110, // 0
  B00110000, // 1
  B01101101, // 2
  B01111001, // 3
  B00110011, // 4
  B01011011, // 5
  B01011111, // 6
  B01110000, // 7
  B01111111, // 8
  B01111011  // 9
};

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clkPin, OUTPUT);
  pinMode(displayOnePin, OUTPUT);
  pinMode(displayTwoPin, OUTPUT);
//  pinMode(displayThreePin, OUTPUT);
//  pinMode(displayFourPin, OUTPUT);
}

void loop() {
//  // For one-digit display (0 to 9)
//  for (byte i = 0; i <= 9; i++) {
//    digitalWrite(latchPin, HIGH);
//    digitalWrite(displayOnePin, HIGH);
//    shiftOut(dataPin, clkPin, LSBFIRST, digits[i]);
//    digitalWrite(latchPin, LOW);
//    delay(500);
//    digitalWrite(displayOnePin, LOW);
//  }

  // For two-digit displays (0 to 99)
  for (byte i = 0; i <= 9; i++) {
    for (byte j = 0; j <= 9; j++){
      for (int k = 0; k < 25; k++){
        digitalWrite(latchPin, HIGH);
        digitalWrite(displayOnePin, HIGH);
        shiftOut(dataPin, clkPin, LSBFIRST, digits[i]);
        digitalWrite(latchPin, LOW);
        delay(10);
        digitalWrite(displayOnePin, LOW);
        
        digitalWrite(latchPin, HIGH);
        digitalWrite(displayTwoPin, HIGH);
        shiftOut(dataPin, clkPin, LSBFIRST, digits[j]);
        digitalWrite(latchPin, LOW);
        delay(10);
        digitalWrite(displayTwoPin, LOW);        
      }
    }
  }
  
//  // For four-digit displays (0 to 9999)
//  for (byte i = 0; i <= 9; i++) {
//    for (byte j = 0; j <= 9; j++){
//      for (byte k = 0; k <= 9; k++){
//        for (byte l = 0; l <= 9; l++){
//          for (int m = 0; m < 25; m++){
//            digitalWrite(latchPin, HIGH);
//            digitalWrite(displayOnePin, HIGH);
//            shiftOut(dataPin, clkPin, LSBFIRST, digits[i]);
//            digitalWrite(latchPin, LOW);
//            delay(5);
//            digitalWrite(displayOnePin, LOW);
//            
//            digitalWrite(latchPin, HIGH);
//            digitalWrite(displayTwoPin, HIGH);
//            shiftOut(dataPin, clkPin, LSBFIRST, digits[j]);
//            digitalWrite(latchPin, LOW);
//            delay(5);
//            digitalWrite(displayTwoPin, LOW);  
//    
//            digitalWrite(latchPin, HIGH);
//            digitalWrite(displayThreePin, HIGH);
//            shiftOut(dataPin, clkPin, LSBFIRST, digits[k]);
//            digitalWrite(latchPin, LOW);
//            delay(5);
//            digitalWrite(displayThreePin, LOW);
//            
//            digitalWrite(latchPin, HIGH);
//            digitalWrite(displayFourPin, HIGH);
//            shiftOut(dataPin, clkPin, LSBFIRST, digits[l]);
//            digitalWrite(latchPin, LOW);
//            delay(5);
//            digitalWrite(displayFourPin, LOW);  
//          }
//        }
//      }
//    }
//  }
  
}
