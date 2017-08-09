/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any
 * functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs the user operator control code. This function will be started in its own
 * task with the
 * default priority and stack size whenever the robot is enabled via the Field
 * Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is
 * disabled or
 * communications is lost, the operator control task will be stopped by the
 * kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the
 * VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX
 * Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX
 * Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is
 * available and
 * the scheduler is operational. However, proper use of delay() or
 * taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating
 * LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop,
 * even if empty.
 */
// all variables
int isFineControl = false;
int fineControl = 1;
int leftDriveValue;
int rightDriveValue;
int count = 0;
int rightrpm = 0;
int leftrpm = 0;
int rightDriveTarget;
int leftDriveTarget;


//pids
void pid() {
  if (joystickGetAnalog(1, 2) > 10) { //if right joystick is being used, increase target
    rightDriveTarget = rightDriveTarget + joystickGetAnalog(1, 3);
  }
  else {
    rightDriveTarget = 0;
  }
  if (joystickGetAnalog(1, 3) > 10) { //if right joystick is being used, increase target
    leftDriveTarget = leftDriveTarget + joystickGetAnalog(1, 3);
  }
  else {
    leftDriveTarget = 0;
  }
}
// update all sensors and print to console
void updateSensor() {
  int leftencodervalue = encoderGet(leftencoder);
  int rightencodervalue = encoderGet(rightencoder);
  //printf("left value %d \n", leftencodervalue);
  //printf("right value %d \n", rightencodervalue);
  if (count == 5) {
    rightrpm = (rightencodervalue / 1)* 60;
    leftrpm = (leftencodervalue / 1) * 60;
    printf("right value %d \n", rightrpm);
    printf("left value %d \n", leftrpm);
    encoderReset(leftencoder);
    encoderReset(rightencoder);
    count = 0;
  }
  count = count + 1;
  delay(200);
}
// update robot to joystick control
void updateDrive() {
  // Chasis control
  motorSet(2, -(joystickGetAnalog(1, 3) * fineControl));
  motorSet(3, (joystickGetAnalog(1, 3) * fineControl));
  motorSet(4, -(joystickGetAnalog(1, 2) * fineControl));
  motorSet(5, (joystickGetAnalog(1, 2) * fineControl));
  // mobo lift control
  if (joystickGetDigital(1, 6, JOY_UP) == 1) {
    motorSet(6, 127);
    motorSet(7, 127);
  }
  if (joystickGetDigital(1, 6, JOY_DOWN) == 1) {
    motorSet(6, -127);
    motorSet(7, -127);
  }
  if (joystickGetDigital(1, 6, JOY_DOWN) == 0 &&
      joystickGetDigital(1, 6, JOY_UP) == 0) {
    motorSet(6, 0);
    motorSet(7, 0);
  }
  // lift control
  if (joystickGetDigital(1, 7, JOY_UP) == 1) {
    motorSet(8, 127);
    motorSet(9, 127);
  }
  if (joystickGetDigital(1, 7, JOY_DOWN) == 1) {
    motorSet(8, -127);
    motorSet(9, -127);
  }
  if (joystickGetDigital(1, 7, JOY_DOWN) == 0 &&
      joystickGetDigital(1, 6, JOY_UP) == 0) {
    motorSet(8, 0);
    motorSet(9, 0);
  }
  // fine control toggle
  if (joystickGetDigital(1, 7, JOY_DOWN) == 1 &&
      isFineControl == false) { // toggle it on
    isFineControl = true;
    fineControl = .5;
  }
  if (joystickGetDigital(1, 7, JOY_DOWN) == 0 &&
      isFineControl == true) { // toggle it off
    isFineControl = false;
    fineControl = 1;
  }
}

void operatorControl() {
  TaskHandle driveTaskHandle = taskRunLoop(updateDrive, 50);
  TaskHandle sensorTaskHandle = taskRunLoop(updateSensor, 50);
  while (1) {
    delay(20);
  }
  taskDelete(driveTaskHandle);
  taskDelete(sensorTaskHandle);
}
