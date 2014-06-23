#include "ping.h"
#include "utils.h" // for pulseIn
#include <wiringPi.h> // for digitalWrite, delayMicroseconds

Ping::Ping(int tempTriggerPin, int tempEchoPin) {
	triggerPin = tempTriggerPin;
	echoPin = tempEchoPin;
	}

void Ping::init() {
	pinMode(triggerPin, OUTPUT);
	pinMode(echoPin, INPUT);
	}

long Ping::getInches() {
	return getReading() / 74 / 2;
	}

long Ping::getCentimeters() {
	return getReading() / 29 / 2;
	}

long Ping::getReading() {
	long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerPin, LOW);

  // The echo pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  duration = utils::pulseIn(echoPin, HIGH, 100000L);

  return duration;
	}