#include <Servo.h>

// Define the servo and its pin
Servo servo;
const int servoPin = 3;
long servoTime = millis();
int servoOn = LOW;

void setupServo(){
  servo.attach(servoPin);
}

void servoSystem(int state, long curTime){
  switch(state){
    case 0:
      if(servoOn == LOW){
        // Keep the path closed
        servo.write(90);
        servoTime = curTime;
      }else{
        // Open the path for 3s
        //Serial.println("servo on");
        if(curTime - servoTime < 3000){
          //Serial.println(1);
          servo.write(0);
        }else{
          servo.write(90);
          servoTime = curTime;
          servoOn = LOW;
        }
      }
      break;
      
    case 1:
      servoOn = HIGH;
      break;
      
    default:
      servo.write(90);
      break;
  }
}
