#pragma config(Motor,  port6,           S1,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           S2,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           S3,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           S4,            tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while (1 == 1)
	{
		motor[S1] = 100;
		motor[S2] = 100;
		motor[S3] = 100;
		motor[S4] = 100;
	}


}
