/*
 * PWMController.cpp
 *
 *  Created on: Nov 13, 2015
 *      Author: Fabio
 */

#include "PWMController.h"
#include "xparameters.h"
#include "xgpio.h"
#include "xstatus.h"
#include "xil_printf.h"
#include "configuration.h"

/*
 * Default Constructor (empty)
 *
 */
PWMController::PWMController() { }

/*
 * Constructor
 *
 */
PWMController::PWMController( unsigned int newDutyCycle,
		   	   	   	   	      unsigned int newMinDutyCycle,
							  unsigned int newMaxDutyCycle,
							  int newGpioChannel,
							  u16 newDeviceId,
							  u32 newDirection){

	dutyCycle = newDutyCycle;
	maxDutyCycle = newMaxDutyCycle;
	minDutyCycle = newMinDutyCycle;
	gpioChannel = newGpioChannel;
	deviceId = newDeviceId;
	direction = newDirection;
}

/*
 * Destructor (empty)
 *
 */
PWMController::~PWMController() { }

/*
 * PWMController::Initialize
 * Initialize the GPIO port
 *
 */
int PWMController::Initialize(){
	int Status;

	Status = XGpio_Initialize(&gpioObj, deviceId);

	if (Status != XST_SUCCESS) {
		xil_printf("GPIO output to the steering failed!\r\n");
		return XST_FAILURE;
	}

	XGpio_SetDataDirection(&gpioObj, gpioChannel, direction);

	return XST_SUCCESS;
}

/*
 * PWMController::Write
 * Writes the dutyCycle variable value in the output port
 *
 */
void PWMController::Write(){
	if ( dutyCycle >= minDutyCycle && dutyCycle <= maxDutyCycle ) {
		XGpio_DiscreteWrite(&gpioObj, gpioChannel, dutyCycle);
	}
}

/*
 * PWMController::Write
 * Overloaded method that takes an pwmdutyCycle integer variable, stores
 * in this object, and writes it in the output port
 *
 */
void PWMController::Write(int pwmDutyCycle){
	dutyCycle = pwmDutyCycle;

	if ( dutyCycle >= minDutyCycle && dutyCycle <= maxDutyCycle ) {
		XGpio_DiscreteWrite(&gpioObj, gpioChannel, dutyCycle);
	}
}
