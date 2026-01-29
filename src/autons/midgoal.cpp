#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#endif

const void midgoal::left() {
    leftMG.move(-127);
    rightMG.move(127);
}

const void midgoal::right() {
    chassis.setPose(47.362, 13.922, 270);
    intake.move(-127);
    chassis.moveToPoint(14.379,25.104 ,5000);

}