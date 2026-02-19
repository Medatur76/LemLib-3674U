#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#endif

const void midgoal::left() {
    
}

const void midgoal::right() {
    chassis.setPose(49.271,15.365,0);
    matchload.retract();
    intake.move(127);
    chassis.moveToPoint(49.271, 46, 3000);
    //ping
    chassis.turnToHeading(90, 3000);
    chassis.moveToPoint(62, 46, 3000);
    chassis.waitUntilDone();
    pros::delay(100);
    chassis.moveToPoint(27.18, 47-2.6, 2000, {.forwards = false});
    chassis.waitUntilDone();
    matchload.extend();
    chassis.setPose(29.021, 47.479, 90);
    pros::delay(2000);
    chassis.moveToPoint(46.816, 46.661, 3000, {.forwards = true});
    chassis.moveToPoint(32.703, 31.933, 3000, {.forwards = true});
    chassis.waitUntilDone();
    chassis.moveToPoint(12.248, 12.706,  3000, {.maxSpeed = 45});
    chassis.waitUntilDone();
    intake.move(-127);


}