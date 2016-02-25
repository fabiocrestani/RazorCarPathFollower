/*
 * MainClass.cpp
 *
 *  Created on: Nov 13, 2015
 *      Author: Fabio
 */

#include "MainClass.h"

#include "configuration.h"
#include "PWMController.h"
#include "RazorCar.h"
#include "Path.h"
//#include "xuartps.h"

MainClass::MainClass() {

	/* Initializes the car object */
	RazorCar car = RazorCar();

	/* Initializes the path queue */
	Path myPath = Path();
	myPath.loadTestPath();
	//myPath.receivePath();

	/* Waits for the user change the switch state */
	xil_printf("Change the switch to 0 to continue");
	while (car.getSwitches().Read() > 0 ) car.Stop();
	car.setLED(LED_OFF);
	xil_printf("Running the path\r\n");

	/* Assigns the path object to the car */
	car.setPath(myPath);

	/* Wait a few seconds */
	car.Wait(20);

	/* Starts the path */
	car.runPath();

	/* Stops the car */
	xil_printf("bye");
	while(1){
		car.Stop();
	}
}

MainClass::~MainClass() { }
