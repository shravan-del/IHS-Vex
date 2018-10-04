#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous()
{
    pros::Motor motor(1);
    int t = 0;
    int b = 5; // buffer, this is the range that the motor can be off by
    int m = 600; // max speed allowed: velocity from -+-100, +-200, or +-600 depending on the motor's gearset
    t = 100;
    motor.move_absolute(t, m); // Moves t units forward
    while (!((motor.get_position() < (t + b)) && (motor.get_position() > (t - b))))
    {
        // Continue running this loop as long as the motor is not within +-b units of its goal
        pros::delay(2);
    }
    t = 0;
    motor.move_absolute(t, m); // This does not cause a movement
    while (!((motor.get_position() < (t + b)) && (motor.get_position() > (t - b))))
    {
        pros::delay(2);
    }

    motor.tare_position();
    motor.move_absolute(t, m); // Moves t units forward
    while (!((motor.get_position() < (t + b)) && (motor.get_position() > (t - b))))
    {
        pros::delay(2);
    }
}