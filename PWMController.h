/*
 * PWMController.h
 *
 *  Created on: Nov 13, 2015
 *      Author: Fabio
 */

#ifndef PWMCONTROLLER_H_
#define PWMCONTROLLER_H_

/* Include Files */
#include "xparameters.h"
#include "xgpio.h"
#include "xstatus.h"
#include "xil_printf.h"

class PWMController {

private:
	unsigned int dutyCycle;			// Actual duty cycle
	unsigned int maxDutyCycle;      // Max duty cycle value for this device
	unsigned int minDutyCycle;      // Min duty cycle value for this device
	int gpioChannel;                // GPIO Channel, usually 1
	u16 deviceId;                   // Device ID given by Vivado
	u32 direction;					// Can be DIRECTION_INPUT or DIRECTION_OUTPUT
	XGpio gpioObj;                  // XGpio data structure to store the GPIO configuration

public:

	PWMController();
	PWMController( unsigned int newDutyCycle,
				   unsigned int newMinDutyCycle,
				   unsigned int newMaxDutyCycle,
				   int newGpioChannel,
				   u16 newDeviceId,
				   u32 newDirection);

	virtual ~PWMController();

	int Initialize();

	void Write();
	void Write(int pwmDutyCycle);
};

#endif /* PWMCONTROLLER_H_ */
