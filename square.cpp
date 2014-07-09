#include "square.h"
#include "uniqueList.h"
#include <math.h>

Square::Square(int tempX, int tempY) : x(tempX), y(tempY), scannedFrom(false) {
	for(int i = 0; i < 4; i++) {
		adjacent[i] = 0;
		}
	int numTimesScanned = numTimesFound = 0;
	}

void Square::scanned(bool found, Square* position) {
	scannedFrom.add(position);
	numTimesScanned++;
	if(found) {
		numTimesFound++;
		}
	}

double Square::probability() {
	return 0.0;
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
