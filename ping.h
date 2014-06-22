#ifndef PING_H
#define PING_H

class Ping {
	public:
		Ping(int tempTriggerPin, int tempEchoPin);
		void init();
		long getInches();
		long getCentimeters();
	private:
		long getReading();
		int triggerPin, echoPin;
	};

#endif