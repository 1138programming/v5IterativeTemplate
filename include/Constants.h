/**
 * @file Constants.h
 * @brief Provides constants used throughout the entire code. Contains user-readable motor names
 */

 #include "abstractBaseClasses/Motor.h"

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define DEFAULT_TASK_TIME 10000
#define DELAY_TIME 10
#define MAX_MOTORS 20
#define MAX_FOLLOWERS 3

// Motor ports
const int leftBasePort = 1;
const int rightBasePort = 10;
const int armPort = 8;
const int clawPort = 3;

// Motor gearsets
const pros::motor_gearset_e_t baseMotorGearset = pros::E_MOTOR_GEARSET_18;
const pros::motor_gearset_e_t armMotorGearset = pros::E_MOTOR_GEARSET_18;
const pros::motor_gearset_e_t clawMotorGearset = pros::E_MOTOR_GEARSET_18;

// Global configurations
const pros::motor_encoder_units_e_t globalEncoderUnits = pros::E_MOTOR_ENCODER_COUNTS;
const pros::motor_brake_mode_e_t globalBrakeMode = pros::E_MOTOR_BRAKE_COAST;
const int globalSlewStep = 14;

//Motor and encoder constants
const int KMaxMotorSpeed = 127;
const int KMaxJoystickValue = 127;
const int encoderTicks = 360; // Encoder ticks in one revolution
const float rotationsPerInch = 31.400156410256; // TODO check if this is correct

// Encoder ports
const int exampleEncoderTopPort = 0;
const int exampleEncoderBottomPort = 1;

// Global things that we need

#endif
