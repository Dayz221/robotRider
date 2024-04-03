#include <Arduino.h>

class GripperServo{
public:
    GripperServo(int pin, int close_val, int open_val);
    GripperServo();
    GripperServo operator= (GripperServo& other);

    void open();
    void close();

private:
    int pin;
    int close_val, open_val;
    void setServo(int pos);
};

class GripperSystem{
public:
    GripperSystem(GripperServo& gripper, GripperServo& lifter);
    void open_gripper();
    void close_gripper();
    void open_lifter();
    void close_lifter();
private:
    GripperServo gripper, lifter;
};