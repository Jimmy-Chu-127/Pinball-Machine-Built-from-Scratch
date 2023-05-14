const int knockSensor = A0;
const int threshold = 100;

int sensorReading;
int knockDetected = LOW;
long knock_time = millis();
long now_time;

void setup() {
  pinMode(knockSensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  now_time = millis();
  sensorReading = analogRead(knockSensor);
  //Serial.println(sensorReading);

  if (sensorReading >= threshold && knockDetected == LOW) {
    Serial.println("Knock detected");
    knockDetected = HIGH;
    knock_time = now_time;
  }

  if (knockDetected == HIGH && now_time - knock_time > 300){
    knockDetected = LOW;
  }
}
