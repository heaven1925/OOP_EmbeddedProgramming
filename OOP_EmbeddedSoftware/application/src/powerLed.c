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
void PowerLed_ctor( PowerLed_Type* const param   , 
										LedColors_Type _color			   ,
										LedState_Type	 _state			   ,
										LedCurrent_Type	_current	   ,
										LedDiameter_Type	_diameter  ,
										LedVoltage_Type	_voltage		 )
{
	
	static const struct LedVTable vTable =
	{
		(void			(*)	(Led_Type const * const param)	) &PowerLed_runDiagnostics 		,
		(uint32_t	(*)	(Led_Type const * const param)	)	&PowerLed_computeEfficiency	,
	};
	
	/* Construct child */
	Led_cotr(&param->super , _color , _state );
	/* Construct methods */
	param->super.vptr = &vTable;
	
	/* Construct parent */
	param->current 	= _current	;
	param->diameter = _diameter	;
	param->voltage	= _voltage	;
	
	
}

/*
* Power Led Class Methods
*/
void							PowerLed_setCurrent		( PowerLed_Type* const param , LedCurrent_Type	_current 	)
{
	param->current = _current ;
}


void							PowerLed_setDiameter	( PowerLed_Type* const param , LedDiameter_Type	_diameter )
{
	param->diameter = _diameter ;
}	

void							PowerLed_setVoltage		( PowerLed_Type* const param , LedVoltage_Type	_voltage 	)
{
	param->voltage = _voltage;
}

PowerLed_power		PowerLed_computePower	( PowerLed_Type* const param )
{
	return ( param->voltage * param->current );
}

LedCurrent_Type		PowerLed_getCurrent		( PowerLed_Type* const param )
{
	return param->current ;
}

LedDiameter_Type	PowerLed_getDiameter  ( PowerLed_Type* const param )
{
	return param->diameter;
}

LedVoltage_Type		PowerLed_getVoltage   ( PowerLed_Type* const param )
{
	return param->voltage;
}


void							PowerLed_runDiagnostics		( PowerLed_Type const * const param )
{
/* Dummy Diagnostic Sequence */
	char powerLed_textBuffer[40];
	
	for( uint8_t loopVal = 0 ; loopVal < 20 ; loopVal ++)
	{
		sprintf(&powerLed_textBuffer[0] , "Power Led Diagnostic Stage = %d \n\r",loopVal);
	}
}


uint32_t					PowerLed_computeEfficiency( PowerLed_Type const * const param )
{
	const uint8_t in 	= 100;
	const uint8_t out	= 200;
	const uint8_t k1	= 12;
	const uint8_t k2  = 8;
	
	int8_t K;
	
	K = param->current == CURR_VERYHIGH ? k1 : k2 ;
	
	return ( ((in/out)*100)-K);
	
	
}

