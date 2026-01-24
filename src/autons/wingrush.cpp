#include "main.hpp"
#include "auton.hpp"
#include "motions.hpp"

const void wingrush::left() {
    leftMG.move(127);
    rightMG.move(127);
}

const void wingrush::right() {
    leftMG.move(-127);
    rightMG.move(-127);
}