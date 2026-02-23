
#include "lemlib/chassis/chassis.hpp"
#include "main.hpp"
#include <cmath>
#include <vector>

const void OffsetFinder::run() {
    int iterations = 10;
    std::vector<float> v_offsets, h_offsets;

    // Reset tracking wheels
    vertical_tracking_wheel.reset();
    horizontal_tracking_wheel.reset();

    for (int i = 0; i < iterations; i++) {
        // Reset pose and set brake mode
        chassis.setPose(0, 0, 0);
        chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
        float theta_start = chassis.getPose(false).theta;
        float target = (i % 2 == 0) ? 180 : 270;
        chassis.turnToHeading(target, 1000, {.direction = AngularDirection::CW_CLOCKWISE, .maxSpeed = 63}, false);
        chassis.waitUntilDone();
        pros::delay(250);
        float theta_end = chassis.getPose(false).theta;
        float t_delta = std::abs(lemlib::angleError(theta_end, theta_start, false));
        float v_delta = vertical_tracking_wheel.getDistanceTraveled();
        float h_delta = horizontal_tracking_wheel.getDistanceTraveled();
        v_offsets.push_back(v_delta / t_delta);
        h_offsets.push_back(h_delta / t_delta);
        // Reset for next iteration
        vertical_tracking_wheel.reset();
        horizontal_tracking_wheel.reset();
    }

    float v_offset = lemlib::avg(v_offsets);
    float h_offset = lemlib::avg(h_offsets);

    // Optionally print or display the offsets
    pros::lcd::set_text(5, "V: " + std::to_string(v_offset) + ", H: " + std::to_string(h_offset));
}
