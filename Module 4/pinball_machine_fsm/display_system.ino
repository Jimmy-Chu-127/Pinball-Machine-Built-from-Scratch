const int dataPin = 4;
const int latchPin = 3; 
const int clkPin = 2;
const int displayOnePin = 9;
const int displayTwoPin = 10; 

const byte digits_anode[] = {
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

const byte digits_cathode[] = {
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

// Set up pins
void setupDisplay() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clkPin, OUTPUT);
  pinMode(displayOnePin, OUTPUT);
  pinMode(displayTwoPin, OUTPUT);
}

// Show digit on the indicated display
void setDisplay(int index, int digit) {
  if (index == 1){
    digitalWrite(displayOnePin, HIGH);
    digitalWrite(displayTwoPin, LOW);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clkPin, LSBFIRST, digits_cathode[digit]);
    digitalWrite(latchPin, HIGH);
    digitalWrite(displayOnePin, LOW);  
  }else{
    digitalWrite(displayTwoPin, HIGH);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clkPin, LSBFIRST, digits_cathode[digit]);
    digitalWrite(latchPin, HIGH);
    digitalWrite(displayTwoPin, LOW);  
  } 
}
