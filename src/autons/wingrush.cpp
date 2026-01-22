#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#endif
#ifndef __AUTON_H
#define __AUTON_H
#include "auton.hpp"
#endif

const void wingrush::left() {
    leftMG.move(127);
    rightMG.move(127);
}

const void wingrush::right() {
    leftMG.move(-127);
    rightMG.move(-127);
}