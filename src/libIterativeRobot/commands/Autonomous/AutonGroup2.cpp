#include "libIterativeRobot/commands/Autonomous/AutonGroup2.h"
#include "libIterativeRobot/commands/Miscellaneous/Delay.h"

AutonGroup2::AutonGroup2() {
  addSequentialCommand(new Delay(5000, 0));
}
