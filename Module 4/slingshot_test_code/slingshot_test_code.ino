int copper_tape1 = 2;
int mos_control = 15;

int slingshot_state = 0;

unsigned long now_time = 0;
unsigned long slingshot1_time = 0;

// put your setup code here, to run once:
void setup() {
  Serial.begin(9600);
  pinMode(copper_tape1, INPUT);
  pinMode(mos_control, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(copper_tape1), ISR_slingshot, RISING);
}

void slingshot1(){
  if(slingshot_state == 0){
    Serial.println("low");
    if(now_time - slingshot1_time > 500){
      digitalWrite(mos_control, LOW);
      slingshot1_time = now_time;
    }
  }
  else { //slingshot_state == 1
    slingshot1_time = millis();
    digitalWrite(mos_control, HIGH);
    slingshot_state = 0;
    Serial.println("high");
  }
}

void ISR_slingshot() {
  slingshot_state = 1;
}

// put your main code here, to run repeatedly:
void loop() {

  now_time = millis();
  slingshot1();
}