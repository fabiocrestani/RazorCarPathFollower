/*
 * configuration.h
 *
 *  Created on: Nov 13, 2015
 *      Author: Fabio
 */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

/* AXI GPIO General Configuration */
#define GPIO_DEVICE_ID_steering  XPAR_AXI_GPIO_0_DEVICE_ID
#define GPIO_DEVICE_ID_speed     XPAR_AXI_GPIO_1_DEVICE_ID
#define GPIO_DEVICE_ID_switches  XPAR_AXI_GPIO_2_DEVICE_ID
#define GPIO_DEVICE_ID_leds      XPAR_AXI_GPIO_3_DEVICE_ID

#define DIRECTION_INPUT  0xFF
#define DIRECTION_OUTPUT 0x00

/* Speed module configuration */
#define MAX_SPEED 170
#define STAND_SPEED 148
#define STAND_STEERING 160
#define STD_DELAY 4

/* Delay time definition */
#define COUNT_DELAY 40000000

/* Recording path configuration */
#define queueMAXSIZE 100

/* Switches states */
#define SWITCHES_READING_PATH 0x01
#define SWITCHES_RUN_PATH     0x00

/* LEDs states */
#define LED_LEFT  0x06
#define LED_RIGHT 0x09
#define LED_ALL   0xFF
#define LED_OFF   0x00

/* Enables debugging messages */
#define DEBUG 1

#endif /* CONFIGURATION_H_ */
