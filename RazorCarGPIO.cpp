/*
 * RazorCarGPIO.cpp
 *
 *  Created on: Dec 3, 2015
 *      Author: Fabio
 */

#include "RazorCarGPIO.h"

/*
 * RazorCarGPIO() (Default Constructor)
 *
 */
RazorCarGPIO::RazorCarGPIO() { }

/*
 * RazorCarGPIO( u16 newDeviceId, u32 newDirection, int newGpioChannel )
 * Overloaded constructor which sets the GPIO properties.
 */
RazorCarGPIO::RazorCarGPIO( u16 newDeviceId, u32 newDirection, int newGpioChannel ) {
	deviceId = newDeviceId;
	direction = newDirection;
	gpioChannel = newGpioChannel;

	Initialize();
}

/*
 * ~RazorCarGPIO() (Default Destructor)
 */
RazorCarGPIO::~RazorCarGPIO() { }

/*
 * Initialize()
 * Initializes the GPIO port.
 */
int RazorCarGPIO::Initialize(){
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
 * Write()
 * Writes an integer to the GPIO port
 */
void RazorCarGPIO::Write(int data) {
	XGpio_DiscreteWrite(&gpioObj, gpioChannel, data);
}

/*
 * Read()
 * Reads an integer from the GPIO port
 */
int RazorCarGPIO::Read() {
	return XGpio_DiscreteRead(&gpioObj, gpioChannel);
}
