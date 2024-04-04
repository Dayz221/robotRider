#include "Platform.h"

Platform::Platform(EncMotor *leftMotor, EncMotor *rightMotor, float wheelRadius, float clearence, int stepsPer360) {
    this->leftMotor = leftMotor;
    this->rightMotor = rightMotor;
    this->wheelRadius = wheelRadius;
    this->clearence = clearence;
    this->stepsPer360 = stepsPer360;
}

void Platform::move(int left, int right) {
    leftMotor->setSpeed(left);
    rightMotor->setSpeed(right);
}

void Platform::move(int speed) {
    leftMotor->setSpeed(speed);
    rightMotor->setSpeed(speed);
}

void Platform::stop() {
    leftMotor->stop();
    rightMotor->stop();
}

void Platform::moveNSteps(int steps, int speed) {
    while(!leftMotor->rotateNSteps(steps, speed) && !rightMotor->rotateNSteps(steps, speed));
    this->stop();
}

void Platform::rotateNSteps(int steps, int speed) {
    while(!leftMotor->rotateNSteps(steps, -speed) && !rightMotor->rotateNSteps(steps, speed));
    this->stop();
}

void Platform::moveDist(int dist, int speed) {
    int steps = ((float)dist/wheelRadius)*stepsPer360;
    this->moveNSteps(steps, speed);
}

void Platform::rotateAng(int ang, int speed) {
    int steps = ((3.1415 * 2 * clearence * ((float)ang/360))/wheelRadius)*stepsPer360;
    this->rotateNSteps(steps, speed);
}

void Platform::moveMilliseconds(int32_t time, int speed) {
    int32_t start = millis();
    this->move(speed);
    while (millis() - start < time);
    this->stop();
}

void Platform::rotateMilliseconds(int32_t time, int speed) {
    int32_t start = millis();
    this->move(-speed, speed);
    while (millis() - start < time);
    this->stop();
}