#include "Motor.h"

int32_t first_motor_cnt = 0;
int32_t second_motor_cnt = 0;

void interrupt_first() {
    first_motor_cnt++;
}

void interrupt_second() {
    second_motor_cnt++;
}

Motor::Motor(int dir, int pwm, float k, int breakTime) : dir(dir), pwm(pwm), k(k), breakTime(breakTime) {
    pinMode(dir, OUTPUT);
    pinMode(pwm, OUTPUT);
}

void Motor::setSpeed(int speed) {
    speed = max(-255, min(255, speed));
    this->speed = speed;

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

void Motor::setBreakTime(int breakTime) {
    this->breakTime = breakTime;
}

void Motor::stop(int breakTime) {
    if (abs(speed) < 100) {
        this->setSpeed(0);
        return;
    }
    this->setSpeed(-255*(speed/abs(speed)));
    delay(breakTime);
    this->setSpeed(0);
}

void Motor::stop() {
    this->stop(this->breakTime);
}


EncMotor::EncMotor(int dir, int pwm, bool isr, float k, int breakTime): Motor(dir, pwm, k, breakTime) {
    this->isr = isr;

    pinMode((isr) ? 3 : 2, INPUT_PULLUP);

    if (isr) {
        attachInterrupt(isr, interrupt_second, RISING);
        cnt = &second_motor_cnt;
    } else {
        attachInterrupt(isr, interrupt_first, RISING);
        cnt = &first_motor_cnt;
    }
}

int32_t EncMotor::getEncCnt() {
    return (*cnt);
}


// while(!left.rotateNSteps(500, 200));
bool EncMotor::rotateNSteps(int steps, int speed) {
    if (last_steps != steps) {
        last_steps = steps;
        start = this->getEncCnt();
        this->setSpeed(speed);
    };
    
    if (this->getEncCnt()-start>=steps) {
        this->stop();
        return true;
    }

    return false;
}