#include "led.hpp"

LedStrip::LedStrip(uint8_t pin) {
    __led_pin = pin;
    __brightness = 5;
    __state = false;
}

void LedStrip::SetBrightness(uint8_t brightness) {
    if (brightness >= 10) {
        brightness = 9;
    }
    __brightness = brightness;

    Upload();
}

void LedStrip::Upload() {
    switch (__state)
    {
    case true:
        analogWrite(__led_pin, gammaLUT10[__brightness]);
        break;
    
    case false:
        analogWrite(__led_pin, 0);
        break;
    }
    
};

void LedStrip::Begin() {
    pinMode(__led_pin, OUTPUT);
    Upload();
}

void LedStrip::State(bool state) {
    switch (state) {
        case false:
            __state = false;
            Upload();
            break;
        case true:
            __state = true;
            Upload();
            break;
    }
}

bool LedStrip::GetState() {
    return __state;
}

void LedStrip::UpBrightness() {
    if (GetBrightness() < 9) {
        SetBrightness(GetBrightness()+1);
    }
}

void LedStrip::DownBrightness() {
    if (GetBrightness() > 0) {
        SetBrightness(GetBrightness()-1);
    }
}

uint8_t LedStrip::GetBrightness() {
    return __brightness;
}