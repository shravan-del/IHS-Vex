#pragma config(Sensor, dgtl1,  dab,            sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  dab2,           sensorQuadEncoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#pragma DebuggerWindows("debugStream")
int  value;
task main()
{
	SensorValue[dab] = 0;
	while (1==1){


    // delay while motor accelerate
    // clear encoder, enc should be the digital port that the encoder is on
    wait1Msec(10);
    value = SensorValue[dab]; //NOTE TO KADALI: THIS WORKS FAM

    // stop motor
    motor[ port5 ] = 0;
    motor[ port6 ] = 0;
    motor[ port3 ] = 0;
    motor[ port2 ] = 0;

    // wait for 1


    // send to stdio
    writeDebugStreamLine("encoder count is %d", value );

    // done
}
}
