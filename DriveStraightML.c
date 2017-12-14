#pragma config(Motor,  port2,           BL,            tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port4,           FL,            tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port5,           BR,            tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port6,           FR,            tmotorVex393_MC29, openLoop, reversed, driveRight)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
  Project Title: Simple Machine Learning Robot
  Team Members: Ethan Hansen, Carly Thorkildson, and Laura Denney
  Date: 11-17-2017
  Section:


  Task Description:


  Pseudocode:

*/


	//Setting original values as global so we can access them from the debugger window
	int newLeftMCVal = 10 + random(100);
	int newRightMCVal = 10 + random(100);
	int oldLeftMCVal = newLeftMCVal;
	int oldRightMCVal = newRightMCVal;
	float oldDistance = 0;
	float newDistance = 0;
	int newVal = 0;
	bool flase = false;



task main()
{                                     //Program begins, insert code within curly braces

	//set global variables to new values. Not sure why this is needed. Doesn't work without it
	newLeftMCVal = 10 + random(100);
	newRightMCVal = 10 + random(100);
	oldLeftMCVal = newLeftMCVal;
	oldRightMCVal = newRightMCVal;
	oldDistance = 0;
	newDistance = 0;
	newVal = 0;

	//while loop runs until the robot goes far enough
	while (oldDistance < 100) {
		//Reset timer and reset continue variable
		clearTimer(T1);
		newVal = 0;
		//drive while time is less than 5 second (5000 milliseconds)
		while (time1[T1] < 5000) {
			motor[BL] = newLeftMCVal;
			motor[FL] = newLeftMCVal;
			motor[BR] = newRightMCVal;
			motor[FR] = newRightMCVal;
		}
		//Stop motors
		motor[BL] = 0;
		motor[FL] = 0;
		motor[BR] = 0;
		motor[FR] = 0;
		//Wait until the user enters the continue variable (1)
		waitUntil(newVal == 1);

		//Learning code
		if (newDistance > oldDistance) {
			oldRightMCVal = newRightMCVal;
			oldLeftMCVal = newLeftMCVal;

			newRightMCVal = -5 + random(10) + oldRightMCVal;
			newLeftMCVal = -5 + random(10) + oldLeftMCVal;

			oldDistance = newDistance;
		} else {
			newRightMCVal = oldRightMCVal;
			newLeftMCVal = oldLeftMCVal;

			newRightMCVal = -5 + random(10) + oldRightMCVal;
			newLeftMCVal = -5 + random(10) + oldLeftMCVal;
	}
}


}
