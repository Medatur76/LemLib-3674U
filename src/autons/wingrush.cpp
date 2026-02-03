#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#endif

const void wingrush::left() {
    PathReader reader = PathReader(wingrush_left_txt);
    chassis.setPose(55.66, -13.306, 270);
    lift.extend();
    chassis.follow(reader["Start"], 10, 2000);
    intake.move(127);
    pros::delay(1000);
    chassis.follow(reader["Score"], 10, 1000);
    outtake.move(127);
    pros::delay(1500);
    outtake.move(0);
    intake.move(0);
    descore.retract();
    chassis.follow(reader["Descore"], 10, 3000);
}

const void wingrush::right() {
    PathReader reader = PathReader(wingrush_right_txt);
    chassis.setPose(55.66, 13.306, 270);
    lift.extend();
    chassis.follow(reader["Start"], 10, 2000);
    intake.move(127);
    pros::delay(1000);
    chassis.follow(reader["Score"], 10, 1000);
    outtake.move(127);
    pros::delay(1500);
    outtake.move(0);
    intake.move(0);
    descore.retract();
    chassis.follow(reader["Descore"], 10, 3000);
}