#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>
#include <FEHRPS.h>

#define POWER 10
#define TURNPOWER 10
#define COUNTS 5

//initialization statements
ButtonBoard buttons(FEHIO::Bank3);
DigitalEncoder rEncoder(FEHIO::P2_0);
DigitalEncoder lEncoder(FEHIO::P2_1);
FEHMotor rMotor(FEHMotor::Motor0);
FEHMotor lMotor(FEHMotor::Motor1);
AnalogInputPin CdS (FEHIO::P0_0);

//returns an expected encoder count for a given distance in inches
int encodeLength(float dist)
{
	return dist*33.7408; //test but it should truncate the float to an int
}

//wait until the light changes to start the course
void waitForLightChange()
{
    LCD.WriteLine("WAITING");
    while(CdS.Value()>.6);
    LCD.WriteLine("LIGHT CHANGE");
}


//pulse forward measuring using encoders
//for use withen the rpsForward command
void pulseForward(int percent, int counts)
{
	int lCounts=0; 
	int rCounts=0;
	int	sum=0;
	//Rest encoder counts
	rEncoder.ResetCounts();
	lEncoder.ResetCounts();
	
	//set both motors to the desired percen
	rMotor.SetPercent(percent);
	lMotor.SetPercent(percent);
	
	//move each motor forward the expected number of counts
	while(sum < counts*2)
	{
		lCounts = lEncoder.Counts();
		rCounts = rEncoder.Counts();
		sum = lCounts+rCounts;
	}
	//turn motors off
	rMotor.Stop();
	lMotor.Stop();
}

//pulse left measuring using encoders
//for use withen the rpsTurn command
void pulseLeft(int percent, int counts)
{
	int lCounts=0; 
	int rCounts=0;
	int	sum=0;
	//Rest encoder counts
	rEncoder.ResetCounts();
	lEncoder.ResetCounts();
	
	//set both motors to the desired percent
	rMotor.SetPercent(percent);
	lMotor.SetPercent(-percent);
	
	//move each motor forward the expected number of counts
	while(sum < counts*2)
	{
		lCounts = lEncoder.Counts();
		rCounts = rEncoder.Counts();
		sum = lCounts+rCounts;
	}

	//turn motors off
	rMotor.Stop();
	lMotor.Stop();
}

//pulse right measuring using encoders
//for use withen the rpsTurn command
void pulseRight(int percent, int counts)
{
	int lCounts=0; 
	int rCounts=0;
	int	sum=0;
	//Rest encoder counts
	rEncoder.ResetCounts();
	lEncoder.ResetCounts();
	
	//set both motors to the desired percent
	rMotor.SetPercent(-percent);
	lMotor.SetPercent(percent);
	
	//move each motor forward the expected number of counts
	while(sum < counts*2)
	{
		lCounts = lEncoder.Counts();
		rCounts = rEncoder.Counts();
		sum = lCounts+rCounts;
	}

	//turn motors off
	rMotor.Stop();
	lMotor.Stop();
}

//use RPS to check x location while robot is facing the +x direction
void rpsXPlus(float x_coordinate)
{
//check whether the robot is within an acceptable range
    while(RPS.X() < x_coordinate - .5 || RPS.X() > x_coordinate + .5)
    {
        if(RPS.X() > x_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(-POWER,COUNTS);
        }
        else if(RPS.X() < x_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(POWER,COUNTS);
        }
	}
}

//use RPS to check x location while robot is facing the -x direction
void rpsXMinus(float x_coordinate)
{
//check whether the robot is within an acceptable range
    while(RPS.X() < x_coordinate - .5 || RPS.X() > x_coordinate + .5)
    {
        if(RPS.X() > x_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(POWER,COUNTS);
        }
        else if(RPS.X() < x_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(-POWER,COUNTS);
        }
	}
}


//use RPS to check y location while robot is facing the -y direction
void rpsYMinus(float y_coordinate)
{
	//check whether the robot is within an acceptable range
    while(RPS.Y() < y_coordinate - .5 || RPS.Y() > y_coordinate + .5)
    {
        if(RPS.Y() > y_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(POWER,COUNTS);
        }
        else if(RPS.Y() < y_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(-POWER,COUNTS);
        }
	}
}

//use RPS to check y location while robot is facing the +y direction
void rpsYPlus(float y_coordinate)
{
	//check whether the robot is within an acceptable range
    while(RPS.Y() < y_coordinate - .5 || RPS.Y() > y_coordinate + .5)
    {
        if(RPS.Y() > y_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(-POWER,COUNTS);
        }
        else if(RPS.Y() < y_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(POWER,COUNTS);
        }
	}
}


//turn using rps and turn subfunctions
void rpsTurn(float heading)
{
	while(RPS.Heading() < heading - 1 || RPS.Heading() > heading + 1)
	{
		if(RPS.Heading() > heading)
		{
			//pulse the motors for a short duration in the correct direction
			pulseRight(TURNPOWER,COUNTS);
			//LCD.WriteLine("HEADING CHECK RIGHT");
		}
		else if(RPS.Heading() < heading)
		{
			pulseLeft(TURNPOWER,COUNTS);
			//LCD.WriteLine("HEADING CHECK LEFT");
      }
   } 
}
