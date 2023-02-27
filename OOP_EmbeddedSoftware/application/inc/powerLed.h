/*******************************************************************************
  * @file    app.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 	 21.02.2023 - ...
  * @rev     V1.0.0
  * @brief	 OOP Embedded Software Programming Application
********************************************************************************/

#ifndef __POWERLED_H__
#define	__POWERLED_H__

#include "led.h" /* Parent Class */

typedef uint8_t PowerLed_power;
typedef uint8_t PowerLed_dimm_time;

typedef enum
{
	CURR_LOW 			= 10 , /* 10mA */
	CURR_NORMAL 	=	25 ,
	CURR_HIGH			= 50 ,
	CURR_VERYHIGH = 100,
}LedCurrent_Type;

typedef enum
{
	DIAM_2MM 	= 2,
	DIAM_5MM	= 5,
	DIAM_10MM = 10,
}LedDiameter_Type;

typedef enum
{
	VOLT_LOW 		= 3 ,
	VOLT_NORMAL = 5 ,
	VOLT_HIGH		= 10 ,
}LedVoltage_Type;

/*************************** struct definitions **********************************/

typedef struct{
	
	/* Inherit Led Class */
	Led_Type					super;
	/* childs of powerLed class */
	LedCurrent_Type		current;
	LedDiameter_Type	diameter;
	LedVoltage_Type		voltage;
	
}PowerLed_Type;

/************************* function declerations ********************************/

/*
* Constructor function
*/
void PowerLed_ctor( PowerLed_Type* const param   , 
										LedColors_Type _color			   ,
										LedState_Type	 _state			   ,
										LedCurrent_Type	_current	   ,
										LedDiameter_Type	_diameter  ,
										LedVoltage_Type	_voltage		 );

/*
* Power Led Class Methods
*/
void							PowerLed_setCurrent		( PowerLed_Type* const param , LedCurrent_Type	_current 	);
void							PowerLed_setDiameter	( PowerLed_Type* const param , LedDiameter_Type	_diameter );
void							PowerLed_setVoltage		( PowerLed_Type* const param , LedVoltage_Type	_voltage 	);

PowerLed_power		PowerLed_computePower	( PowerLed_Type* const param );

LedCurrent_Type		PowerLed_getCurrent		( PowerLed_Type* const param );
LedDiameter_Type	PowerLed_getDiameter  ( PowerLed_Type* const param );
LedVoltage_Type		PowerLed_getVoltage   ( PowerLed_Type* const param );

void							PowerLed_runDiagnostics		( PowerLed_Type const * const param );
uint32_t					PowerLed_computeEfficiency( PowerLed_Type const * const param );

#endif /* __POWERLED_H__ */
