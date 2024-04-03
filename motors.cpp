#include "motors.h"

Motor::Motor(int dir, int pwm, float k) {
  this->dir = dir;
  this->pwm = pwm;
  this->k = k;
  pinMode(dir, OUTPUT);
  pinMode(pwm, OUTPUT);
}

void Motor::setSpeed(int speed) {
  this->speed = speed;
  speed = max(-255, min(255, speed));
  if (speed > 0) {
    digitalWrite(dir, HIGH);
    analogWrite(pwm, k*speed);
  } else if (speed < 0) {
    digitalWrite(dir, LOW);
    analogWrite(pwm, -k*speed);
  } else {
    digitalWrite(dir, LOW);
    digitalWrite(pwm, LOW);
  }
}

void Motor::stopMotor(int break_time) {
  this->setSpeed(-speed);
  delay(break_time);
  this->setSpeed(0);
}

void Motor::moveMilliseconds(int time, int speed) {
  this->setSpeed(speed);
  uint32_t start = millis();
  while (millis() - start < time);
  this->stopMotor(30);
}