#include <Arduino.h>

#ifndef MOTOR_LIB
#define MOTOR_LIB

class Motor {
public:
    Motor(int dir, int pwm, float k = 1.0f, int breakTime = 20);
    void setBreakTime(int breakTime);
    void setSpeed(int speed);
    void stop(int breakTime);
    void stop();

private:
    int dir, pwm;
    int speed = 0;
    float k = 1.0f;
    int breakTime;
};

class EncMotor: public Motor {
public:
    EncMotor(int dir, int pwm, bool isr, float k = 1.0f, int breakTime = 20, int stepsPer360 = 500);
    bool rotateNSteps(int steps, int speed);
    int32_t getEncCnt();

private:
    int stepsPer360;
    int32_t* cnt;
    bool isr;
    int32_t last_steps = 0;
    int32_t start = 0;
};

#endif