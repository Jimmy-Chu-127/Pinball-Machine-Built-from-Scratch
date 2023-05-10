const int dataPin = 4;
const int latchPin = 3; 
const int clkPin = 2;
const int displayOnePin = 9;
const int displayTwoPin = 10; 
//const int displayThreePin = 11;
//const int displayFourPin = 12; 

const int IRLedPin = 13;
const int IRRevPin = A0; 
int IRRevVal;
const int threshold = 600;
int score = 0; // player's score
int ballDetected = false; // indicator for pinball detection

long start_time = millis();
long display_time = millis();
long now_time;

const int buzzerPin = 7;
int buzzerEnabled = false;

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

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clkPin, OUTPUT);
  pinMode(displayOnePin, OUTPUT);
  pinMode(displayTwoPin, OUTPUT);
//  pinMode(displayThreePin, OUTPUT);
//  pinMode(displayFourPin, OUTPUT);

  pinMode(IRLedPin, OUTPUT);
  pinMode(IRRevPin, INPUT);

  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  
  IRRevVal = analogRead(IRRevPin); // Read the voltage drop across the photodiode 

  ballDetection();
  
  //Serial.print("IRRevVal = ");
  //Serial.print(IRRevVal);
  //Serial.print("\t Score = ");
  //Serial.println(score);

  if (buzzerEnabled == true) {
    ringBuzzer(); // ring the buzzer
  }

  now_time = millis();
  displayScore(score); // Display the score on the two-digit 7-segment display

  if (now_time - start_time > 500 && ballDetected == true) {
    restartBallDetection(); // Reset the ball detection indicator
  }
}


void ballDetection(){
  // If the value exceed the threshold and the system did not detect a ball 
  // passing just before, increment the score by 1. Reset the timer.
  if (IRRevVal > threshold && ballDetected == false) {
    score++;
    ballDetected = true;
    start_time = millis();
    buzzerEnabled = true;
  }
}


void displayScore(int score) {
  int i = score / 10; // first digit
  int j = score % 10; // second digit

  //  Switch between the two digits every 10 milliseconds
  //Serial.println(now_time - display_time);
  if(now_time - display_time > 20){
    display_time = now_time;
  }else if(now_time - display_time < 10){
    digitalWrite(displayOnePin, HIGH);
    digitalWrite(displayTwoPin, LOW);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clkPin, LSBFIRST, digits_cathode[i]);
    digitalWrite(latchPin, HIGH);
    digitalWrite(displayOnePin, LOW);  
  }else{
    digitalWrite(displayTwoPin, HIGH);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clkPin, LSBFIRST, digits_cathode[j]);
    digitalWrite(latchPin, HIGH);
    digitalWrite(displayTwoPin, LOW);  
  }
}


void restartBallDetection() {
  // Reset the indicator
    ballDetected = false;
    buzzerEnabled = false;
    start_time = now_time;
}


void ringBuzzer() {
  // Ring the buzzer for 0.2s
  if (now_time - start_time < 200){
    tone(buzzerPin, 1000);
  }else{
    noTone(buzzerPin);
  }
}
