#pragma config(Motor,  port2,           righttop,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rightbottom,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           lefttop,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           leftbottom,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift1,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           lift2,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           claw,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
  motor[leftbottom] = 127;
	motor[rightbottom] = 127;
	motor[righttop] = 127;
	motor[lefttop] = 127;
	wait1Msec(1000);
	//Move Forward 1 Secconds
	motor[leftbottom] = 127;
	motor[rightbottom] = -127;
	motor[righttop] = -127;
	motor[lefttop] = 127;
	wait1Msec(500);
	//Rotate Right .5 Secconds
	motor[leftbottom] = 127;
	motor[rightbottom] = 127;
	motor[righttop] = 127;
	motor[lefttop] = 127;
	wait1Msec(500);
	//Move Forward .5 Secconds
	motor[leftbottom] = -127;
	motor[rightbottom] = 127;
	motor[righttop] = 127;
	motor[lefttop] = -127;
	wait1Msec(500);
	//Rotate Left .5 Secconds
	motor[lift1] = 127;
	motor[lift2] = 127;
	motor[claw] = 127;
	wait1Msec(700);
	//Raise Lift and Open Claw .7 Secconds
	motor[leftbottom] = 127;
	motor[rightbottom] = -127;
	motor[righttop] = -127;
	motor[lefttop] = 127;
	wait1Msec(200);
	//Move Forward .2 Secconds
  AutonomousCodePlaceholderForTesting();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  // User control code here, inside the loop

  while (true)
  {
    {
    //Right side of the robot is controlled by the right joystick, Y-axis
    motor[righttop] = vexRT[Ch2];
    motor[rightbottom]  = vexRT[Ch2];
    //Left side of the robot is controlled by the left joystick, Y-axis
    motor[lefttop] = vexRT[Ch3];
    motor[leftbottom]  = vexRT[Ch3];
    motor[lift1] = vexRT[Ch2Xmtr2];
    motor[lift2] = vexRT[Ch2Xmtr2];
    motor[claw] = vexRT[Ch3Xmtr2];
    {
	bLCDBacklight = true;									// Turn on LCD Backlight
	string mainBattery, backupBattery;

{
		clearLCDLine(0);											// Clear line 1 (0) of the LCD
		clearLCDLine(1);											// Clear line 2 (1) of the LCD

		//Display the Primary Robot battery voltage
		displayLCDString(0, 0, "Primary: ");
		sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
		displayNextLCDString(mainBattery);

		//Display the Backup battery voltage
		displayLCDString(1, 0, "Backup: ");
		sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');	//Build the value to be displayed
		displayNextLCDString(backupBattery);

		//Short delay for the LCD refresh rate
		wait1Msec(100);
	}
}
    UserControlCodePlaceholderForTesting();
  }
  }
}
