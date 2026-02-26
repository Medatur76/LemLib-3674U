#include "main.hpp"
#include <cmath>
#include "motions.hpp"
#include "pros/rtos.hpp"
#include <vector>

void skills_one(){

    chassis.setPose(0,0,270);
    matchload.extend();
    driveToWall(18.1, 3000, 100, true);
    chassis.turnToHeading(0, 500);
    chassis.waitUntilDone();
    intake.move(-127);
    matchload.extend();
    driveToWall(1,400,60,true);
    chassis.waitUntilDone();
    
}
void skills_two(){
    drive_distance(-12,600,100);
    chassis.turnToHeading(45, 500);
    chassis.waitUntilDone();
    intake.move(0);
    drive_distance(-15, 600, 100);
    chassis.turnToHeading(0, 500);
    chassis.waitUntilDone();
    drive_distance(-80, 3000, 100);
    chassis.turnToHeading(90, 500);
    chassis.waitUntilDone();
    driveToWall(18, 3000, 100, false);
    chassis.turnToHeading(180, 500);
    chassis.waitUntilDone();
    intake.move(-127);
    chassis.waitUntilDone();
    drive_distance(-20,700,100);
    chassis.waitUntilDone();
    chassis.turnToHeading(180, 500);
    hood.extend();
    pros::delay(2000);
    hood.retract();
    chassis.turnToHeading(180, 500);
    driveToWall(1,900,60,true);

    chassis.waitUntilDone();
    pros::delay(600);
    drive_distance(-30, 1200, 100);
    chassis.waitUntilDone();
    hood.extend();
}

void skills_three(){
    matchload.retract();
    chassis.resetLocalPosition();
    move_relative(-12,-24, 500,true);
}

const void skills::run() {

    // skills_one();
    // skills_two();
    pros::delay(400);
    skills_three();
}
