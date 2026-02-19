#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#include "pros/rtos.hpp"
#endif

const void wingrush::left() {
    chassis.setPose(47.362, -13.922, 270);
    intake.move(127);
    descore.extend();
    chassis.moveToPoint(30.092  ,-17.177 ,5000, {.maxSpeed = 65,.minSpeed = 30, .earlyExitRange = 3});
    chassis.moveToPoint(20.749, -24.397-3, 5000, {.minSpeed = 65, .earlyExitRange = 3});
    chassis.waitUntilDone();
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
    
}

const void wingrush::right() {
    chassis.setPose(47.362, 13.922, 270);
    intake.move(127);
    descore.extend();
    chassis.moveToPoint(30.092  ,17.177 ,5000, {.maxSpeed = 65,.minSpeed = 30, .earlyExitRange = 3});
    chassis.moveToPoint(20.749, 24.397-3, 5000, {.minSpeed = 65, .earlyExitRange = 3});
    chassis.waitUntilDone();
    matchload.retract();
    chassis.moveToPoint(50.035, 45.8-4, 5000, {.forwards = true, .maxSpeed = 95}, false);
    chassis.waitUntilDone();
    chassis.turnToHeading(90, 5000);
    chassis.moveToPoint(61.748+4.7, 45.8-2.5, 2000);
    chassis.waitUntilDone();
    pros::delay(120);
    chassis.moveToPoint(29.021, 46.661-5.5, 1600, {.forwards = false});
    chassis.waitUntilDone();
    chassis.waitUntilDone();
    descore.retract();
    chassis.setPose(29.021, 47.479, 90);
    pros::delay(2000);
    chassis.moveToPoint(36.18, 38.843+1, 3000, {.forwards = true});
    chassis.turnToHeading(95,9000);
    chassis.moveToPoint(16.907, 41.138, 5000, {.forwards = false});
}