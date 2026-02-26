#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#include "motions.hpp"
#endif

const void ball::left() {
    chassis.setPose(0,0,270);
    matchload.extend();
    driveToWall(18.1, 3000, 100, true);
    chassis.turnToHeading(180, 500);
    chassis.waitUntilDone();
    intake.move(-127);
    matchload.extend();
    driveToWall(1,400,60,true);
    chassis.waitUntilDone();
    drive_distance(-50,3000,127);
    hood.extend();
    chassis.setPose(0,0,90);
    chassis.moveToPose(13.18, -7, 90, 5000, {.forwards = true, .minSpeed = 65});
    chassis.turnToHeading(90, 200);
    chassis.moveToPoint(-33.979, -6.544, 400, {.forwards = false, .maxSpeed = 65});
};

const void ball::right() {
    
    chassis.setPose(0,0,270);
    matchload.extend();
    driveToWall(18.1, 3000, 100, true);
    chassis.turnToHeading(0, 500);
    chassis.waitUntilDone();
    intake.move(-127);
    matchload.extend();
    driveToWall(1,400,60,true);
    chassis.waitUntilDone();
    drive_distance(-50,3000,127);
    hood.extend();
    chassis.setPose(0,0,90);
    // works until here, make sure the wing hits and it doesnt cross the auton line
    chassis.moveToPose(13.18, -7, 90, 5000, {.forwards = true, .minSpeed = 65});
    chassis.turnToHeading(90, 200);
    chassis.moveToPoint(-33.979, -6.544, 400, {.forwards = false, .maxSpeed = 65});
    };