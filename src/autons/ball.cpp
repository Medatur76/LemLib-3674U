#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#include "motions.hpp"
#endif

const void ball::left() {
    chassis.setPose(0,0,270);
    matchload.extend();
    driveToWall(18.1, 3000, 100, true);
    chassis.turnToHeading(0, 500);
    chassis.waitUntilDone();
    intake.move(-127);
    matchload.extend();
    driveToWall(1,200,60,true);
    chassis.waitUntilDone();
    drive_distance(-50,3000,127);
    hood.extend();
    chassis.setPose(0,0,90);
    // works until here, make sure the wing hits and it doesnt cross the auton line
    chassis.moveToPose(13.18, -7, 90, 5000, {.forwards = true, .minSpeed = 65});
    chassis.turnToHeading(90, 200);
    chassis.moveToPoint(-33.979, -6.544, 400, {.forwards = false, .maxSpeed = 65});
};

const void ball::right() {
    
    chassis.setPose(0,0,270);
    matchload.extend();
    driveToWall(17.5, 1300, 100, true);
    chassis.turnToHeading(360, 500);
    chassis.waitUntilDone();
    intake.move(-127);
    matchload.extend();
    drive_distance(26,600);
    pros::delay(3000);
    chassis.turnToHeading(360, 300);
    pros::delay(350);
    drive_distance(-30,2000);
    chassis.waitUntilDone();
    hood.extend();
    pros::delay(200);
      chassis.setPose(0,0,90);
    chassis.moveToPose(12.18, -7, 90, 5000, {.forwards = true, .minSpeed = 65});
    chassis.turnToHeading(90, 200);
    chassis.moveToPoint(-35.979, -4.544, 400, {.forwards = false, .maxSpeed = 65});
    };
    