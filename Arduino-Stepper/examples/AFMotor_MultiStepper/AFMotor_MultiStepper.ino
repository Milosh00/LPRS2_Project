#include <AFMotor.h>

// MultiStepper
// -*- mode: C++ -*-
//
// Control both Stepper motors at the same time with different speeds
// and accelerations.
// Public domain!

#include <AccelStepper.h>
#include <AFMotor.h>

// two stepper motors one on each port
AF_Stepper motor1(200, 1);
AF_Stepper motor2(200, 2);

// you can change these to DOUBLE or INTERLEAVE or MICROSTEP!
// wrappers for the first motor!
void forwardstep1() {  
  motor1.onestep(FORWARD, SINGLE);
}
void backwardstep1() {  
  motor1.onestep(BACKWARD, INTERLEAVE);
}

// wrappers for the second motor!
void forwardstep2() {  
  motor2.onestep(FORWARD, SINGLE);
}
void backwardstep2() {  
  motor2.onestep(BACKWARD, INTERLEAVE);
}

// Motor shield has two motor ports, now we'll wrap them in an AccelStepper object
AccelStepper stepper1(forwardstep1, backwardstep1);
AccelStepper stepper2(backwardstep2, forwardstep2);

void setup()
{ 
    stepper1.setMaxSpeed(600.0);
    stepper1.setAcceleration(300.0);
    stepper1.moveTo(1000);

    stepper2.setMaxSpeed(600.0);
    stepper2.setAcceleration(300.0);
    stepper2.moveTo(1000);
}

void loop()
{
    // Change direction at the limits
    if (stepper1.distanceToGo() == 0)
    stepper1.moveTo(-stepper1.currentPosition());
    stepper1.run();

    if (stepper2.distanceToGo() == 0)
    stepper2.moveTo(-stepper1.currentPosition());
    stepper2.run();
}
