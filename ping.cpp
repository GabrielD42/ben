#include <wiringPi.h>
#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

const int echoPin = 25;
const int triggerPin = 24;

void setup() {
	pinMode(triggerPin, OUTPUT);
	pinMode(echoPin, INPUT);
	}

void loop() {
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
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  cout << inches << "in, " << cm << "cm" << endl;

  delay(100);
	}

void cleanup() {
	// nothing to do
	}

/////////////////////////////////////////////
//                                         //
// DON"T TOUCH ANYTHING FROM THIS POINT ON //
//                                         //
/////////////////////////////////////////////

void safeQuit(int signal);

int main() {
	if(wiringPiSetupGpio() != -1) {
		// get set up to catch keyboard interrupts
		struct sigaction sigIntHandler;
  	sigIntHandler.sa_handler = safeQuit;
  	sigemptyset(&sigIntHandler.sa_mask);
  	sigIntHandler.sa_flags = 0;
  	sigaction(SIGINT, &sigIntHandler, NULL);

  	// do arduino stuff
  	setup();
		while(1) {
			loop();
			}

		exit(0) // return with errors (this should never be reached)
		}
	else {
		cout << "wiringPi setup failed" << endl;
		exit(1); // return with errors
		}
	}

// catch keyboard interrupt (ctrl-c)
void safeQuit(int signal){
	cout << "\nCaught signal " << signal << "\nSafely exiting..." << endl;
	cleanup();
  exit(0); // return happily
	}