/*******************************************************************************
  * @file    app.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 	 21.02.2023 - ...
  * @rev     V1.0.0
  * @brief	 LED CLASS
********************************************************************************/

#include "led.h"

static void 			run_diagnostics				(Led_Type const * const param);
static uint32_t 	compute_efficiency		(Led_Type const * const param);


void Led_cotr(Led_Type* const param , LedColors_Type _color , LedState_Type _state)
{
	
	/* Initial Virtual Table */
	static const struct LedVTable vTable=
	{
		&run_diagnostics,
		&compute_efficiency
	};
	
	param->vptr = &vTable;
	
	param->color = _color;
	param->state = _state;
	
	GPIO_PinState pinState = GPIO_PIN_RESET;

	switch( _color )
	{
		case RED: 
		pinState = ( _state == ON ) ? GPIO_PIN_SET : GPIO_PIN_RESET ;
		
		break;
		
		case GREEN: 
		pinState = ( _state == ON ) ? GPIO_PIN_SET : GPIO_PIN_RESET ;
		HAL_GPIO_WritePin(LED_PORT, LED_GREEN_PIN, pinState);
			
		break;
		
		case YELLOW: 

		pinState = ( _state == ON ) ? GPIO_PIN_SET : GPIO_PIN_RESET ;
		HAL_GPIO_WritePin(LED_PORT, LED_YELLOW_PIN, pinState);
		
		break;
		
		case BLUE: 
			
		pinState = ( _state == ON ) ? GPIO_PIN_SET : GPIO_PIN_RESET ;
		HAL_GPIO_WritePin(LED_PORT, LED_BLUE_PIN, pinState); 
		
		break;		
	}
	
}


void Led_setState(Led_Type* const param , LedState_Type _state )
{
	param->state = _state;
	GPIO_PinState pinState = ( _state == ON ) ? GPIO_PIN_SET : GPIO_PIN_RESET;
	
	switch( param->color )
	{
		case RED	 : HAL_GPIO_WritePin(LED_PORT, LED_RED_PIN	, pinState	  ); break;
		case GREEN : HAL_GPIO_WritePin(LED_PORT, LED_GREEN_PIN, pinState	  ); break;	
		case YELLOW: HAL_GPIO_WritePin(LED_PORT, LED_YELLOW_PIN, pinState		); break;		
		case BLUE	 : HAL_GPIO_WritePin(LED_PORT, LED_BLUE_PIN	 , pinState		); break;				
	}
}


LedState_Type Led_getState(Led_Type* const param )
{
	return param->state;
}


static void 		run_diagnostics(Led_Type const * const param)
{
	(void)param;
}

static uint32_t compute_efficiency(Led_Type const * const param)
{
	(void)param;
		return 0;
}

/* Polymorphism at work */

void					runSystemDiagnostics(Led_Type const* led_modules[] )
{
	for( uint8_t loopVal = 0 ; led_modules[ loopVal ] != (Led_Type*)0 ; loopVal++ )
	{
		Led_runDiagnostics_vcall( led_modules[ loopVal ] );
	}
}

void					computeLedEfficiency(Led_Type const* led_modules[] )
{
	for( uint8_t loopVal = 0 ; led_modules[ loopVal ] != (Led_Type*)0 ; loopVal++ )
	{
		Led_computeEfficiency_vcall( led_modules[ loopVal ]  ); 
	}
}

