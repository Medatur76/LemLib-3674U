#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#endif

int selected_auton = 1;
std::string autons[] = {"WINGRUSH LEFT","WINGRUSH RIGHT","MIDGOAL LEFT","MIDGOAL RIGHT"};
using auton_function = const void(*)(void);
auton_function autonFuncs[] = {wingrush::left, wingrush::right, midgoal::left, midgoal::right};

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a < b ? a : b;
}

void on_left_button() {
	pros::lcd::clear_line(2);
	pros::lcd::set_text(2, autons[selected_auton = max(--selected_auton, 0)]);
}

void on_right_button() {
	pros::lcd::clear_line(2);
	pros::lcd::set_text(2, autons[selected_auton = min(++selected_auton, 3)]);
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello 3674U!");

	pros::lcd::register_btn0_cb(on_left_button);
	pros::lcd::register_btn2_cb(on_right_button);

	// Calibrate the chassis IMU and sensors
	chassis.calibrate();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}


/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
	pros::lcd::set_text(2, autons[selected_auton]);
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	autonFuncs[selected_auton]();
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	
	while (true) {
		pros::lcd::set_text(3, "Temp: " + std::to_string(getAvgDrivetrainTemp()).substr(0, 5) + "C");
		// Arcade control scheme
		int dir = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
		int turn = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
		leftMG.move(dir + turn);                      // Sets left motor voltage
		rightMG.move(dir - turn);                     // Sets right motor voltage

		intake.move((master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)-master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) * 127);
    	outtake.move((master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)-master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) * 127);

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
			if (liftCD) {
				liftCD = false;
				lift.toggle();
			}
		} else liftCD = true;
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
			if (descoreCD) {
				descoreCD = false;
				descore.toggle();
			}
		} else descoreCD = true;
		

		pros::delay(20);                               // Run for 20 ms then update
	}
}