/** @file */

#ifndef PING_H
#define PING_H

/**
 * Provides an interface to use the ping sensor
 */
class Ping {
	public:
		/**
		 * Initializes pin numbers
		 * @param tempTriggerPin the pin number for the trigger pin
		 * @param tempEchoPin the pin number for the echo pin
		 */
		Ping(int tempTriggerPin, int tempEchoPin);
		/**
		 * Initilizes the pins to be ready to be used. Must be called before any other function and in setup().
		 */
		void init();
		/**
		 * Uses the ping sensor to takes a reading and returns the distance in inches
		 * @return the distance in inches
		 */
		long getInches();
		/**
		 * Uses the ping sensor to takes a reading and returns the distance in centimeters
		 * @return the distance in centimeters
		 */
		long getCentimeters();
	private:
		/**
		 * Uses the ping sensor to takes a reading and returns the distance in microseconds
		 * @return the distance in microseconds
		 */
		long getReading();
		int triggerPin;
		int echoPin;
	};

#endif