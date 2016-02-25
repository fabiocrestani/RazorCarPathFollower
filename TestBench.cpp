/*
 * TestBench.cpp
 *
 *  Created on: Nov 13, 2015
 *      Author: Fabio
 */

/*
 * *****************************************************************************
 * This file is not actually being used in this version of the program.
 * Check the file MainClass.cpp to see how the car and the path are initialized.
 * *****************************************************************************
 */

#include "TestBench.h"
#include "configuration.h"

TestBench::TestBench() { }

TestBench::TestBench(RazorCar car) { }

TestBench::~TestBench() { }

void TestBench::WaitCOUNT_DELAY(){
	volatile int Delay;
	for (Delay = 0; Delay < COUNT_DELAY; Delay++);
}
