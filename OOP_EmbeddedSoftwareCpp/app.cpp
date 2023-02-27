/*******************************************************************************
  * @file    app.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 	 21.02.2023 - ...
  * @rev     V1.0.0
  * @brief	 OOP Embedded Software Programming Application
********************************************************************************/

#include "app.h"

#include "powerLed.h"

//rcc init

//gpio init reqs

int main(void)
{
	// Static
	Led led1(BLUE,OFF);
	// Dynamic
	Led* led2 = new Led(YELLOW , OFF);

	// Static
	PowerLed 	powerLed1(GREEN, ON, CURR_HIGH, DIAM_5MM, VOLT_NORMAL);
	// Dynamic
	PowerLed*	powerLed2 = new PowerLed(RED, ON, CURR_HIGH, DIAM_5MM, VOLT_NORMAL);
	
	PowerLed_power powerLed1_power = powerLed1.PowerLed_computePower();
	PowerLed_power powerLed2_power = powerLed2->PowerLed_computePower();
	
	while(1)
	{
		
		led1.Led_setState(ON);
		led2->Led_setState(ON);
		powerLed1.Led_setState(ON);
		powerLed2->Led_setState(ON);
		
		HAL_Delay(1000);
		
		led1.Led_setState(OFF);
		led2->Led_setState(OFF);
		powerLed1.Led_setState(OFF);
		powerLed2->Led_setState(OFF);
		
		HAL_Delay(1000);
		
		delete led2;
		delete powerLed2;
	}
}
