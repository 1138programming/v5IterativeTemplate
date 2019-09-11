#include "libIterativeRobot/commands/Miscellaneous/Delay.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

Delay::Delay(int duration, int id) {
  this->startTime = 0;
  this->duration = duration;
  this->priority = 1;
  this->id = id;
}

bool Delay::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void Delay::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  startTime = pros::millis();
  printf("Starting delay. ID is %d\n", id);
}

void Delay::execute() {
  //printf("Claw control running\n");
  printf("Time at: %d. ID is %d\n", pros::millis() - startTime, id);
}

bool Delay::isFinished() {
  return pros::millis() - startTime >= duration;
}

void Delay::end() {
  // Code that runs when isFinished() returns true.
  printf("Finished delay. ID is %d\n", id);
}

void Delay::interrupted() {
  printf("Delay interrupted. ID is %d\n", id);
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}

void Delay::blocked() {
}
