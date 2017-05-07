#pragma config(Motor,  port2,           righttop,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rightbottom,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           lefttop,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           leftbottom,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift1,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           lift2,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           claw,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           hang,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

//LCD Display code.
const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;
//Declare count variable to keep track of our choice
int count = 0;
//Wait for Press--------------------------------------------------
void waitForPress()
{
	while(nLCDButtons == 0){}
	wait1Msec(5);
}
//----------------------------------------------------------------

//Wait for Release------------------------------------------------
void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(5);
}

//

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////
void TurnRight()
{
	motor[leftbottom] = -127;
	motor[rightbottom] = 127;
	motor[righttop] = 127;
	motor[lefttop] = -127;
}
void TurnLeft()
{
	motor[leftbottom] = 127;
	motor[rightbottom] = -127;
	motor[righttop] = -127;
	motor[lefttop] = 127;
}
void MoveForward()
{
	motor[leftbottom] = 127;
	motor[rightbottom] = 127;
	motor[righttop] = 127;
	motor[lefttop] = 127;
}
void MoveBackward()
{
	motor[leftbottom] = -127;
	motor[rightbottom] = -127;
	motor[righttop] = -127;
	motor[lefttop] = -127;
}
void StopMoving()
{
	motor[leftbottom] = 0;
	motor[rightbottom] = 0;
	motor[righttop] = 0;
	motor[lefttop] = 0;
}
void pre_auton()
{

	//------------- Beginning of User Interface Code ---------------
	//Clear LCD
	clearLCDLine(0);
	clearLCDLine(1);
	bLCDBacklight = true;
	//Loop while center button is not pressed
	while(nLCDButtons != centerButton)
	{
		//Switch case that allows the user to choose from 4 different options
		switch(count){
		case 0:
			//Display first choice
			displayLCDCenteredString(0, "Red Left");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 3;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 1:
			//Display second choice
			displayLCDCenteredString(0, "Red Right");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 2:
			//Display third choice
			displayLCDCenteredString(0, "Blue Left");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 3:
			//Display fourth choice
			displayLCDCenteredString(0, "Blue Right");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count = 0;
			}
			break;
		default:

			count = 0;

			break;

		}
	}

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
	//Clear LCD
	clearLCDLine(0);
	clearLCDLine(1);
	//Switch Case that actually runs the user choice
	switch(count){
	case 0:
		//If count = 0, run the code correspoinding with choice 1
		displayLCDCenteredString(0, "Red Left");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(250);						// Robot waits for 250 milliseconds


		break;
	case 1:
		//If count = 1, run the code correspoinding with choice 2
		displayLCDCenteredString(0, "Red Right");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(250);						// Robot waits for 250 milliseconds

		// Insert "Red Right" autonomous code here.


		break;
	case 2:
		//If count = 2, run the code correspoinding with choice 3
		displayLCDCenteredString(0, "Blue Left");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(20);						// Robot waits for 20 milliseconds
		MoveForward();
		motor[hang] = 127;
		wait1Msec(800);
		//Move Forward .8 Secconds
		TurnRight();
		wait1Msec(450);
		//Rotate Right .45 Secconds
		MoveForward();
		motor[claw] = 117;
		wait1Msec(400);
		//Move Forward .4 Secconds
		TurnLeft();
		motor[claw] = 0;
		wait1Msec(430);
		//Rotate Left .43 Secconds
		StopMoving();
		motor[lift1] = 100;
		motor[lift2] = 100;
		wait1Msec(700);
		//Raise Lift and Open Claw .7 Secconds
		motor[lift1] = 70;
		motor[lift2] = 70;
		MoveForward();
		wait1Msec(1200);
		//Move Forward 1.2 Secconds
		motor[claw] = 0;
		motor[hang] = 0;
		MoveForward();
		wait1Msec(200);
		//NEXT TASK
		MoveBackward();
		wait1Msec(1300);
		//Move Backwards 1.3 Secconds
		TurnLeft();
		wait1Msec(500);
		//Rotate Left .5 Secconds
		motor[lift1] = -127;
		motor[lift2] = -127;
		motor[claw] = -50;
		motor[leftbottom] = 127;
		motor[lefttop] = 127;
		motor[rightbottom] = 127;
		motor[righttop] = 127;
		wait1Msec(600);
		//Move Forwards .6 Secconds
		motor[claw] = 127;
		wait1Msec(700);
		//Close Claw .4 Secconds
		StopMoving();
		motor[lift1] = 127;
		motor[lift2] = 127;
		wait1Msec(800);
		//Open Claw .8 Secconds
		TurnRight();
		wait1Msec(600);
		//Rotate Right .6 Secconds
		MoveForward();
		wait1Msec(1000);
		//Move Forwards .6 Secconds
		motor[claw] = -127;
		wait1Msec(600);
		//Open Claw .3 Secconds
		motor[claw] = 127;
		motor[lift1] = 0;
		motor[lift2] = 0;
		StopMoving();
		wait1Msec(300);
		//Stop
		motor[lift1] = 30;
		motor[lift2] = 30;
		MoveBackward();
		wait1Msec(1300);
		//Move Backwards
		TurnRight();
		wait1Msec(150);
		//Turn Right
		motor[lift1] = -20;
		motor[lift2] = -20;
		wait1Msec(300);
		//Move Backwards and Lower Lift
		MoveForward();
		motor[lift1] = -50;
		motor[lift2] = -50;
		wait1Msec(500);
		//Move Forwards
		motor[lift1] = 0;
		motor[lift2] = 0;
		wait1Msec(600);
		StopMoving();
		//Stop

		break;

	case 3:
		//If count = 3, run the code correspoinding with choice 4
		displayLCDCenteredString(0, "Blue Right");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(250);						// Robot waits for 250 milliseconds

		// Insert "Blue Right" autonomous code here.

		break;
	default:
		displayLCDCenteredString(0, "No valid choice");
		displayLCDCenteredString(1, "was made!");
		break;
}}

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
	// User control code here, inside the loop


	while(1 == 1)
	{
		//Right side of the robot is controlled by the right joystick, Y-axis
		motor[righttop] = vexRT[Ch2];
		motor[rightbottom]  = vexRT[Ch2];
		//Left side of the robot is controlled by the left joystick, Y-axis
		motor[lefttop] = vexRT[Ch3];
		motor[leftbottom]  = vexRT[Ch3];
		if(vexRT[Btn6DXmtr2] == 1) {
			motor[hang] = -127;
		}
		if(vexRT[Btn6UXmtr2] == 1) {
			motor[hang] = 127;
		}
		if(vexRT[Btn6DXmtr2] == 0) {
			if(vexRT[Btn6UXmtr2] == 0) {
				motor[hang] = 0;
			}
		}
		motor[lift1] = vexRT[Ch2Xmtr2];
		motor[lift2] = vexRT[Ch2Xmtr2];
		motor[claw] = vexRT[Ch3Xmtr2];    {
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

	}
}
