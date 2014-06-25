BEN
===

The code controlling the Raspberry Pi on my robot, BEN (Bright Enough to Navigate)

##ping sensor
* stores trigger pin number
* stores echo pin number
* gives distance

##grid
2d linked-list of squares

* controls access (mutex)
* adds rows and columns

##square
* number of times scanned
* number of times object found here
* linked list of coordinates that this square has been scanned from
* x coordinate
* y coordinate

##mysql
###maps database
stores maps from each run for analyzing. each table is one map, with each field being the probability (a number from 0-1) of there being an object there.

###current database
stores information about the current run that needs to be dealt with in `cleanup()`.


##threads
in order of priority

* 1 thread for bump sensors
* 1 main thread
* 1 thread for movement
* 4 threads for ping sensors
	* they will alternate between sensors
* 1 thread for processing sensor data
* 1 thread for finding best path
* 1 thread for machine learning