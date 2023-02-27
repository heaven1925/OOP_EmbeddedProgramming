/*******************************************************************************
  * @file    app.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 	 27.02.2023 - ...
  * @rev     V1.0.0
  * @brief	 OOP Embedded Software Programming Application
********************************************************************************/

#ifndef __CONTROLLED_H__
#define	__CONTROLLED_H__

#include "led.h"

typedef enum{
	LOW 	= 20 ,
	MID 	= 50 ,
	HIGH 	= 80
}LedDimmDuty_Type;

typedef struct{
	
	Led_Type 					super;
	LedDimmDuty_Type	dimmDuty;
}ControlLed_Type;


void ControlLed_ctor( ControlLed_Type* const param  ,
											LedDimmDuty_Type _dimmDuty		,
											LedColors_Type	_color				,
											LedState_Type		_state				);

LedDimmDuty_Type 	ControlLed_getDimmDuty( ControlLed_Type* const param );
void							ControlLed_setDimmDuty( ControlLed_Type* const param , LedDimmDuty_Type dimmDuty);

void							ControlLed_runDiagnostics( ControlLed_Type const * const param );
uint32_t					ControlLed_computeEfficiency( ControlLed_Type const * const param );








#endif /* __CONTROLLED_H__ */
