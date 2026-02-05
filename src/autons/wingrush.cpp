#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#endif

const void wingrush::left() {
    PathReader reader = PathReader(wingrush_left_txt);
    chassis.setPose(55.66, -13.306, 270);
    lift.retract();
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
    // PathReader reader = PathReader(wingrush_right_txt);
    // chassis.setPose(55.66, 13.306, 270);
    // lift.retract();
    // chassis.follow(reader["Start"], 10, 2000);
    // intake.move(127);
    // pros::delay(1000);
    // chassis.follow(reader["Score"], 10, 1000);
    // outtake.move(127);
    // pros::delay(1500);
    // outtake.move(0);
    // intake.move(0);
    // descore.retract();
    // chassis.follow(reader["Descore"], 10, 3000);
    
    // Temporary copy of left auton for testing
    chassis.setPose(47.362, 13.922, 270);
    intake.move(127);
    chassis.moveToPoint(30.092  ,17.177 ,5000, {.maxSpeed = 65,.minSpeed = 30, .earlyExitRange = 3});
    chassis.moveToPoint(20.749, 24.397, 5000, {.minSpeed = 65, .earlyExitRange = 3});
    chassis.waitUntilDone();
    lift.retract();
    chassis.moveToPoint(50.035, 47.122, 5000, {.forwards = true, .maxSpeed = 95});
    chassis.moveToPoint(60.045+6, 46-2, 2100);
    chassis.waitUntilDone();
    pros::delay(100);
    chassis.moveToPoint(31.054, 46.9040-5, 5000, {.forwards = false});
    chassis.waitUntilDone();
    outtake.move(127);
    pros::delay(1200);
    outtake.move(0);
    intake.move(0);
    chassis.moveToPoint(36.099, 37.504, 5000);
    chassis.moveToPoint(9.013, 38.29, 5000);
    lift.extend();
}