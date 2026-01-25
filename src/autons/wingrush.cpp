#include "main.hpp"
#include "auton.hpp"
#include "motions.hpp"

const void wingrush::left() {
    leftMG.move(127);
    rightMG.move(127);
}

const void wingrush::right() {
    chassis.setPose(47.362, 13.922, 270);
    intake.move(127);
    chassis.moveToPoint(30.092  ,17.177 ,5000, {.maxSpeed = 65,.minSpeed = 30, .earlyExitRange = 3});
    chassis.moveToPoint(20.749, 24.397, 5000, {.earlyExitRange = 3});
    chassis.waitUntilDone();
    lift.extend();
    chassis.swingToHeading(52, DriveSide::RIGHT,5000, {.maxSpeed = 127,.minSpeed = 30, .earlyExitRange =12});
    chassis.moveToPose(59.649, 46.904, 90, 5000);
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.moveToPoint(31.054, 46.904, 5000, {.forwards = false});
    chassis.waitUntilDone();
    outtake.move(127);
    lift.retract();
}