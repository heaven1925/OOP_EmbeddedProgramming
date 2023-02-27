




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

/*************************** Cpp definitions **********************************/

class	PowerLed:public Led{

private:
	LedCurrent_Type		current;
	LedDiameter_Type	diameter;
	LedVoltage_Type		voltage;
public:
	PowerLed( LedColors_Type _color			   ,
						LedState_Type	 _state			   ,
						LedCurrent_Type	_current	   ,
						LedDiameter_Type	_diameter  ,
						LedVoltage_Type	_voltage		 );
	
	void							PowerLed_setCurrent		( LedCurrent_Type	_current 	);
	void							PowerLed_setDiameter	( LedDiameter_Type	_diameter );
	void							PowerLed_setVoltage		( LedVoltage_Type	_voltage 	);

	PowerLed_power		PowerLed_computePower	();
	LedCurrent_Type		PowerLed_getCurrent		();
	LedDiameter_Type	PowerLed_getDiameter  ();
	LedVoltage_Type		PowerLed_getVoltage   ();
	
};

#endif /* __POWERLED_H__ */
