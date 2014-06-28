#include "square.h"
#include "list.h"

Square::Square(int tempX, int tempY) : x(tempX), y(tempY), scannedFrom(scannedFrom) {
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

float Square::probability() {
	return float(numTimesFound) / numTimesScanned;
	}

bool Square::operator==(const Square& other) {
	return(this.x == other.x && this.y == other.y);
	}

bool Square::operator!=(const Square& other) {
	return(!(operator==(other)));
	}

bool Square::operator>(const Square& other) {
	return((this.x > other.x) ? true : ((this.y > other.y) ? true : false));
	}

bool Square::operator<(const Square& other) {
	return((this.x < other.x) ? true : ((this.y < other.y) ? true : false));
	}

bool Square::operator>=(const Square& other) {
	return(!(operator<(other)));
	}

bool Square::operator<=(const Square& other) {
	return(!(operator>(other)));
	}
