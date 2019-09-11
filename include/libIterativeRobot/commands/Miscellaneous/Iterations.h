#ifndef _COMMANDS_ITERATIONS_H_
#define _COMMANDS_ITERATIONS_H_

#include "libIterativeRobot/commands/Command.h"

class Iterations: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    void blocked();
    Iterations(int duration, int id);
  private:
    int currIteration;
    int iterations;
    int id;
};

#endif // _COMMANDS_ITERATIONS_H_
