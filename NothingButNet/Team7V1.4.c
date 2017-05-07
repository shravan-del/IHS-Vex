#pragma config(Motor,  port2,           LU,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           LD,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           RD,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           RU,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           ShooterL,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           ShooterR,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           Lift,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  // .....................................................................................
  // Insert user code here.
  // .....................................................................................

	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	int shooterspeed = 0;
	// User control code here, inside the loop

	while (true)
	{
		//Motor Control
	  int shooterspeed;
	  motor[LU] = vexRT[Ch3];
	  motor[LD] = vexRT[Ch3];
	  motor[RD] = vexRT[Ch2];
	  motor[RU] = vexRT[Ch2];
	  motor[ShooterR] = shooterspeed;
	  motor[ShooterL] = shooterspeed;
	  //Shooter Speed Check
	  if(vexRT[Btn7U] == 1)
	  {
	  	shooterspeed = shooterspeed + 1;
	  }
	  if(vexRT[Btn7D] == 1)
	  {
	  	shooterspeed = shooterspeed - 1;
	  }
	  //Lift Check
	  if(vexRT[Btn8D] == 1)
	  {
	  	motor[Lift] = 127;
	}
	  if(vexRT[Btn8U] == 1)
	  {
	  	motor[Lift] = 0;
}
	}
}
