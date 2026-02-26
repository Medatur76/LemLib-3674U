#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#endif

void move_relative(double x, double y, double timeout, bool forwards, float speed) {
    chassis.moveToPoint(
        chassis.getPose().x + x,
        chassis.getPose().y + y,
        timeout,
        {forwards, speed}
    );
}

void move_relative_to_pose(double x, double y, double theta, double timeout, bool forwards, float speed) {
    chassis.moveToPose(
        chassis.getPose().x + x,
        chassis.getPose().y + y,
        theta,
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

void driveToWall(double distance, double timeout, float speed = 127, bool from_front = true) {
    const double exit_range = 3.0;
    const double start = pros::millis();

    while (pros::millis() - start < timeout) {
        double front_distance = front.get() / 25.4;
        double back_distance  = back.get()  / 25.4;

        bool front_valid = front_distance > 10/25.4 && front_distance < 2000/25.4;
        bool back_valid  = back_distance  > 10/25.4 && back_distance  < 2000/25.4;

        if ((from_front && !front_valid) or (!from_front && !back_valid)) {
            pros::delay(20);  
            continue;
        }

        double dist = from_front ? front_distance : back_distance;
        if (std::abs(dist - distance) <= exit_range) break;

        drive_distance((from_front ? 1 : -1) * (dist - distance), 5000, speed);
        chassis.waitUntilDone();
        pros::delay(120);
    }
} 

void turnRelative(double theta, double timeout, float speed) {
    chassis.turnToHeading(chassis.getPose().theta + theta, timeout, {.maxSpeed = (int)speed});
}