/*******************************************************************************
  * @file    app.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 	 27.02.2023 - ...
  * @rev     V1.0.0
  * @brief	 OOP Embedded Software Programming Application
********************************************************************************/

#include "controlLed.h"

void ControlLed_ctor( ControlLed_Type* const param  ,
											LedDimmDuty_Type _dimmDuty		,
											LedColors_Type	_color				,
											LedState_Type		_state				)
{
	
	static const struct LedVTable vTable =
	{
		(void			(*)	(Led_Type const * const param)	) &ControlLed_runDiagnostics 		,
		(uint32_t	(*)	(Led_Type const * const param)	)	&ControlLed_computeEfficiency	,
	};
	
	Led_cotr(&param->super , _color , _state);
	
	param->super.vptr = &vTable;
	
	param->dimmDuty = _dimmDuty;
}



LedDimmDuty_Type 	ControlLed_getDimmDuty( ControlLed_Type* const param )
{
	return param->dimmDuty;
}


void							ControlLed_setDimmDuty( ControlLed_Type* const param , LedDimmDuty_Type dimmDuty)
{
	param->dimmDuty = dimmDuty;
}

void							ControlLed_runDiagnostics( ControlLed_Type const * const param )
{
	/* Dummy Diagnostic Sequence */
	char controlLed_textBuffer[40];
	
	for( uint8_t loopVal = 0 ; loopVal < 20 ; loopVal ++)
	{
		sprintf(&controlLed_textBuffer[0] , "Control LEd Diagnostic Stage = %d \n\r",loopVal);
	}
	
}


uint32_t					ControlLed_computeEfficiency( ControlLed_Type const * const param )
{
	/* Dummy Efficiency Computation */
	const uint8_t in 	= 100;
	const uint8_t out	= 200;
	const uint8_t k1	= 12;
	const uint8_t k2  = 8;
	
	int8_t K;
	
	K = param->dimmDuty == HIGH ? k1 : k2 ;
	
	return ( ((in/out)*100)-K);
}

