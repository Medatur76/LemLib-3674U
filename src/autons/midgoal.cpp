#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#endif

PathReader reader(midgoal_right_test_txt);

const void midgoal::left() {
    leftMG.move(-127);
    rightMG.move(127);
}

const void midgoal::right() {
    chassis.setPose(55.66, 13.306, 270);
    lift.extend();
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