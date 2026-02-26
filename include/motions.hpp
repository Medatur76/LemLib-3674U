#pragma once

void move_relative(double x, double y, double timeout, bool forwards, float speed = 127);
void drive_distance(double distance, double timeout, float speed = 127);
void driveToWall(double distance, double timeout, float speed = 127, bool from_front = true);
void move_relative_to_pose(double x, double y, double theta, double timeout, bool forwards, float speed);
void turnRelative(double theta, double timeout, float speed = 127);