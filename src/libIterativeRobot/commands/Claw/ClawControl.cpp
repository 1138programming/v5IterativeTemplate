#include "libIterativeRobot/commands/Claw/ClawControl.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

ClawControl::ClawControl(bool Open) {
  this->Open = Open;
  requires(Robot::claw);
  this->priority = 2;
}

bool ClawControl::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void ClawControl::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  if (this->Open)
    Robot::claw->move(KMaxMotorSpeed);
  else
    Robot::claw->move(-KMaxMotorSpeed);
}

void ClawControl::execute() {
}

bool ClawControl::isFinished() {
  return false;
}

void ClawControl::end() {
  // Code that runs when isFinished() returns true.
}

void ClawControl::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}

void ClawControl::blocked() {
}
