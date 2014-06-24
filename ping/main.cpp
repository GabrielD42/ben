#include "main.h"
#include "ping.h"
#include "base.h"
#include <iostream>
#include <wiringPi.h>

using namespace std;

Ping sensor(24, 25);

void setup() {
	sensor.init();
	}

void loop() {
	cout << sensor.getInches() << "in" << endl;
	delay(1000);
	}

void cleanup() {

	}