/** @file */

#include "base.h"
#include <wiringPi.h> // for wiringPiSetupGpio
#include <iostream> // for cout
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

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

		exit(0); // return with errors (this should never be reached)
		}
	else {
		cout << "wiringPi setup failed" << endl;
		exit(1); // return with errors
		}
	}

/**
 * this function is called when main() catches a keyboard interrupt (such as ctrl-c). it calls cleanup() so that all data can be safely saved and memory reclaimed before the program ends.
 *
 * @param signal the interrupt signal
 */
void safeQuit(int signal){
	cout << "\nCaught signal " << signal << "\nSafely exiting..." << endl;
	cleanup();
  exit(0); // return happily
	}