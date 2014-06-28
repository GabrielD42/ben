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

void test(Square& other) {
	cout << "Comparing (" << square.x << ", " << square.y << ") to (" << other.x << ", " << other.y << ")" << endl;
	cout << "== "<< square == other << endl;
	cout << "!= "<< square != other << endl;
	cout << "< "<< square < other << endl;
	cout << "> "<< square > other << endl;
	cout << "<= "<< square <= other << endl;
	cout << ">= "<< square >= other << endl;
	}

/**
 * called at beginning of execution to initilize everything properly
 */
void setup() {
	sensor.init();
	Square one(0, 2);
	Square two(2, 0);
	Square three(0, -2);
	Square four(-2, 0);
	Square five(0, 0);
	Square six(2, 2);
	Square seven(-2, -2);
	Square eight(2, -2);
	Square nine(-2, 2);
	test(one);
	test(two);
	test(three);
	test(four);
	test(five);
	test(six);
	test(seven);
	test(eight);
	test(nine);
	}

/**
 * called at program end (or interrupt) to clean up any classes that need cleaning up and save any data that need saving
 */
void loop() {
	// int reading = sensor.getInches();
	// bool found = false;
	// if(reading == 5) {
	// 	found = true;
	// 	}
	// square.scanned(found, &from);
	// cout << sensor.getInches() << "in" << endl;
	// delay(1000);
	}

/**
 * called at program end (or interrupt) to clean up any classes that need cleaning up and save any data that need saving
 */
void cleanup() {

	}