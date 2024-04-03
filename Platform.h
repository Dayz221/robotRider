#include <Arduino.h>
#include "Motor.h"

class Platform {
private:
    EncMotor *leftMotor;
    EncMotor *rightMotor;
    float wheelRadius;
    float clearence;
    int stepsPer360;

public:
    Platform(EncMotor *leftMotor, EncMotor *rightMotor, float wheelRadius = 82, float clearence = 105, int stepsPer360 = 500);
    void move(int left, int right);
    void move(int speed);
    void stop();
    void moveNSteps(int steps, int speed);
    void rotateNSteps(int steps, int speed);
    void moveDist(int dist, int speed);
    void rotateAng(int ang, int speed);
};