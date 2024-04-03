#include <Arduino.h>

class Motor {
private:
    int dir, pwm;
    int speed = 0;
    float k;

public:
    Motor(int dir, int pwm, float k = 1.0f);
    
    void setSpeed(int speed);
    void stopMotor(int break_time);
    void moveMilliseconds(int time, int speed);
};