/*******************************************************************************
  * @file    led.cpp
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 	 21.02.2023 - ...
  * @rev     V1.0.0
  * @brief	 OOP Embedded Software Programming Application
********************************************************************************/

#include "led.h"


Led::Led(LedColors_Type _color , LedState_Type _state)
/* Option 2 */
//: color(_color) , state(_state)
{
	this->color = _color;
	this->state = _state;
}

void 		Led::Led_setState(LedState_Type _state )
{
	this->state = _state;
	
	GPIO_PinState pinState = ( _state == ON ) ? GPIO_PIN_SET : GPIO_PIN_RESET;

	switch( this->color )
	{
		case RED 		: HAL_GPIO_WritePin(LED_PORT , LED_RED_PIN , pinState 		);  break;
		case GREEN 	: HAL_GPIO_WritePin(LED_PORT , LED_GREEN_PIN , pinState 	);	break;
		case BLUE 	: HAL_GPIO_WritePin(LED_PORT , LED_BLUE_PIN , pinState 		);	break;
		case YELLOW : HAL_GPIO_WritePin(LED_PORT , LED_YELLOW_PIN , pinState 	);	break;
	}
	
}


LedState_Type Led::Led_getState()const
{
	return this->state;
}
