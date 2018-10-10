/*#pragma config(Motor,  port2,         FrontLeft,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           TopFlyWheel,   tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           BackLeft,      tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           Flipper,       tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           Intake,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port7,           BackRight,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           BottomFlyWheel,tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           FrontRight,    tmotorVex393HighSpeed_MC29, openLoop)
//*!!Code generated by Luke    *///
//const float PI = 3.1415926;

void driveForward(int x){
	int rx,lx=x;
	SensorValue[leftDriveEnc]=0;
	SensorValue[rightDriveEnc]=0;

	while(rx>0&&lx>0){
		motor[FrontLeft]=motor[BackLeft]=lx*20;
		motor[FrontRight]=motor[BackRight]=-rx*20;
		lx-=abs((SensorValue[leftDriveEnc]/360)*(int)(PI*(float)(4)));
		rx-=abs((SensorValue[leftDriveEnc]/360)*(int)(PI*(float)(4)));
	}
}
void driveBackwards(int x){
	int rx,lx=x;
	SensorValue[leftDriveEnc]=0;
	SensorValue[rightDriveEnc]=0;

	while(rx>0&&lx>0){
		motor[FrontLeft]=motor[BackLeft]=-lx*20;
		motor[FrontRight]=motor[BackRight]=rx*20;
		lx-=abs((SensorValue[leftDriveEnc]/360)*(int)(PI*(float)(4)));
		rx-=abs((SensorValue[leftDriveEnc]/360)*(int)(PI*(float)(4)));
	}
}
void flyWheelSlewUp(int seconds){
	if(motor[leftFlyWheel]<127){
	for(int x = 0; x<=seconds*10; x++){
	motor[leftFlyWheel]+=(127/(seconds*10));
	motor[rightFlyWheel]-=(127/(seconds*10));
	wait1Msec(100);
	}
}
motor[leftFlyWheel]=127;
motor[rightFlyWheel]=-127;
}

void flyWheelSlewDown(int seconds){
	if(motor[leftFlyWheel]>0){
	for(int x = 0; x<=seconds*10; x++){
	motor[leftFlyWheel]-=(127/(seconds*10));
	motor[rightFlyWheel]+=(127/(seconds*10));
	wait1Msec(100);
	}
}
motor[leftFlyWheel]=0;
motor[rightFlyWheel]=0;
}
task auton(){



}
