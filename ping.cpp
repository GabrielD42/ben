#include <wiringPi.h>
#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

// forward declarations
void safeQuit(int signal);

int main() {
	if(wiringPiSetupGpio() != -1) {
		struct sigaction sigIntHandler;

  	sigIntHandler.sa_handler = safeQuit;
  	sigemptyset(&sigIntHandler.sa_mask);
  	sigIntHandler.sa_flags = 0;

   sigaction(SIGINT, &sigIntHandler, NULL);

		pinMode(0, OUTPUT);
		while(1) {
			digitalWrite(0, HIGH);
			delay(500);
			digitalWrite(0, LOW);
			delay(500);
			}
		return 0;
		}
	else {
		cout << "wiringPi setup failed" << endl;
		exit(1);
		}
	}

void safeQuit(int signal){
	cout << "Caught signal " << signal << endl;
  exit(1);
	}