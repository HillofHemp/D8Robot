#include "encoderFunctions.h"

#define MPOWER -30

//main method for performance test 2
int main()
{
	char[] order = getOrder();
	LCD.WriteLine(order[0]+order[1]+order[2]);
	
	while(!buttons.MiddlePressed)
	{
		if(allButtonsPressed)
		{
			LCD.WriteLine("ALL PRESSED");
		}
	}
	

    //RPS.InitializeMenu();
    waitForLightChange();

    pulseForward(MPOWER,encodeLength(13));
    //rpsYMinus(18.5);

    pulseLeft(20,200);
    //rpsTurn(90);

    pulseForward(MPOWER,encodeLength(12));
    //rpsXPlus(29.3);

    pulseLeft(20,200);
    //rpsTurn(180);

    pulseForward(MPOWER,encodeLength(60));
    //rpsYPlus(65);
}
