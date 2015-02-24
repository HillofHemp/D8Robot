#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>
#include <FEHRPS.h>

#define POWER 25 

//initialization statements
ButtonBoard buttons(FEHIO::Bank3);
FEHMotor rMotor(FEHMotor::Motor0);
FEHMotor lMotor(FEHMotor::Motor1);


//use RPS to check x location while robot is facing the +x direction
void rpsXPlus(float x_coordinate)
{
	int change=2;
	//check whether the robot is within an acceptable range
    while(RPS.X() < x_coordinate - .5 || RPS.X() > x_coordinate + .5)
    {
      if(RPS.X() > x_coordinate)
      {
      	if(change==1)
    		{
    			rMotor.Stop();
				lMotor.Stop();
    		}
      	//pulse the motors for a short duration in the correct direction
      	rMotor.SetPercent(-POWER);
			lMotor.SetPercent(-POWER);
			change=0;
      }
      else if(RPS.X() < x_coordinate)
      {
       	if(change==0)
    		{
    			rMotor.Stop();
				lMotor.Stop();
    		}
      	//pulse the motors for a short duration in the correct direction
      	rMotor.SetPercent(POWER);
			lMotor.SetPercent(POWER); 
			change=1;    
      }
	}
}

//use RPS to check x location while robot is facing the -x direction
void rpsXMinus(float x_coordinate)
{
	int change=2;
	//check whether the robot is within an acceptable range
    while(RPS.X() < x_coordinate - .5 || RPS.X() > x_coordinate + .5)
    {
        if(RPS.X() > x_coordinate)
        {
      	if(change==1)
    		{
    			rMotor.Stop();
				lMotor.Stop();
    		}
      	//pulse the motors for a short duration in the correct direction
      	rMotor.SetPercent(POWER);
			lMotor.SetPercent(POWER);
			change=0;
        }
        else if(RPS.X() < x_coordinate)
        {
       	if(change==0)
    		{
    			rMotor.Stop();
				lMotor.Stop();
    		}
      	//pulse the motors for a short duration in the correct direction
      	rMotor.SetPercent(-POWER);
			lMotor.SetPercent(-POWER);
			change=1;
        }
	}
}


//use RPS to check y location while robot is facing the -y direction
void rpsYMinus(float y_coordinate)
{
	int change=2;
	//check whether the robot is within an acceptable range
    while(RPS.Y() < y_coordinate - .5 || RPS.Y() > y_coordinate + .5)
    {
        if(RPS.Y() > y_coordinate)
        {
      	if(change==1)
    		{
    			rMotor.Stop();
				lMotor.Stop();
    		}
      	//pulse the motors for a short duration in the correct direction
      	rMotor.SetPercent(POWER);
			lMotor.SetPercent(POWER);
			change=0;
        }
        else if(RPS.Y() < y_coordinate)
        {
       	if(change==0)
    		{
    			rMotor.Stop();
				lMotor.Stop();
    		}
      	//pulse the motors for a short duration in the correct direction
      	rMotor.SetPercent(-POWER);
			lMotor.SetPercent(-POWER);
			change=1;
        }
	}
}

//use RPS to check y location while robot is facing the +y direction
void rpsYPlus(float y_coordinate)
{
	int change=2;
	//check whether the robot is within an acceptable range
    while(RPS.Y() < y_coordinate - .5 || RPS.Y() > y_coordinate + .5)
    {
        if(RPS.Y() > y_coordinate)
        {
      	if(change==1)
    		{
    			rMotor.Stop();
				lMotor.Stop();
    		}
      	//pulse the motors for a short duration in the correct direction
      	rMotor.SetPercent(-POWER);
			lMotor.SetPercent(-POWER);
			change=0;
        }
        else if(RPS.Y() < y_coordinate)
        {
       	if(change==0)
    		{
    			rMotor.Stop();
				lMotor.Stop();
    		}
      	//pulse the motors for a short duration in the correct direction
      	rMotor.SetPercent(POWER);
			lMotor.SetPercent(POWER); 
			change=1; 
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
      	if(change==1)
    		{
    			rMotor.Stop();
				lMotor.Stop();
    		}
      	//pulse the motors for a short duration in the correct direction
      	rMotor.SetPercent(-POWER);
			lMotor.SetPercent(POWER);
			change=0;
		}
		else if(RPS.Heading() < heading)
		{
       	if(change==0)
    		{
    			rMotor.Stop();
				lMotor.Stop();
    		}
      	//pulse the motors for a short duration in the correct direction
      	rMotor.SetPercent(POWER);
			lMotor.SetPercent(-POWER); 
			change=1; 
      }
   } 
}