// ========== DRIVETRAIN SETUP ==========

// drivetrain settings
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
inline pros::Rotation horizontal_encoder(-15);

// vertical tracking wheel encoder (rotation sensor on port 5)
inline pros::Rotation vertical_encoder(5);

// horizontal tracking wheel (2" omni, offset to the left)
inline lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, 
                                                       lemlib::Omniwheel::NEW_2, 
                                                       -0.32);

// vertical tracking wheel (2.75" omni, offset backward)
inline lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, 
                                                     lemlib::Omniwheel::NEW_275, 
                                                     0.0);

// sensors used for odometry
inline lemlib::OdomSensors sensors(&vertical_tracking_wheel,      // vertical tracking wheel 1
                                   nullptr,                       // vertical tracking wheel 2 (not used)
                                   &horizontal_tracking_wheel,    // horizontal tracking wheel 1
                                   nullptr,                       // horizontal tracking wheel 2 (not used)
                                   &imu                           // inertial sensor
);

// ========== PID CONTROLLER SETTINGS ==========

// lateral PID controller
inline lemlib::ControllerSettings lateral_controller(7,   // proportional gain (kP)
                                                     0,    // integral gain (kI)
                                                     4,    // derivative gain (kD)
                                                     3,    // anti windup
                                                     1,    // small error range (inches)
                                                     100,  // small error range timeout (ms)
                                                     3,    // large error range (inches)
                                                     500,  // large error range timeout (ms)
                                                     20    // maximum acceleration (slew)
);

// angular PID controller
inline lemlib::ControllerSettings angular_controller(6,    // proportional gain (kP) 6
                                                     0,    // integral gain (kI)
                                                     34,   // derivative gain (kD) 34
                                                     3,    // anti windup
                                                     1,    // small error range (degrees)
                                                     100,  // small error range timeout (ms)
                                                     3,    // large error range (degrees)
                                                     500,  // large error range timeout (ms)
                                                     0     // maximum acceleration (slew)
);

// ========== CHASSIS SETUP ==========

// create the chassis
inline lemlib::Chassis chassis(drivetrain,       // drivetrain settings
                               lateral_controller, // lateral PID settings
                               angular_controller, // angular PID settings
                               sensors             // odometry sensors
);

class PathReader {
    protected:
        std::vector<std::string> paths;
        std::vector<asset> assets;
    public:
        PathReader(const asset&);

        asset& operator[](const char*);

        asset& get(const char *);

        bool has(const char *);
};

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