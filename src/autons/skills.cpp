#include "main.hpp"
#include <cmath>
#include "motions.hpp"
#include "pros/rtos.hpp"
#include <vector>

void clear_blocks(void) {
    matchload.extend();
    pros::delay(400);
    matchload.retract();
}

void move_forward_no_lemlib(double ms, float speed) {
    leftMG.move(speed);
    rightMG.move(speed);
    pros::delay(ms);
    leftMG.move(0);
    rightMG.move(0);
}

void skills_start(){
    descore.extend();
    intake.move(-127);

}
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
    pros::delay(2000);
    hood.retract();
}

void skills_three(){
    matchload.retract();
    // descore.extend();
    chassis.setPose(0, 0, 0);
    chassis.turnToHeading(-35, 500);
    chassis.waitUntilDone();
    drive_distance(37, 1200, 100);
    chassis.turnToHeading(285, 500);
    chassis.waitUntilDone();
    intake.move(-127);
    drive_distance(15, 1200, 127);
    chassis.turnToHeading(270, 500);
    clear_blocks();
    descore.extend();
    drive_distance(32, 1200, 127);
    chassis.turnToHeading(245,500);
    drive_distance(20,2000, 127);
    chassis.turnToHeading(270,2000);
    chassis.waitUntilDone();
    chassis.setPose(0,0,0);
    move_relative(-10,100, 5000, true);



}

void skills_four() {
     chassis.setPose(0,0,270);
    matchload.extend();
    driveToWall(18.1, 3000, 100, true);
    chassis.turnToHeading(0, 500);
    chassis.waitUntilDone();
    intake.move(-127);
    matchload.extend();
    drive_distance(-12,600,100);
    hood.extend();
    pros::delay(2000);
    hood.retract();
    driveToWall(1,400,60,true);
    chassis.waitUntilDone();
}

void skills_five(){
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
    pros::delay(2000);
    hood.retract();
}

void skills_six(){
    matchload.retract();
    // descore.extend();
    chassis.setPose(0, 0, 0);
    chassis.turnToHeading(-35, 500);
    chassis.waitUntilDone();
    drive_distance(37, 1200, 100);
    chassis.turnToHeading(285, 500);
    chassis.waitUntilDone();
    intake.move(-127);
    drive_distance(15, 1200, 127);
    chassis.turnToHeading(270, 500);
    clear_blocks();
    descore.extend();
    drive_distance(32, 1200, 127);
    chassis.turnToHeading(245,500);
    drive_distance(20,500, 127);
    chassis.turnToHeading(270,2000);
}

const void skills::run() {

    skills_one();
    skills_two();
    pros::delay(400);
    skills_three();
    skills_four();
    skills_five();
    pros::delay(400);
    skills_six();
}
