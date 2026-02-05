#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#endif

const void midgoal::left() {
    PathReader reader = PathReader(midgoal_left_txt);
    chassis.setPose(55.66, -13.306, 180);
    lift.retract();
    chassis.follow(reader["Start"], 10, 3000);
    intake.move(127);
    pros::delay(1000);
    chassis.follow(reader["LongGoal"], 10, 1500);
    outtake.move(127);
    pros::delay(1500);
    outtake.move(0);
    intake.move(0);
    chassis.follow(reader["MidGoal"], 10, 2000);
    intake.move(-127);
}

const void midgoal::right() {
    PathReader reader = PathReader(midgoal_right_txt);
    chassis.setPose(55.66, 13.306, 270);
    lift.retract();
    chassis.follow(reader["Start"], 10, 3000);
    intake.move(127);
    pros::delay(1000);
    chassis.follow(reader["LongGoal"], 10, 1500);
    outtake.move(127);
    pros::delay(1500);
    outtake.move(0);
    intake.move(0);
    chassis.follow(reader["MidGoal"], 10, 2000);
    intake.move(-127);
}