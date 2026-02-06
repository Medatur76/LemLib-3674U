#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#include "pros/rtos.hpp"
#endif

const void ball::left() {

};

const void ball::right() {
    chassis.setPose(49.271,15.365,0);
    lift.retract();
    intake.move(127);
    chassis.moveToPoint(49.271, 46, 3000);
    chassis.turnToHeading(90, 3000);
    chassis.moveToPoint(62, 46, 3000);
    chassis.waitUntilDone();
    chassis.setPose(29.021, 47.479, 90);
    pros::delay(2000);
    chassis.moveToPoint(36.18, 38.843+1, 3000, {.forwards = true});
    chassis.moveToPose(1, 39.706-3, 90, 9123, {.forwards = false});
};