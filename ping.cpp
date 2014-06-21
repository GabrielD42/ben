#include <wiringPi.h>
#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

using namespace std;

const int echoPin = 25;
const int triggerPin = 24;

long microsecondsToInches(long microseconds);
long microsecondsToCentimeters(long microseconds);
long pulseIn(int pin, int level, int timeout);

PI_THREAD(myThread) {
	while(1) {
		delay(1000);
		cout << "in myThread" << endl;
		}
	}

void setup() {
	pinMode(triggerPin, OUTPUT);
	pinMode(echoPin, INPUT);

	newThread = piThreadCreate(myThread);
	if(newThread != 0) {
		cout << "thread creation failed :(" << endl;
		}
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
  duration = pulseIn(echoPin, HIGH, 100000L);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  cout << inches << "in, " << cm << "cm" << endl;

  delay(100);
	}

void cleanup() {
	// nothing to do
	}

long microsecondsToInches(long microseconds)	{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
	}

long microsecondsToCentimeters(long microseconds)	{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
	}

long pulseIn(int pin, int level, int timeout)	{
	struct timeval tn, t0, t1;
  long micros;

  gettimeofday(&t0, NULL);

  micros = 0;
  while (digitalRead(pin) != level)	{
	  gettimeofday(&tn, NULL);

    if (tn.tv_sec > t0.tv_sec) micros = 1000000L; else micros = 0;
	    micros += (tn.tv_usec - t0.tv_usec);

    if (micros > timeout)
    	return 0;
   	}

  gettimeofday(&t1, NULL);

  while (digitalRead(pin) == level)	{
		gettimeofday(&tn, NULL);

    if (tn.tv_sec > t0.tv_sec) micros = 1000000L; else micros = 0;
  	  micros = micros + (tn.tv_usec - t0.tv_usec);

    if (micros > timeout)
    	return 0;
   	}

  if (tn.tv_sec > t1.tv_sec) micros = 1000000L; else micros = 0;
  micros = micros + (tn.tv_usec - t1.tv_usec);

  return micros;
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

		exit(0); // return with errors (this should never be reached)
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