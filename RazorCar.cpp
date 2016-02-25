/*
 * RazorCar.cpp
 *
 *  Created on: Nov 15, 2015
 *      Author: Fabio
 */

#include "RazorCar.h"
#include "PWMController.h"
#include "configuration.h"
#include "Path.h"

/*
 * RazorCar() (Default Constructor)
 * Initializes the speed and steering controllers
 *
 */
RazorCar::RazorCar() {

	/* Initialize the speed and the steering controllers */
	speedController = PWMController(148, 100, MAX_SPEED, 1, GPIO_DEVICE_ID_speed, DIRECTION_OUTPUT);
	steeringController = PWMController(160, 110, 210, 1, GPIO_DEVICE_ID_steering, DIRECTION_OUTPUT);
	speedController.Initialize();
	steeringController.Initialize();

	speed = STAND_SPEED;
	steering = STAND_STEERING;

	/* Initialize switches */
	switches = RazorCarGPIO(GPIO_DEVICE_ID_switches, DIRECTION_INPUT, 1);

	/* Initialize leds */
	leds = RazorCarGPIO(GPIO_DEVICE_ID_leds, DIRECTION_OUTPUT, 1);

	#ifdef DEBUG
		xil_printf("Car initialized.\r\n");
	#endif
}

/*
 * ~RazorCar() (Destructor)
 */
RazorCar::~RazorCar() { }

/*
 * setStand()
 * Set the car to the stand position. Speed motor off and steering straigh.
 * These constants are defined in the file configuration.h
 *
 */
void RazorCar::setStand(){
	setSpeed(STAND_SPEED);
	setSteering(STAND_STEERING);
}

/*
 * setSpeed(int newSpeed)
 *
 */
void RazorCar::setSpeed(int newSpeed){
	speed = newSpeed;
	speedController.Write(speed);
}

/*
 * setSteering(int newSteering)
 *
 */
void RazorCar::setSteering(int newSteering){
	steering = newSteering;
	steeringController.Write(steering);
}

/*
 * setDelay(int newDelay)
 *
 */
void RazorCar::setDelay(int newDelay){
	delay = newDelay;
}

/*
 * setPath(Path newPath)
 *
 */
void RazorCar::setPath(Path newPath) {
	path = newPath;
}

/*
 * getPath()
 *
 */
Path RazorCar::getPath() {
	return path;
}

/*
 * runPath()
 *
 */
void RazorCar::runPath() {

	int i;

	#ifdef DEBUG
		xil_printf("Starting path.\r\n");
	#endif

	while(!path.empty()){
		setSpeed( path.getPosition().getSpeed() );
		setSteering( path.getPosition().getSteering() );
		setDelay( path.getPosition().getDelay() );

		if (steering > 162) setLED(LED_RIGHT);
		if (steering < 140) setLED(LED_LEFT);
		if (steering > 140 && steering < 162) setLED(LED_OFF);

		xil_printf("Set: speed = %d and steering = %d\r\n", speed, steering);

		Wait(delay);
		path.removePosition();
	}

	#ifdef DEBUG
		xil_printf("Path done. Stopping the car.\r\n");
	#endif
}

/*
 * Stop()
 * Sets the car to the stand position and waits forever.
 *
 */
void RazorCar::Stop() {
	setStand();
	Wait(2);
	setLED(LED_OFF);
	Wait(2);
	setLED(LED_ALL);
}

/*
 * getSwitches()
 * Simply returns the private member switches
 */
RazorCarGPIO RazorCar::getSwitches() {
	return switches;
}

/*
 * Wait()
 * Software delay. Takes and integer as input.
 */
void RazorCar::Wait(int delay) {
	int i, k;

	for (k=0; k<delay*10; k++){
		for (i=0; i<1000000; i++);
	}
}


void RazorCar::setLED(int newLED) {
	leds.Write(newLED);
}
