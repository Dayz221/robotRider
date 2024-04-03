#include <Arduino.h>

#ifndef SHARP
#define SHARP

    const int SHARP_10_80 = 1;
    const int SHARP_4_40 = 2;

class Sharp{
    public:
    Sharp(int pin, int sen);
    Sharp(int pin, float a, float b, float k);
    float getDist();
    void setVmax(float Vmax);
    private:
    float a;
    float k;
    float b;
    float convert(float Vmax);
    float Vmax;
    int pin;
};

#endif