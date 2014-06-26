/** @file */

#include "main.h"
#include "ping.h"
#include "square.h"
#include "base.h"
#include <iostream>
#include <wiringPi.h>

using namespace std;

Square square(0, 0);
Square from(3, 4);
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
	long reading = sensor.getInches();
	bool found = false;
	if(reading >= 4.5 && reading <= 5.5) {
		found = true;
		}
	square.scanned(found, &from);
	cout << sensor.getInches() << "in" << endl;
	delay(1000);
	}

/**
 * called at program end (or interrupt) to clean up any classes that need cleaning up and save any data that need saving
 */
void cleanup() {

	}