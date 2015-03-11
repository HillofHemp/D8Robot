#import <math.h>
#define RADTODEG 57.2957795
double getAngle(double fx, double fy)	{
	
	//Variable declaring
	double sx, sy, distance, angle, dx, dy, radicand;  
	
	//Variable Initialization 
	sx = RPS.X();
	sy = RPS.Y();
	dx = fx-sx;
	dy = fy-sy;
	
	//calculations for finding the angle to plug into arccos
	radicand = pow(dx,2) + pow(dy, 2);
	distance = sqrt(radicand);
	
	//finding angle using arccos function and distance from object and robot
	if (dy >= 0)	{
		angle = acos(dx/distance) * RADTODEG;
	} else if (dy < 0  && dx < 0)	{
		angle = (360 - acos(dx/distance))*RADTODEG;
	} else if (dy < 0 && dx >= 0)	{
		angle = -acos(dx/distance)*RADTODEG;
	}
	
	//if angle is bigger than 360, return angle to domain 0<angle<360
	angle = angle%360;
	//returns the angle for the heading
	return angle;
}
	
	
	
