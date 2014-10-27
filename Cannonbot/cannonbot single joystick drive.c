#pragma config(Sensor, in3,    back_limit_switch, sensorTouch)
#pragma config(Sensor, in4,    front_limit_switch, sensorTouch)
#pragma config(Sensor, in5,    pneumatic_1,    sensorDigitalOut)
#pragma config(Sensor, in9,    pneumatic_lift, sensorDigitalOut)
#pragma config(Sensor, in10,   pneumatic_lift, sensorDigitalOut)
#pragma config(Sensor, in11,   pneumatic_lift, sensorDigitalOut)
#pragma config(Sensor, in12,   pneumatic_lift, sensorDigitalOut)
#pragma config(Sensor, in15,   pneumatic_cannon, sensorDigitalOut)
#pragma config(Motor,  port1,           left_front,    tmotorVex393, openLoop)
#pragma config(Motor,  port2,           right_front,   tmotorVex393, openLoop)
#pragma config(Motor,  port3,           right_back,    tmotorVex393, openLoop)
#pragma config(Motor,  port4,           left_back,     tmotorVex393, openLoop)
#pragma config(Motor,  port5,           cannon,        tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	bVexAutonomousMode = false;

	while(1 == 1)
	{
		//motor[left_front] = 0;
		//motor[left_back] = 0;
		//motor[right_front] = 127;
		//motor[right_back] = 127;

		//motor[right_back] = vexRT(Ch2);
		//motor[right_front] = vexRT(Ch2);
		//motor[left_back] = vexRT(Ch1);
		//motor[left_front] = vexRT(Ch1);
		motor[right_front] = vexRT[Ch2]/2 - vexRT[Ch1]/2;		//y-axis value: forward/backward motion
		motor[left_front] = vexRT[Ch2]/2 + vexRT[Ch1]/2;
		motor[right_back] = vexRT[Ch2]/2 - vexRT[Ch1]/2;
		motor[left_back] = vexRT[Ch2]/2 + vexRT[Ch1]/2;

		if(vexRT[Ch5] == 1)
		{
			SensorValue[pneumatic_lift] = 1;
		}
		//else if(vexRT[Ch5] == -1)
		//{
		//	SensorValue[pneumatic_lift] = -1;
		//}
		else if(vexRT[Ch5] == 0)
		{
			SensorValue[pneumatic_lift] = 0;
		}
		if (vexRT[btn6U] == 1)
		{
			SensorValue[pneumatic_cannon] = 0;
		}
		if (vexRT[btn6D] == 1)
		{
			SensorValue[pneumatic_cannon] = 0;
		}
			if (vexRT[btn6U] == 0)
		{
			SensorValue[pneumatic_cannon] = 1;
		}
			if (vexRT[btn6D] == 0)
		{
			SensorValue[pneumatic_cannon] = 1;
		}
		motor[cannon] = vexRT[Ch3]; // movement of cannon up and down
	}
}