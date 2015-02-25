#include "encoderFunctions.h"

#define POWER 25

//main method for performance test 2
int main()
{
	RPS.InitializeMenu();
	waitForLightChange();
	
	pulseForward(POWER,439);
	rpsYMinus(18.5);
	
	pulseLeft(POWER,159);
	rpsTurn(90);
	
	pulseForward(POWER,371);
	rpsXPlus(29.3);
	
	pulseLeft(POWER,159);
	rpsTurn(180);
	
	pulseForward(POWER,1485);
	rpsYPlus(62.5);
}