#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#include "pros/rtos.hpp"
#endif

const void wingrush::left() {
    // PathReader reader = PathReader(wingrush_left_txt);
    // chassis.setPose(55.66, -13.306, 270);
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
    chassis.setPose(47.362, -13.922, 90);
    intake.move(127);
    descore.extend();
    chassis.moveToPoint(30.092, -17.177, 5000, {.maxSpeed = 65, .minSpeed = 30, .earlyExitRange = 3});
    chassis.moveToPoint(20.749, -(24.397-3), 5000, {.minSpeed = 65, .earlyExitRange = 3});
    chassis.waitUntilDone();
    lift.retract();
    chassis.moveToPoint(50.035, -(45.8-4), 5000, {.forwards = true, .maxSpeed = 95}, false);
    chassis.waitUntilDone();
    chassis.turnToHeading(270, 5000);
    chassis.moveToPoint(61.748+4.7, -(45.8-2.5), 4000);
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.moveToPoint(29.021, -(46.661-5.5), 2000, {.forwards = false});
    chassis.waitUntilDone();
    outtake.move(127);
    chassis.waitUntilDone();
    descore.retract();
    chassis.setPose(29.021, -47.479, 270);
    pros::delay(2000);
    chassis.moveToPoint(36.18, -(38.843+1), 3000, {.forwards = true});
    chassis.moveToPose(1, -(39.706-3), 270, 9123, {.forwards = false});
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
    descore.extend();
    chassis.moveToPoint(30.092  ,17.177 ,5000, {.maxSpeed = 65,.minSpeed = 30, .earlyExitRange = 3});
    chassis.moveToPoint(20.749, 24.397-3, 5000, {.minSpeed = 65, .earlyExitRange = 3});
    chassis.waitUntilDone();
    lift.retract();
    chassis.moveToPoint(50.035, 45.8-4, 5000, {.forwards = true, .maxSpeed = 95}, false);
    chassis.waitUntilDone();
    chassis.turnToHeading(90, 5000);
    chassis.moveToPoint(61.748+4.7, 45.8-2.5, 2000);
    chassis.waitUntilDone();
    pros::delay(120);
    chassis.moveToPoint(29.021, 46.661-5.5, 1600, {.forwards = false});
    chassis.waitUntilDone();
    outtake.move(127);
    chassis.waitUntilDone();
    descore.retract();
    chassis.setPose(29.021, 47.479, 90);
    pros::delay(2000);
    chassis.moveToPoint(36.18, 38.843+1, 3000, {.forwards = true});
    chassis.turnToHeading(95,9000);
    chassis.moveToPoint(5.907, 41.138, 5000, {.forwards = false});
}