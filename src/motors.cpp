// motors.c

#include <AccelStepper.h>

AccelStepper slider_stepper; // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
AccelStepper rotator_stepper(AccelStepper::FULL4WIRE, 7,8,9,10); 


void setup_steppers(){

  // slider
  slider_stepper.setMaxSpeed(900);
  slider_stepper.setAcceleration(30);
  slider_stepper.moveTo(0);
  
  rotator_stepper.setMaxSpeed(900);
  slider_stepper.setAcceleration(30);
  slider_stepper.moveTo(0);
}

void slide_dist(int dist){
   slider_stepper.moveTo(slider_stepper.currentPosition() + dist);
}


void rotate_angle(int angle){
   rotator_stepper.moveTo(rotator_stepper.currentPosition() + angle);
}


void run_or_off(){
  if (!slider_stepper.run()){
    slider_stepper.disableOutputs();
  } else {
    slider_stepper.enableOutputs();
  }

  if (!rotator_stepper.run()){
    rotator_stepper.disableOutputs();
  } else {
    rotator_stepper.enableOutputs();
  }
}

void run_or_hold(){
    slider_stepper.run();
    rotator_stepper.run();
}