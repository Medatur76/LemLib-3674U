#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#include "pros/rtos.hpp"
#include "motions.hpp"
#endif

const void wingrush::left() {
    chassis.setPose(47.362, -13.922, 270);
    intake.move(127);
    descore.extend();
    chassis.moveToPoint(30.092  ,-17.177 ,5000, {.maxSpeed = 65,.minSpeed = 30, .earlyExitRange = 3});
    chassis.moveToPoint(20.749, -24.397-3, 5000, {.minSpeed = 65, .earlyExitRange = 3});
    chassis.waitUntilDone();
    matchload.retract();
    chassis.moveToPoint(50.522, -47, 5000, {.forwards = true, .maxSpeed = 95}, false);
    chassis.waitUntilDone();
    chassis.turnToHeading(90, 5000);
    chassis.moveToPoint(64.547, -47-2, 700);
    chassis.waitUntilDone();
    pros::delay(5);
    chassis.moveToPoint(27.129, -47-5, 1600, {.forwards = false});
    chassis.waitUntilDone();
    chassis.waitUntilDone();
    descore.retract();
    chassis.setPose(31.257, -47.278, 90);
    pros::delay(2000);
    chassis.moveToPoint(37.154, -40.595, 3000, {.forwards = true});
    chassis.turnToHeading(270,9000);
    chassis.moveToPoint(16.487, -39.219, 5000, {.forwards = true});

    // chassis.moveToPoint(0, 5, 2153);
    
}

const void wingrush::right() {
    chassis.setPose(0,0,270);
    matchload.extend();
    driveToWall(17.5, 1300, 100, true);
    chassis.turnToHeading(360, 500);
    chassis.waitUntilDone();
    intake.move(-127);
    matchload.extend();
    drive_distance(20,600);
    chassis.turnToHeading(360, 300);
    pros::delay(350);
    drive_distance(-50,2000);
    chassis.waitUntilDone();
    hood.extend();
    pros::delay(400);
      chassis.setPose(0,0,90);
    chassis.moveToPose(12.18, -7, 90, 5000, {.forwards = true, .minSpeed = 65});
    chassis.turnToHeading(90, 200);
    chassis.moveToPoint(-35.979, -6.544, 400, {.forwards = false, .maxSpeed = 65});

}