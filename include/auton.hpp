#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#endif

// drivetrain settings
inline lemlib::Drivetrain drivetrain(&leftMG, // left motor group
                              &rightMG, // right motor group
                              16, // 14 inch track width
                              lemlib::Omniwheel::NEW_325, // using new 4" omnis
                              450, // drivetrain rpm is 360
                              2 // horizontal drift is 2 (for now)
);

// create an imu on port 10
inline pros::Imu imu(10);

// horizontal tracking wheel encoder
inline pros::Rotation horizontal_encoder(20);
// vertical tracking wheel encoder
inline pros::adi::Encoder vertical_encoder('C', 'D', true);
// horizontal tracking wheel
inline lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, lemlib::Omniwheel::NEW_275, -5.75);
// vertical tracking wheel
inline lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_275, -2.5);

inline lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            &horizontal_tracking_wheel, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

// lateral PID controller
inline lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

// angular PID controller
inline lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// create the chassis
inline lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors // odometry sensors
);

class wingrush {
    public:
        const static void left();
        const static void right();
};

class midgoal {
    public:
        const static void left();
        const static void right();
};