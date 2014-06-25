BEN
===

The code controlling the Raspberry Pi on my robot, BEN (Bright Enough to Navigate)

##ping sensor
* stores trigger pin number
* stores echo pin number
* gives distance

##world
* 2d linked-list of squares

##square
* number of times scanned
* number of times object found here
* linked list of coordinates that this square has been scanned from
* x coordinate
* y coordinate

##mysql
* stores maps from each run

##threads
in order of priority
* 1 thread for bump sensors
* 1 main thread
* 1 thread for movement
* 8 threads for ping sensors
* 1 thread for processing sensor data
* 1 thread for finding best path
* 1 thread for machine learning