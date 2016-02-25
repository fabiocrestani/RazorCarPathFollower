/*
 * RazorCarGPIO.h
 *
 *  Created on: Dec 3, 2015
 *      Author: Fabio
 */

#ifndef RAZORCARGPIO_H_
#define RAZORCARGPIO_H_

#include "xgpio.h"

class RazorCarGPIO {

private:
	int gpioChannel;                // GPIO Channel, usually 1
	u16 deviceId;                   // Device ID given by Vivado
	u32 direction;					// Can be DIRECTION_INPUT or DIRECTION_OUTPUT
	XGpio gpioObj;                  // XGpio data structure to store the GPIO configuration

public:
	RazorCarGPIO();
	RazorCarGPIO( u16 newDeviceId, u32 newDirection, int newGpioChannel );

	virtual ~RazorCarGPIO();

	int Initialize();

	void Write(int data);
	int Read();
};

#endif /* RAZORCARGPIO_H_ */
