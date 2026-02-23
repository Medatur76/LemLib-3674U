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
    chassis.setPose(47.021,13.524,270);
    intake.move(-127);
    chassis.moveToPoint(14.271, 25.388-2, 1200, {.forwards = true, .maxSpeed = 65,  .earlyExitRange = 3});
    chassis.waitUntilDone();
    intake.move(0);
    matchload.extend();
    chassis.moveToPoint(38.316, 47.661, 2000, {.forwards = true}, false);
    chassis.waitUntilDone();
    intake.move(-127);
    chassis.turnToHeading(90, 300);
    chassis.waitUntilDone();
    chassis.moveToPoint(60, 47.661, 1900, {.forwards = true, .maxSpeed = 55}, false);
    chassis.waitUntilDone();
    pros::delay(900);
    chassis.turnToHeading(90, 1200);
    move_relative(-38,-1, 1000, false, 100);
    chassis.waitUntilDone();
    descore.extend();
    matchload.retract();
    hood.extend();
    intake.move(-127);
    pros::delay(1200);
    move_relative(8,-12,600, false, 100);
    chassis.setPose(0,0,90);
    chassis.moveToPose(13.18, -7, 90, 5000, {.forwards = true, .minSpeed = 65});
    chassis.turnToHeading(90, 200);
    chassis.moveToPoint(-33.979, -6.544, 5000, {.forwards = false, .maxSpeed = 65});


}