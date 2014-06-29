#include "square.h"
#include "list.h"

Square::Square(int tempX, int tempY) : x(tempX), y(tempY), scannedFrom(scannedFrom) {
	for(int i = 0; i < 4; i++) {
		adjacent[i] = 0;
		}
	int numTimesScanned = numTimesFound = 0;
	}

void Square::scanned(bool found, Square* position) {
	Node<Square> newNode(position);
	scannedFrom.add(newNode);
	numTimesScanned++;
	if(found) {
		numTimesFound++;
		}
	}

float Square::probability() {
	return float(numTimesFound) / numTimesScanned;
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
