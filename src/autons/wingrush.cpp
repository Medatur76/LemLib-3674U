#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#endif
#ifndef __AUTON_H
#define __AUTON_H
#include "auton.hpp"
#endif

void move_relative(double x, double y, double timeout, bool forwards, float speed=127){
    chassis.moveToPoint(chassis.getPose().x + x,
                              chassis.getPose().y + y,
                              timeout, {forwards, speed});
}
void drive_distance(double distance, double timeout, float speed=127){
    chassis.moveToPoint(chassis.getPose().x + distance * cos((-chassis.getPose().theta+90) * M_PI / 180.0),
                              chassis.getPose().y + distance * sin((-chassis.getPose().theta+90) * M_PI / 180.0),
                              timeout, {(distance>=0), speed});
} 

const void wingrush::left() {
    leftMG.move(127);
    rightMG.move(127);
}

const void wingrush::right() {
    leftMG.move(-127);
    rightMG.move(-127);
}