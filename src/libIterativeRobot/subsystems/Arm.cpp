#include "main.h"
#include "libIterativeRobot/commands/Arm/StopArm.h"

Arm::Arm() {
  // Get arm motors
  armMotor = Motor::getMotor(armPort, armMotorGearset);

  armController = new PIDController(armMotor, 0.32, 0, 0.05);
}

void Arm::initDefaultCommand() {
  StopArm* stopArm = new StopArm();
  //printf("Stop arm address is %p\n", stopArm);
  pros::delay(1000);
  setDefaultCommand(stopArm);
}

/**
 * Move the arm
 * @param left - speed of the left side
 * @param right - speed of the right side
 */
void Arm::move(int speed) {
  //printf("Arm speed is %d\n", speed);
  armMotor->setSpeed(speed);
}

void Arm::setSetpoint(int setpoint) {
  armController->setSetpoint(setpoint);
}

bool Arm::atSetpoint() {
  return armController->atSetpoint();
}

void Arm::loop() {
  armController->loop();
}

void Arm::lock() {
  armController->lock();
}

void Arm::disablePID() {
  armController->disable();
}

void Arm::enablePID() {
  armController->enable();
}
