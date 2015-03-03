BEN
===

This repository contains code that will (hopefully) one day become a robot. BEN stands for **B**right **E**nough to **N**avigate. BEN has a multi-step goal:

1. Navigate to a sector in his world. At this point he does not know where any obstacles are
2. Search the sector for a small object, identified by comparing it to pictures it has taken
3. Pick up the object and return to his starting position on the shortest path


##ping sensor
scans continuously as long as robot is not moving
* stores trigger pin number
* stores echo pin number
* gives distance

##grid
2d linked-list of squares

* controls access (mutex)
* adds rows and columns

when written to by sensor processing thread, passes copy to a*/search thread


##square
* number of times scanned
* number of times object found here
* linked list of coordinates that this square has been scanned from
* x coordinate
* y coordinate

##mysql
###maps database
stores maps from each run for analyzing. each table is one map, with each field being the probability (a number from 0-1) of there being an object there.

##global variables
stores information about the current run that needs to be dealt with in `cleanup()`.
####ping readings
time               | distance      | sensor number
------------------ | ------------- | -------------
time (primary key) | float (in cm) | int (0-7)
####robot locations
time               | x               | y
------------------ | --------------- | ---------------
time (primary key) | int (of center) | int (of center)
####best route
breakpoint pointer

order              |  x                |  y               | executed
------------------ | ----------------- | ---------------- | --------
int (primary key)  | int (of center)   | int (of center)  | boolean

##threads
in order of priority

* 1 thread for bump sensors
* 1 main thread
* 1 thread for movement
* 1 control thread sensors
* 4 threads for ping sensors
	* they will alternate between sensors
* 1 thread for processing sensor data
* 1 thread for finding best path
* 1 thread for machine learning

##movement
8 directions
pulls of next instruction from best route table and moves there.
if empty, runs a turn-scan-turn-scan subroutine
Sends signals to sensor threads when turning (control sensor threads) to pause

##A*/search thread
a*/search bool
a* function
	input: grid
	output: best route table
	sets breakpoint
search
	use a* to go to closest unexplored space