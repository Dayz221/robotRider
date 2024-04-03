#include <Arduino.h>

class Motor {
private:
    int dir, pwm;
    int speed;
    float k;

public:
    Motor(int dir, int pwm, float k = 1.0f);
    
    void setSpeed(int speed);
    void stopMotor(int break_time);
};

