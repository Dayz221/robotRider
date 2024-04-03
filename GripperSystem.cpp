#include "GripperSystem.h"

GripperServo::GripperServo(int pin, int close_val, int open_val) {
    this->pin = pin;
    this->close_val = close_val;
    this->open_val = open_val;
}

GripperServo::GripperServo() : pin(0), close_val(0), open_val(0) {}
    
GripperServo GripperServo::operator= (GripperServo& other) {
    this->pin = other.pin;
    this->close_val = other.close_val;
    this->open_val = other.open_val;
    return *this;
}

void GripperServo::open() {

}

void GripperServo::close() {

}



GripperSystem::GripperSystem(GripperServo& gripper, GripperServo& lifter) {
    this->gripper = gripper;
    this->lifter = lifter;
}

void GripperSystem::open_gripper()  {
    gripper.open();
}

void GripperSystem::close_gripper() {
    gripper.close();
}

void GripperSystem::open_lifter()   {
    lifter.open();
}

void GripperSystem::close_lifter()  {
    lifter.close();
}