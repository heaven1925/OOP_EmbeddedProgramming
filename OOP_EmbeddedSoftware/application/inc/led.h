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

/*************************** struct definitions **********************************/

/*
* Led Type Struct
*/
typedef struct{
	struct LedVTable const *vptr;	 /* Virtual Pointer */
	LedColors_Type 					color; /* Color Of Led */
	LedState_Type	 					state; /* State Of Led */
}Led_Type;

/*
* Led Virtual Functions
*/
struct LedVTable{
	
	void 				(*run_diagnostics)(Led_Type const * const param);
	uint32_t		(*compute_efficiency)(Led_Type const * const param);
};

/* Method 1 */
static inline void Led_runDiagnostics_vcall(Led_Type const * const param)
{
	(*param->vptr->run_diagnostics)(param);
}
static inline uint32_t Led_computeEfficiency_vcall(Led_Type const * const param)
{
	return (*param->vptr->compute_efficiency)(param);
}
/* Method 2 */

#define		LED_RUN_DIAG_VCALL(param)		( *(param)->vptr->run_diagnostics 		)(param)
#define		LED_COMP_EFF_VCALL(param)		(	*(param)->vptr->compute_efficiency	)(param)

/************************* function declerations ********************************/

/*
* Constructor function
*/
void Led_cotr(Led_Type* const param , LedColors_Type _color , LedState_Type _state);

/*
* Led Class Methods
*/
void 					Led_setState(Led_Type* const param , LedState_Type _state );
LedState_Type Led_getState(Led_Type* const param );

/*
*
*/
void					runSystemDiagnostics(Led_Type const* led_modules[] );
void					computeLedEfficiency(Led_Type const* led_modules[] );

#endif /* __LED_H__ */
