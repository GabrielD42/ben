#include <wiringPi.h>
#include <iostream>

using namespace std;

int main() {
	if(wiringPiSetupGpio() != -1) {
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
		cout << "GPIO pins could not be accessed. Are you running as root?" << endl;
		return -1;
		}
	}