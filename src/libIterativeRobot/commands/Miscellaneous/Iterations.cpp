#include "libIterativeRobot/commands/Miscellaneous/Iterations.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

Iterations::Iterations(int iterations, int id) {
  this->currIteration = 0;
  this->iterations = iterations;
  this->priority = 1;
  this->id = id;
}

bool Iterations::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void Iterations::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  currIteration = 0;
  printf("Starting iterations. ID is %d\n", id);
}

void Iterations::execute() {
  //printf("Claw control running\n");
  currIteration++;
  printf("Iteration at: %d. ID is %d\n", currIteration, id);
}

bool Iterations::isFinished() {
  return currIteration >= iterations;
}

void Iterations::end() {
  // Code that runs when isFinished() returns true.
  printf("Finished iterations. ID is %d\n", id);
}

void Iterations::interrupted() {
  printf("Iterations interrupted. ID is %d\n", id);
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}

void Iterations::blocked() {
}
