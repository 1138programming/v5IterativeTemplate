#include "main.h"
#include "libIterativeRobot/commands/Base/StopBase.h"

Base::Base() {
  // Set up motors
  leftMotor = Motor::getMotor(leftBasePort, baseMotorGearset);
  rightMotor = Motor::getMotor(rightBasePort, baseMotorGearset);

  rightMotor->reverse();
}

void Base::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new StopBase());
}

/**
 * Move the base
 * @param left - speed of the left side
 * @param right - speed of the right side
 */
void Base::move(int left, int right) {
  leftMotor->setSpeed(left);
  rightMotor->setSpeed(right);
}
