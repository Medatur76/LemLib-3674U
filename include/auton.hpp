// ========== DRIVETRAIN SETUP ==========

// drivetrain settings
#include "main.hpp"
inline lemlib::Drivetrain drivetrain(&leftMG,                          // left motor group
                                     &rightMG,                         // right motor group
                                     12,                               // 12 inch track width
                                     lemlib::Omniwheel::NEW_325,       // using new 3.25" omnis
                                     450,                              // drivetrain rpm is 450
                                     2                                 // horizontal drift is 2
);

// ========== SENSORS SETUP ==========


inline pros::Imu imu(9);

// horizontal tracking wheel encoder (rotation sensor on port 15, reversed)
inline pros::Rotation horizontal_encoder(19);

// vertical tracking wheel encoder (rotation sensor on port 5)
inline pros::Rotation vertical_encoder(16);

// horizontal tracking wheel (2" omni, offset to the left)
inline lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, 
                                                       lemlib::Omniwheel::NEW_2, 
                                                       0.011);

// vertical tracking wheel (2.75" omni, offset backward)
inline lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, 
                                                     lemlib::Omniwheel::NEW_2, 
                                                     0);

// sensors used for odometry
inline lemlib::OdomSensors sensors(&vertical_tracking_wheel,      // vertical tracking wheel 1
                                   nullptr,                       // vertical tracking wheel 2 (not used)
                                   &horizontal_tracking_wheel,    // horizontal tracking wheel 1
                                   nullptr,                       // horizontal tracking wheel 2 (not used)
                                   &imu                           // inertial sensor
);

// ========== PID CONTROLLER SETTINGS ==========

// lateral PID controller
inline lemlib::ControllerSettings lateral_controller(6,   // proportional gain (kP)
                                                     0,    // integral gain (kI)
                                                     1,    // derivative gain (kD)
                                                     3,    // anti windup
                                                     1,    // small error range (inches)
                                                     100,  // small error range timeout (ms)
                                                     3,    // large error range (inches)
                                                     200,  // large error range timeout (ms)
                                                     20    // maximum acceleration (slew)
);

// angular PID controller
inline lemlib::ControllerSettings angular_controller(2.1,    // proportional gain (kP) 6
                                                     0,    // integral gain (kI)
                                                     5,   // derivative gain (kD) 34
                                                     0,    // anti windup
                                                     1,    // small error range (degrees)
                                                     100,  // small error range timeout (ms)
                                                     3,    // large error range (degrees)
                                                     400,  // large error range timeout (ms)
                                                     0     // maximum acceleration (slew)
);

// ========== CHASSIS SETUP ==========

// create the chassis
inline lemlib::Chassis chassis(drivetrain,       // drivetrain settings
                               lateral_controller, // lateral PID settings
                               angular_controller, // angular PID settings
                               sensors             // odometry sensors
);

class wingrush {
    public:
        const static void left();
        const static void right();
};

class ball {
    public:
        const static void left();
        const static void right();
};

class midgoal {
    public:
        const static void left();
        const static void right();
};

class OffsetFinder {
    public:
        const static void run();
};

class skills {
    public:
        const static void run();
};