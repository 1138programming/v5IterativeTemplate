#include "libIterativeRobot/commands/Autonomous/AutonGroup1.h"
#include "libIterativeRobot/commands/Autonomous/AutonGroup2.h"
#include "libIterativeRobot/commands/Miscellaneous/Delay.h"
#include "libIterativeRobot/commands/Miscellaneous/Iterations.h"
#include "libIterativeRobot/commands/LambdaGroup.h"

AutonGroup1::AutonGroup1() {
  libIterativeRobot::LambdaGroup* lambda2 = new libIterativeRobot::LambdaGroup();
  lambda2->addSequentialCommand(new Delay(100, 3));
  lambda2->addSequentialCommand(new Delay(100, 4));

  libIterativeRobot::LambdaGroup* lambda = new libIterativeRobot::LambdaGroup();
  lambda->addSequentialCommand(new Delay(100, 1));
  lambda->addSequentialCommand(new Delay(300, 2));
  lambda->addParallelCommand(lambda2);

  addSequentialCommand(new Delay(500, 0));
  addParallelCommand(lambda);
}
