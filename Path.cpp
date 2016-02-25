/*
 * Path.cpp
 *
 *  Created on: Nov 15, 2015
 *      Author: Fabio
 */

#include <stdio.h>

#include <iostream>
using namespace std;
#include "configuration.h"
#include "RazorCar.h"
#include "Path.h"
#include "PathItem.h"

#include "xparameters.h"
#include "xgpio.h"

/*
 * Path() (Default constructor)
 * Creates the object Path and adds a stand state PathItem to the queue
 */
Path::Path() {
	/* Inserts in the queue a stand state */
	PathItem initialItem = PathItem(STAND_SPEED, STAND_STEERING, STD_DELAY);
	insertPosition(initialItem);
}

/*
 * ~Path() (Default destructor)
 */
Path::~Path() { }

/* insertPosition(PathItem newPosition)
 * Inserts a PathItem object into the queue
 */
void Path::insertPosition(PathItem newPosition) {
	pathQueue.push(newPosition);
}

/* insertPosition(int newSpeed, int newSteering, int newDelay)
 * Overloaded version of insertPosition. It does the following:
 * 1. Takes speed, steering, and delay;
 * 2. Creates a new PathItem object.
 * 3. Inserts into the queue
 */
void Path::insertPosition(int newSpeed, int newSteering, int newDelay) {
	PathItem tempPath = PathItem(newSpeed, newSteering, newDelay);
	pathQueue.push(tempPath);
}

/* getPosition()
 * Retrieves the item at the top of the queue, but does not remove it
 */
PathItem Path::getPosition(){
	return pathQueue.front();
}

/*
 * removePosition()
 * Remove the item.
 * It should be used after a getPosition() call
 */
void Path::removePosition() {
	if (!pathQueue.empty())
		pathQueue.pop();
}

/*
 * empty()
 * Encapsulates the <queue>.empty() method.
 */
bool Path::empty() {
	return pathQueue.empty();
}

/*
 * loadTestPath()
 * Loads a test path
 */
void Path::loadTestPath() {
	insertPosition(166, 146, 20);
	insertPosition(110, 146, 5);
	insertPosition(162, 170, 15);
	insertPosition(164, 110, 6);
	insertPosition(165, 146, 5);
	insertPosition(165, 130, 5);
	insertPosition(165, 146, 5);
}

void Path::receivePath() {
/*	int speed = STAND_SPEED;
	int steering = STAND_STEERING;
	int delay = 5;
	int stopFlag = 0;
	char c;

	//Xuint8 c;

	while (stopFlag == 0) {
		xil_printf("\nEnter the next speed: ");

		speed = 0;
		//while(speed == 0)
		//	speed = XUartLite_RecvByte(XPAR_PS7_UART_1_BASEADDR);

		xil_printf("speed  : %d\r\n", speed);



		if (speed != 0) {
			xil_printf("\nEnter the next steering: ");
			// TODO: get data from UART
			cin >> steering;
		}
		else stopFlag = 1;

		if (steering != 0) {
			xil_printf("\nEnter the delay time: ");
			cin >> delay;
		}
		else stopFlag = 1;

		if (delay != 0)
			insertPosition(speed, steering, delay);
		else
			stopFlag = 1;
	}*/
}
