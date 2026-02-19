#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#include "liblvgl/llemu.hpp"
#include "pros/misc.h"
#endif

int selected_auton = 1;
std::string autons[] = {"WINGRUSH LEFT","WINGRUSH RIGHT","MIDGOAL LEFT","MIDGOAL RIGHT", "4B LEFT", "4B RIGHT"};
using auton_function = const void(*)(void);
auton_function autonFuncs[] = {wingrush::left, wingrush::right, midgoal::left, midgoal::right, ball::left, ball::right};

void autonomous();

pros::Controller master(pros::E_CONTROLLER_MASTER);

void ControllerAlert () {
    if (getAvgDrivetrainTemp() > 120) {
        master.rumble("...");
    }

}

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

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello 3674U!");

	pros::lcd::register_btn0_cb(on_left_button);
	pros::lcd::register_btn2_cb(on_right_button);
	pros::lcd::set_text(2, autons[selected_auton]);
	chassis.getPose();
	pros::lcd::set_text(3, "X: %.2f, Y: %.2f, T: %.2f,");

	chassis.calibrate();
}

void disabled() {}


void competition_initialize() {
	pros::lcd::set_text(2, autons[selected_auton]);
}

void autonomous() {
	autonFuncs[selected_auton]();
}

void opcontrol() {
	
	
	while (true) {
		pros::lcd::set_text(3, "Temp: " + std::to_string(getAvgDrivetrainTemp()).substr(0, 5) + "F");
		// Arcade control scheme
		int dir = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
		int turn = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
		leftMG.move(dir + turn);                      // Sets left motor voltage
		rightMG.move(dir - turn);                     // Sets right motor voltage

		intake.move((master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)-master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) * 127);

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
			if (matchloadCD) {
				matchloadCD = false;
				matchload.toggle();
			}
		} else matchloadCD = true;
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
			if (descoreCD) {
				descoreCD = false;
				descore.toggle();
			}
		} else descoreCD = true;

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
			intake.move(-127);
			hood.extend();
		} else {
			hood.retract();
		}

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
			if (liftCD) {
				liftCD = false;
				lift.toggle();
			}
		} else liftCD = true;
		
		// ControllerAlert();
		
		pros::delay(20);                               // Run for 20 ms then update
	}
}