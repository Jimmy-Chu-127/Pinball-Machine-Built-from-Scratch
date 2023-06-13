// Import library
#include <FastLED.h>

// Define variables
#define NUM_LEDS 74
#define LED_PIN 12
#define LED_TYPE WS2811
#define COLOR_ORDER GRB 
#define BRIGHTNESS 150

CRGB leds[NUM_LEDS];

long ledTime = millis();
int ledBlink = LOW; // indicator for scoring
int ledReset = LOW; // indicator for resetting
int ledScore = LOW; // indicator for scoring
int blinkTimes = 0;
  
void setupLED(){
  //Initialize LED strip
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip); 
  FastLED.setBrightness(BRIGHTNESS);
}

void ledSystem(int state, long curTime) {
  switch (state) {
    case 0:
      if(ledBlink == LOW && ledReset == LOW && ledScore == LOW){
        // Set rainbow color for the LED strip
        int hue = 0;
        for(int i = 0; i < NUM_LEDS; i++){
          leds[i] = CHSV(hue, 255, BRIGHTNESS);
          hue += 255/NUM_LEDS;
        }
        
        blinkTimes = 0;
        ledTime = curTime;
        
        FastLED.show();

      }else if(ledScore == HIGH){
        // change LED color for 0.1s
        if (curTime - ledTime < 100){
          int hue = 120;
          for(int i = 0; i < NUM_LEDS; i++){
            leds[i] = CHSV(hue, 255, BRIGHTNESS);
          }
          FastLED.show();
        }else{
          ledScore = LOW;
          ledTime = curTime;
        }
        
      }else if(ledBlink == HIGH){
        // Blink the LED 3 times
        if (blinkTimes < 3){
            if(curTime - ledTime < 200){
              for(int i = 0; i < NUM_LEDS; i++){
                leds[i] = CHSV(0, 255, 0);
              }
              FastLED.show();
            }else if (curTime - ledTime >= 200 && curTime - ledTime < 400){
              int hue = int(random(0, 255));
              for(int i = 0; i < NUM_LEDS; i++){
                leds[i] = CHSV(hue, 255, BRIGHTNESS);
              }
              FastLED.show();
            }else{
              ledTime = curTime;
              blinkTimes ++;
            }
        }else{
          ledBlink = LOW;
          ledTime = curTime;
          blinkTimes = 0;
        }
        
      }else if(ledReset == HIGH){
        // Turn off the LED for 3s
        if (curTime - ledTime < 3000){
          for(int i = 0; i < NUM_LEDS; i++){
            leds[i] = CHSV(0, 255, 0);
          }
          FastLED.show();
        }else{
          ledTime = curTime;
          ledReset = LOW;
          blinkTimes = 0;
        }
      }
      
      break;
      
    case 1:
      // Start blinking the LED
      ledBlink = HIGH;
      ledReset = LOW;
      ledScore = LOW;
      
      break;

    case 2:
      // Reset the LED
      ledReset = HIGH;
      ledBlink = LOW;
      ledScore = LOW;

    case 3:
      // change color for scoring
      ledScore = HIGH;
      ledBlink = LOW;
      ledReset = LOW;
      
      break;

    default:
      // Turn off all the LEDs
      for(int i = 0; i < NUM_LEDS; i++){
        leds[i] = CHSV(0, 255, 0);
      }
      FastLED.show();

      break;
  }
}

void ledOFF(){
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CHSV(0, 255, 0);
  }
  FastLED.show();
}
