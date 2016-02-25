/*
 * TestBench.h
 *
 *  Created on: Nov 13, 2015
 *      Author: Fabio
 */

#ifndef TESTBENCH_H_
#define TESTBENCH_H_

#include "PWMController.h"
#include "RazorCar.h"

class TestBench {
public:
	TestBench();
	TestBench(RazorCar car);

	virtual ~TestBench();

	void static WaitCOUNT_DELAY();
};

#endif /* TESTBENCH_H_ */
