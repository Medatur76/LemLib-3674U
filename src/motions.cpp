#include "motions.hpp"
#include "lemlib/api.hpp"
#include "auton.hpp"
#include <cmath>

void move_relative(double x, double y, double timeout, bool forwards, float speed) {
    chassis.moveToPoint(
        chassis.getPose().x + x,
        chassis.getPose().y + y,
        timeout,
        {forwards, speed}
    );
}

void drive_distance(double distance, double timeout, float speed) {
    chassis.moveToPoint(
        chassis.getPose().x + distance * cos((-chassis.getPose().theta + 90) * M_PI / 180.0),
        chassis.getPose().y + distance * sin((-chassis.getPose().theta + 90) * M_PI / 180.0),
        timeout,
        {distance >= 0, speed}
    );
}
