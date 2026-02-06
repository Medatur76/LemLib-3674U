#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#endif

const void midgoal::left() {
    // PathReader reader = PathReader(midgoal_left_txt);
    // chassis.setPose(55.66, -13.306, 180);
    // lift.retract();
    // chassis.follow(reader["Start"], 10, 3000);
    // intake.move(127);
    // pros::delay(1000);
    // chassis.follow(reader["LongGoal"], 10, 1500);
    // outtake.move(127);
    // pros::delay(1500);
    // outtake.move(0);
    // intake.move(0);
    // chassis.follow(reader["MidGoal"], 10, 2000);
    // intake.move(-127);
    
}

const void midgoal::right() {
    // PathReader reader = PathReader(midgoal_right_txt);
    // chassis.setPose(55.66, 13.306, 270);
    // lift.retract();
    // chassis.follow(reader["Start"], 10, 3000);
    // intake.move(127);
    // pros::delay(1000);
    // chassis.follow(reader["LongGoal"], 10, 1500);
    // outtake.move(127);
    // pros::delay(1500);
    // outtake.move(0);
    // intake.move(0);
    // chassis.follow(reader["MidGoal"], 10, 2000);
    // intake.move(-127);
    chassis.setPose(49.271,15.365,0);
    lift.retract();
    intake.move(127);
    chassis.moveToPoint(49.271, 46, 3000);
    chassis.turnToHeading(90, 3000);
    chassis.moveToPoint(62, 46, 3000);
    chassis.waitUntilDone();
    pros::delay(100);
    chassis.moveToPoint(27.18, 47-2.6, 2000, {.forwards = false});
    chassis.waitUntilDone();
    outtake.move(127);
    lift.extend();
    chassis.setPose(29.021, 47.479, 90);
    pros::delay(2000);
    chassis.moveToPoint(46.816, 46.661, 3000, {.forwards = true});
    chassis.moveToPoint(32.703, 31.933, 3000, {.forwards = true});
    chassis.waitUntilDone();
    outtake.move(0);
    chassis.moveToPoint(12.248, 12.706,  3000, {.maxSpeed = 45});
    chassis.waitUntilDone();
    intake.move(-127);


}