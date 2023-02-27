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
#include "controlLed.h"


Led_Type led_1;

PowerLed_Type 		powerLed_1;
PowerLed_power 		powerLed_1_power;

ControlLed_Type		controlLed_1;

void	appMAIN(void)
{
	
	Led_cotr( &led_1 , RED 		, OFF );
	
	PowerLed_ctor(&powerLed_1 , GREEN , OFF , CURR_NORMAL , DIAM_5MM , VOLT_NORMAL );
	powerLed_1_power = PowerLed_computePower(&powerLed_1);
	
	ControlLed_ctor(&controlLed_1 , HIGH , BLUE , OFF );
	
	Led_Type const * sys_leds[] = { &led_1 													, 
																	(Led_Type const *)&powerLed_1 	, 
																	(Led_Type const *)&controlLed_1 };
	
	while(1)
	{
		Led_setState(&led_1 , OFF);	
		Led_setState(&powerLed_1.super , OFF);
		
		PowerLed_computeEfficiency(&powerLed_1);
		ControlLed_computeEfficiency(&controlLed_1);
		
		runSystemDiagnostics(sys_leds);
		computeLedEfficiency(sys_leds);
		
		HAL_Delay(1000);	
		
		Led_setState(&led_1 , ON );
		Led_setState(&powerLed_1.super , ON);
		
		PowerLed_runDiagnostics(&powerLed_1);
		ControlLed_runDiagnostics(&controlLed_1);
		
		HAL_Delay(1000);
		
	}
}

