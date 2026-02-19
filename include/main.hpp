/**
 * \file main.hpp
 *
 * Contains common definitions and header files used throughout your PROS
 * project.
 *
 * \copyright Copyright (c) 2017-2024, Purdue University ACM SIGBots.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#include "pros/distance.hpp"
#define LeftMotors {-8, -7, -14}
#define RightMotors {1, 2, 3}
#define IntakeMotors {12,-13}
#define OuttakeMotor 11
#define LEFT_DISTANCE_PORT -1
#define RIGHT_DISTANCE_PORT -1
#define FORWARD_DISTANCE_PORT -1
#define BACKWARD_DISTANCE_PORT -1

/**
 * If defined, some commonly used enums will have preprocessor macros which give
 * a shorter, more convenient naming pattern. If this isn't desired, simply
 * comment the following line out.
 *
 * For instance, E_CONTROLLER_MASTER has a shorter name: CONTROLLER_MASTER.
 * E_CONTROLLER_MASTER is pedantically correct within the PROS styleguide, but
 * not convenient for most student programmers.
 */
#define PROS_USE_SIMPLE_NAMES

/**
 * If defined, C++ literals will be available for use. All literals are in the
 * pros::literals namespace.
 *
 * For instance, you can do `4_mtr = 50` to set motor 4's target velocity to 50
 */
#define PROS_USE_LITERALS

#include "api.h"

/**
 * You should add more #includes here
 */
//#include "okapi/api.hpp"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "liblvgl/llemu.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"

/**
 * If you find doing pros::Motor() to be tedious and you'd prefer just to do
 * Motor, you can use the namespace with the following commented out line.
 *
 * IMPORTANT: Only the okapi or pros namespace may be used, not both
 * concurrently! The okapi namespace will export all symbols inside the pros
 * namespace.
 */
// using namespace pros;
// using namespace pros::literals;
// using namespace okapi;

/**
 * Prototypes for the competition control tasks are redefined here to ensure
 * that they can be called from user code (i.e. calling autonomous from a
 * button press in opcontrol() for testing purposes).
 */
#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */
#include <algorithm>
#include <string>
#include <cmath>
#endif

ASSET(midgoal_right_txt);
ASSET(midgoal_left_txt);
ASSET(wingrush_right_txt);
ASSET(wingrush_left_txt);

// Drivetrain motor groups
inline pros::MotorGroup leftMG(LeftMotors, pros::MotorGearset::blue), rightMG(RightMotors, pros::MotorGearset::blue);

// Mechanism motors
inline pros::MotorGroup intake(IntakeMotors);

// Pneumatics
// This caused the error with the pneumatics not working lasttime as far as im concerned so this might have to be moved back to a cpp file 
inline pros::adi::Pneumatics matchload('B', false);
inline bool matchloadCD = false;
inline pros::adi::Pneumatics lift('A', true);
inline bool liftCD = false;
inline pros::adi::Pneumatics hood('D', false);
inline bool hoodCD = false;

/**
 * Custom headers that rely on declared values above
 */

#include "auton.hpp"
#include "temp.hpp"

#endif  // _PROS_MAIN_H_
