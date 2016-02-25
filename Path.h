/*
 * Path.h

 *
 *  Created on: Nov 15, 2015
 *      Author: Fabio
 */

#ifndef PATH_H_
#define PATH_H_

#include <queue>
using namespace std;
#include "configuration.h"
#include "PathItem.h"

class Path {

private:
	queue <PathItem> pathQueue;

public:
	Path();
	virtual ~Path();

	void insertPosition(PathItem newPosition);
	void insertPosition(int newSpeed, int newSteering, int newDelay);
	PathItem getPosition();
	void removePosition();

	bool empty();
	void loadTestPath();
	void receivePath();
};

#endif /* PATH_H_ */
