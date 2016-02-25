/*
 * PathItem.cpp
 *
 *  Created on: Nov 15, 2015
 *      Author: Fabio
 */

#include "PathItem.h"
#include "configuration.h"

/*
 * PathItem()
 * Default constructor
 */
PathItem::PathItem() {
	speed = STAND_SPEED;
	steering = STAND_STEERING;
	delay = 1;
}

/*
 * PathItem(int newSpeed, int newSteering, int newDelay)
 * Overloaded constructor that sets speed, steering and delay
 */
PathItem::PathItem(int newSpeed, int newSteering, int newDelay){
	setPosition(newSpeed, newSteering, newDelay);
}

/*
 * ~PathItem() (Default Destructor)
 *
 */
PathItem::~PathItem() { }

/*
 * setPosition(int newSpeed, int newSteering, int newDelay)
 *
 */
void PathItem::setPosition(int newSpeed, int newSteering, int newDelay){

	if (newSpeed > MAX_SPEED) newSpeed = MAX_SPEED;

	if (newDelay <= 0) newDelay = 4;
	delay = newDelay;

	speed = newSpeed;
	steering = newSteering;
}

/*
 * setSpeed(int newSpeed)
 *
 */
void PathItem::setSpeed(int newSpeed) {
	speed = newSpeed;
}

/*
 * setSteering(int newSteering)
 *
 */
void PathItem::setSterring(int newSteering) {
	steering = newSteering;
}

/*
 * setDelay(int newDelay)
 *
 */
void PathItem::setDelay(int newDelay) {
	delay = newDelay * delayMultipler;
}

/*
 * getSpeed()
 *
 */
int PathItem::getSpeed() {
	return speed;
}

/*
 * getSteering()
 *
 */
int PathItem::getSteering() {
	return steering;
}

/*
 * getDelay()
 *
 */
int PathItem::getDelay() {
	return delay;
}
