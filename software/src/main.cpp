#include <Arduino.h>

#define IR_USE_AVR_TIMER1 
#include <IRremote.hpp>

#include "led.hpp"

#define LED_PIN 3
#define IRrecepteur_PIN 2

LedStrip myLedStrip(LED_PIN);

void setup() {
  Serial.begin(9600);

  myLedStrip.Begin();
  IrReceiver.begin(IRrecepteur_PIN, DISABLE_LED_FEEDBACK);
};

void loop() {
  if (IrReceiver.decode()) {
    if (IrReceiver.decodedIRData.command != 0){
      switch (IrReceiver.decodedIRData.command) {
        case 13:
          myLedStrip.State(!myLedStrip.GetState());
          break;
        case 112:
          if (myLedStrip.GetState() == false) {
            myLedStrip.State(true);
          } else {
            myLedStrip.UpBrightness();
          }
          break;
        case 113:
          if (myLedStrip.GetState() == true) {
            myLedStrip.DownBrightness();
          }
          break;
      }
      delay(200);
    }
    IrReceiver.resume();
  }
}