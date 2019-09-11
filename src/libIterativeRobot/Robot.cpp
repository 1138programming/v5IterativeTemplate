#include "libIterativeRobot/Robot.h"
#include "libIterativeRobot/events/EventScheduler.h"
#include "libIterativeRobot/events/JoystickButton.h"
#include "libIterativeRobot/events/JoystickChannel.h"

#include "libIterativeRobot/commands/Arm/ArmControl.h"
#include "libIterativeRobot/commands/Arm/MoveArmTo.h"
#include "libIterativeRobot/commands/Autonomous/AutonGroup1.h"
#include "libIterativeRobot/commands/Autonomous/AutonGroup2.h"
#include "libIterativeRobot/commands/Base/DriveWithJoy.h"
#include "libIterativeRobot/commands/Claw/ClawControl.h"
#include "libIterativeRobot/commands/Claw/MoveClawFor.h"

Robot* Robot::instance = 0;

Base*  Robot::base = 0;
Arm*   Robot::arm = 0;
Claw*  Robot::claw = 0;

AutonChooser* Robot::autonChooser = 0;

pros::Controller* Robot::mainController = 0;
pros::Controller* Robot::partnerController = 0;

Robot::Robot() {
  printf("Overridden robot constructor!\n");

  // Initialize any subsystems
  base = new Base();
  arm  = new Arm();
  claw = new Claw();

  autonChooser = AutonChooser::getInstance();

  mainController = new pros::Controller(pros::E_CONTROLLER_MASTER);
  partnerController = new pros::Controller(pros::E_CONTROLLER_PARTNER);

  // Define buttons and channels
  libIterativeRobot::JoystickChannel* RightY = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  libIterativeRobot::JoystickChannel* LeftY = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_LEFT_Y);
  libIterativeRobot::JoystickButton* ArmUp = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R1);
  libIterativeRobot::JoystickButton* ArmDown = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R2);
  libIterativeRobot::JoystickButton* ClawOpen = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_L1);
  libIterativeRobot::JoystickButton* ClawClose = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_L2);
  libIterativeRobot::JoystickButton* ArmToStart = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_DOWN);
  libIterativeRobot::JoystickButton* ArmToHorizontal = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_RIGHT);
  libIterativeRobot::JoystickButton* ArmToTop = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_UP);
  libIterativeRobot::JoystickButton* ArmToBack = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_LEFT);

  // Add commands to be run to buttons
  RightY->setThreshold(50);
  LeftY->setThreshold(50);
  DriveWithJoy* driveCommand = new DriveWithJoy();
  RightY->whilePastThreshold(driveCommand);
  LeftY->whilePastThreshold(driveCommand);

  ArmUp->whileHeld(new ArmControl(true));
  ArmDown->whileHeld(new ArmControl(false));

  ClawControl* clawOpen = new ClawControl(true);
  ClawControl* clawClose = new ClawControl(false);
  ClawOpen->whenPressed(clawOpen);
  ClawOpen->whenPressed(clawClose, libIterativeRobot::Action::STOP);
  ClawClose->whenPressed(clawClose);
  ClawClose->whenPressed(clawOpen, libIterativeRobot::Action::STOP);
  ClawOpen->whenReleased(clawOpen, libIterativeRobot::Action::STOP);
  ClawClose->whenReleased(clawClose, libIterativeRobot::Action::STOP);

  ArmToStart->whenPressed(new MoveArmTo(0));
  ArmToHorizontal->whenPressed(new MoveArmTo(680));
  ArmToTop->whenPressed(new MoveArmTo(1520));
  ArmToBack->whenPressed(new MoveArmTo(2360));
}

void Robot::robotInit() {
  printf("Robot created.\n");

  autonChooser->addAutonCommand(new AutonGroup1(), "AutonGroup1");
  autonChooser->addAutonCommand(new AutonGroup2(), "AutonGroup2");
}

void Robot::autonInit() {
  printf("Default autonInit() function\n");
  autonChooser->uninit();
  autonChooser->getAutonCommand()->run();
}

void Robot::autonPeriodic() {
  Motor::periodicUpdate();
  PIDController::loopAll();
}

void Robot::teleopInit() {
  printf("Default teleopInit() function\n");
  autonChooser->init();

  // AutonGroup1* autonGroup1 = new AutonGroup1();
  // autonGroup1->run();
}

void Robot::teleopPeriodic() {
  Motor::periodicUpdate();
  PIDController::loopAll();
}

void Robot::disabledInit() {
  printf("Default disabledInit() function\n");
  autonChooser->uninit();
}

void Robot::disabledPeriodic() {
}

Robot* Robot::getInstance() {
    if (instance == NULL) {
        instance = new Robot();
    }
    return instance;
}
