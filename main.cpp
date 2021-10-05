#include "vex.h"

using namespace vex;
competition Competition;

void pre_auton(void) {
  vexcodeInit();
}
motor_group LDriveGroup = motor_group(BackLeftWheel, FrontLeftWheel);
motor_group RDriveGroup = motor_group(BackRightWheel, FrontRightWheel);
void driveLeft(int speed){ //driving left side of chassis
  BackLeftWheel.setVelocity(speed, percent); //setting speed of back left wheel
  FrontLeftWheel.setVelocity(speed, percent); //setting speed of front left wheel
  LDriveGroup.spin(forward);
  //BackLeftWheel.spin(forward); //turning motor on back left wheel
  //FrontLeftWheel.spin(forward); //turning motor on front left wheel
}

void driveRight(int speed){ //driving right side of chassis
  BackRightWheel.setVelocity(speed, percent); //setting speed of back right wheel
  FrontRightWheel.setVelocity(speed, percent); //setting speed of front right wheel
  RDriveGroup.spin(forward);
  //BackRightWheel.spin(forward); //turning motor on back right wheel
  //FrontRightWheel.spin(forward); //turning motor on front right wheel
}

void autonomous(void) {
  
}

void usercontrol(void) {
  while (1) {
    driveLeft(Controller1.Axis3.value()); //left side of robot controlled by left joystick on controller
    driveRight(Controller1.Axis2.value()); //right side of robot controlled by left joystick on controller

    if (Controller1.ButtonR1.pressing()){ //top right button pressed
      Arm.setVelocity(-100, percent); //arm moves up 90% of full speed
      Arm.spin(forward);
    }
    else if (Controller1.ButtonR2.pressing()){ //bottom left button pressed
      Arm.setVelocity(100, percent);
      Arm.spin(forward);
    }
    else{ //nothing is pressed
      Arm.stop(); //Arm.setVelocity(0, percent)
    }
    if (Controller1.ButtonL1.pressing()){ //top right button pressed
      Arm2.setVelocity(100, percent); //arm moves up 90% of full speed
      Arm2.spin(forward);
    }
    else if (Controller1.ButtonL2.pressing()){ //bottom left button pressed
      Arm2.setVelocity(-100, percent);
      Arm2.spin(forward);
    }
    else{ //nothing is pressed
      Arm2.stop(); //Arm.setVelocity(0, percent)
    }
  }
}

int main (void) {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}
