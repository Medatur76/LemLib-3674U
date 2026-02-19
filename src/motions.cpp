#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#include "pros/distance.hpp"
#include "pros/rtos.hpp"
#endif

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

void drive_to_relative(double distance[2], double timeout, float speed = 127) {
    chassis.moveToPoint(chassis.getPose().x + distance[0], chassis.getPose().y + distance[1], timeout, {.maxSpeed=speed});
}

void drive_until_distance(dir direction, int32_t distance, int voltage) {
    pros::Distance sensor = direction == FORWARD ? forward : direction == BACKWARD ? backward : direction == LEFT ? left : right;

    double distances[2] = {0,0};

    distances[direction > 1] = (sensor.get_distance() - distance) / 24.5;

    drive_to_relative(distances, 4000, voltage);
};