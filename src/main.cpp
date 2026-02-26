#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#include "liblvgl/llemu.hpp"
#include "pros/misc.h"
#endif

#define max(x, y) x > y ? x : y
#define min(x, y) x < y ? x : y
#define togglePiston(button, piston) if (master.get_digital(pros::E_CONTROLLER_DIGITAL_##button##)) {\
	if(##piston##CD) {\
		##piston##CD = false;\
		piston.toggle();\
	}\
} else {##piston##CD = true;}


int selected_auton = 0;
std::string autons[] = {"WINGRUSH LEFT","WINGRUSH RIGHT","MIDGOAL LEFT","MIDGOAL RIGHT", "4B LEFT", "4B RIGHT", "OFFSET FINDER", "SKILLS"};
using auton_function = const void(*)(void);
auton_function autonFuncs[] = {wingrush::left, wingrush::right, midgoal::left, midgoal::right, ball::left, ball::right, OffsetFinder::run, skills::run};

void autonomous();

pros::Controller master(pros::E_CONTROLLER_MASTER);

void ControllerAlert () {
    if (getAvgDrivetrainTemp() > 120) {
        master.rumble("...");
    }

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
	int timer = 0;
	
	
	while (true) {
		// pros::lcd::set_text(3, "Temp: " + std::to_string(getAvgDrivetrainTemp()).substr(0, 5) + "F");
		// Arcade control scheme
		int dir = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
		int turn = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
		leftMG.move(dir + turn);                      // Sets left motor voltage
		rightMG.move(dir - turn);                     // Sets right motor voltage

		intake.move((master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)-master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) * 127);

		togglePiston(DOWN, matchload)

		togglePiston(B, descore)

		togglePiston(L2, lift)
		
		master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) ? hood.extend() : hood.retract();
		
	// 	if (timer % 5 == 0) { 
    //    lemlib::Pose pose = chassis.getPose();
    //     pros::lcd::set_text(3, fmt::format("X: {:.2f}", pose.x));
    //     pros::lcd::set_text(4, fmt::format("Y: {:.2f}", pose.y));
    //     pros::lcd::set_text(5, fmt::format("Theta: {:.2f}", pose.theta));
    // }

    // timer++;
    // pros::delay(20);

		
		pros::delay(20);                               // Run for 20 ms then update
	}
}