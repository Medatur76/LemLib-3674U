#include "main.hpp"
#include "auton.hpp"
#include "motions.hpp"

const void midgoal::left() {
    leftMG.move(-127);
    rightMG.move(127);
}

const void midgoal::right() {
    leftMG.move(127);
    rightMG.move(-127);
}