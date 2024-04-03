#include <Arduino.h>

class GripperServo{
public:
    GripperServo(int pin, int close_val, int open_val) {};
    GripperServo() : pin(0), close_val(0), open_val(0) {};
    GripperServo operator= (GripperServo& other) {};

    void open() {};
    void close() {};

private:
    int pin;
    int close_val, open_val;
};

class GripperSystem{
public:
    GripperSystem(GripperServo& gripper, GripperServo& lifter) {};
    void open_gripper()  {};
    void close_gripper() {};
    void open_lifter()   {};
    void close_lifter()  {};
private:
    GripperServo gripper, lifter;
};