#include "square.h"
#include "uniqueList.h"
#include <math.h>

Square::Square(int tempX, int tempY) : x(tempX), y(tempY), scannedFrom(scannedFrom) {
	for(int i = 0; i < 4; i++) {
		adjacent[i] = 0;
		}
	int numTimesScanned = numTimesFound = 0;
	}

void Square::scanned(bool found, Square* position) {
	Node<Square>* newNode = new Node<Square>(position); // allocated on heap
	scannedFrom.add(newNode); // list takes over control of newNode
	numTimesScanned++;
	if(found) {
		numTimesFound++;
		}
	}

double Square::probability() {
	double totalSquaresScanned = 0; // the total number of squares scanned from each time this square was scanned
	for(int i = 0; i < scannedFrom.length(); i++) {
		totalSquaresScanned += sqrt((x - scannedFrom.get(i)->getData()->x)^2 + (y - scannedFrom.get(i)->getData()->y)^2)/3; // the distance formula over 3
		}
	return double(numTimesFound) / totalSquaresScanned;
	}

bool Square::operator==(const Square& other) {
	return(x == other.x && y == other.y);
	}

bool Square::operator!=(const Square& other) {
	return(!(operator==(other)));
	}

bool Square::operator>(const Square& other) {
	return((x > other.x) || (x == other.x && y > other.y));
	}

bool Square::operator<(const Square& other) {
	return((x < other.x) || (x == other.x && y < other.y));
	}

bool Square::operator>=(const Square& other) {
	return(!(operator<(other)));
	}

bool Square::operator<=(const Square& other) {
	return(!(operator>(other)));
	}
