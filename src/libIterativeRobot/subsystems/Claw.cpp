#include "main.h"
#include "libIterativeRobot/commands/Claw/StopClaw.h"

Claw::Claw() {
  // Get claw motors
  clawMotor = Motor::getMotor(clawPort, clawMotorGearset);
}

void Claw::initDefaultCommand() {
  setDefaultCommand(new StopClaw());
}

/**
 * Move the claw
 * @param speed - speed of the speed side
 * @param right - speed of the right side
 */
void Claw::move(int speed) {
  clawMotor->setSpeed(speed);
  //printf("Motor speed set to %d\n", speed);
}
