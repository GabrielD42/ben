#ifndef UTILS_H
#define UTILS_H

/**
 * Utilities namespace
 * contains useful functions that aren't really associated with anything else,
 * such as Arduino-esque functions not included in WiringPi
 */
namespace utils {
	/**
	 * Calculates the length of a pulse on a pin
	 * @param pin the GPIO pin number to watch
	 * @param level what level of pulse to look for. Either HIGH or LOW
	 * @param timeout the maximum length of a pulse
	 * @return the length of the pulse in microseconds
	 */
	long pulseIn(int pin, int level, int timeout);
	}

#endif