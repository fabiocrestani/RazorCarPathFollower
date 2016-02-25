/*
 * RazorCar.h
 *
 *  Created on: Nov 15, 2015
 *      Author: Fabio
 */

#ifndef RAZORCAR_H_
#define RAZORCAR_H_

#include "PWMController.h"
#include "RazorCarGPIO.h"
#include "Path.h"

class RazorCar {

private:
	PWMController speedController;
	PWMController steeringController;
	RazorCarGPIO  switches;
	RazorCarGPIO  leds;

	int speed;
	int steering;
	int distance;
	int delay;

	Path path;

public:
	RazorCar();
	virtual ~RazorCar();

	void setStand();
	void setSpeed(int newSpeed);
	void setSteering(int newSteering);
	void setDelay(int newDelay);

	void setPath(Path newPath);
	Path getPath();
	void runPath();

	void Stop();

	RazorCarGPIO getSwitches();

	void setLED(int newLED);

	void Wait(int delay);
};

#endif /* RAZORCAR_H_ */
