#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#endif

const void wingrush::left() {
    PathReader reader = PathReader(wingrush_left_txt);
    chassis.setPose(55.66, -13.306, 270);
    lift.extend();
    pros::lcd::set_text(4, "Start");
    chassis.follow(reader["Start"], 5, 2000);
    intake.move(127);
    pros::delay(1000);
    pros::lcd::set_text(4, "Score");
    chassis.follow(reader["Score"], 15, 1000);
    outtake.move(127);
    pros::delay(1500);
    outtake.move(0);
    intake.move(0);
    descore.retract();
    pros::lcd::set_text(4, "Descore");
    chassis.follow(reader["Descore"], 15, 3000);
}

const void wingrush::right() {
    chassis.setPose(49.91, 14.828, 0);
    lift.extend();
    chassis.moveToPose(44.626, 31.814, 335, 1000);
    chassis.moveToPose(52.276, 45.93, 85, 1000);
    chassis.moveToPose(60.38, 46.583, 90, 500);
    intake.move(127);
    pros::delay(1000);
    chassis.moveToPose(25.941, 47.311, 90, 1500);
    outtake.move(127);
    pros::delay(1500);
    outtake.move(0);
    intake.move(0);
    descore.retract();
    chassis.moveToPose(44.978, 43.611, 45, 500);
    chassis.moveToPose(25.384, 55.486, 270, 500);
    chassis.moveToPose(8.969, 55.486, 270, 1000);
}