/** @file */

#include "main.h"
#include "ping.h"
#include "square.h"
#include "base.h"
#include <iostream>
#include <wiringPi.h>

using namespace std;

Ping sensor(24, 25);

/**
 * called at beginning of execution to initilize everything properly
 */
void setup() {
	sensor.init();
	}

/**
 * called at program end (or interrupt) to clean up any classes that need cleaning up and save any data that need saving
 */
void loop() {
	cout << sensor.getInches() << "in" << endl;
	delay(1000);
	}

/**
 * called at program end (or interrupt) to clean up any classes that need cleaning up and save any data that need saving
 */
void cleanup() {

	}