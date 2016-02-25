/*
 * PathItem.h
 *
 *  Created on: Nov 19, 2015
 *      Author: Fabio
 */

#ifndef PATHITEM_H_
#define PATHITEM_H_

class PathItem {

private:
	int speed;
	int steering;
	int delay;

	static const int delayMultipler = 10000000;

public:
	PathItem();
	PathItem(int newSpeed, int newSteering, int newDelay);
	virtual ~PathItem();

	void setPosition(int newSpeed, int newSteering, int newDelay);

	void setSpeed(int newSpeed);
	void setSterring(int newSteering);
	void setDelay(int newDelay);

	int getSpeed();
	int getSteering();
	int getDelay();
};

#endif /* PATHITEM_H_ */
