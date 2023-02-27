/*******************************************************************************
  * @file    app.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 	 21.02.2023 - ...
  * @rev     V1.0.0
  * @brief	 LED CLASS
	
	In this project we have 4 led which is "red, green, yellow and blue.
	Led has two state there are ON & OFF
	Led class attributes defined with structure;
	
	
********************************************************************************/

#ifndef __LED_H__
#define	__LED_H__

/***************************** includes *****************************************/

#include "stm32f4xx.h"

#include "stdint.h"
#include "stdio.h"

/***************************** defines ******************************************/

#define		LED_PORT						GPIOD

#define		LED_RED_PIN					GPIO_PIN_12
#define		LED_GREEN_PIN				GPIO_PIN_13
#define		LED_YELLOW_PIN			GPIO_PIN_14
#define		LED_BLUE_PIN				GPIO_PIN_15

/*************************** enumarators ****************************************/

/*
* Led Colors Enum Type
*/
typedef enum{ 
	RED = 0 , 
	GREEN , 
	YELLOW, 
	BLUE 
}LedColors_Type;

/*
* Led State Enum Type
*/
typedef enum{
	OFF = 0 ,
	ON = !OFF
}LedState_Type;


/**************************** Cpp Definitions ***********************************/

class Led{
	
	private:
		LedColors_Type 	color;
		LedState_Type	 	state;
	public:
		/* Constructor */
		Led						(LedColors_Type _color , LedState_Type _state);
		/* Methods */
		void 					Led_setState(LedState_Type _state );
		LedState_Type Led_getState()const;
};



#endif /* __LED_H__ */
