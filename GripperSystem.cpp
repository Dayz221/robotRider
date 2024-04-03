#include "GripperSystem.h"

class GripperServo{
public:
    GripperServo(int pin, int close_val, int open_val) {
        this->pin = pin;
        this->close_val = close_val;
        this->open_val = open_val;
    }

    GripperServo() : pin(0), close_val(0), open_val(0) {}
    
    GripperServo operator= (GripperServo& other) {
        this->pin = other.pin;
        this->close_val = other.close_val;
        this->open_val = other.open_val;
    }

    void open() {

    }
    void close() {

    }

private:
    int pin;
    int close_val, open_val;
};

class GripperSystem{
public:
    GripperSystem(GripperServo& gripper, GripperServo& lifter) {
        this->gripper = gripper;
        this->lifter = lifter;
    }

    void open_gripper()  {
        gripper.open();
    }

    void close_gripper() {
        gripper.close();
    }

    void open_lifter()   {
        lifter.open();
    }

    void close_lifter()  {
        lifter.close();
    }
private:
    GripperServo gripper, lifter;
};