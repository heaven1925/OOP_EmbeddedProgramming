/*******************************************************************************
  * @file    app.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 	 21.02.2023 - ...
  * @rev     V1.0.0
  * @brief	 OOP Embedded Software Programming Application
********************************************************************************/

#include "powerLed.h"


/*
* Constructor function
*/
PowerLed::PowerLed( LedColors_Type _color			   ,
										LedState_Type	 _state			   ,
										LedCurrent_Type	_current	   ,
										LedDiameter_Type	_diameter  ,
										LedVoltage_Type	_voltage		 )
										:Led(_color,_state),
										current(_current)	 ,
										diameter(_diameter),
										voltage(_voltage)
{
	/* Construct child */
	
	/* Construct parent */
	
}

/*
* Power Led Class Methods
*/
void	PowerLed::PowerLed_setCurrent		( LedCurrent_Type	_current 	)
{
	this->current = _current ;
}


void	PowerLed::PowerLed_setDiameter	( LedDiameter_Type	_diameter )
{
	this->diameter = _diameter ;
}	

void	PowerLed::PowerLed_setVoltage		( LedVoltage_Type	_voltage 	)
{
	this->voltage = _voltage;
}

PowerLed_power		PowerLed::PowerLed_computePower	()
{
	return ( this->voltage * this->current );
}

LedCurrent_Type		PowerLed::PowerLed_getCurrent		()
{
	return this->current ;
}

LedDiameter_Type	PowerLed::PowerLed_getDiameter  ()
{
	return this->diameter;
}

LedVoltage_Type		PowerLed::PowerLed_getVoltage   ()
{
	return this->voltage;
}
