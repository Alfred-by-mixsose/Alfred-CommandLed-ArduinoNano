#pragma once
#include <Arduino.h>

class LedStrip{
    public:
        LedStrip(uint8_t pin);
        void Begin();
        void SetBrightness(uint8_t brightness);
        void Upload();
        void State(bool state);
        bool GetState();
        void UpBrightness();
        void DownBrightness();
        uint8_t GetBrightness();

    private:
        uint8_t __brightness;
        uint8_t __led_pin;
        const uint8_t gammaLUT10[10] = {1,   2,   5,  11,  22,  41,  71, 114, 175, 255};
        bool __state;
};