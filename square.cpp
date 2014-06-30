#include "square.h"
#include "list.h"
#include <iostream>

using namespace std;

Square::Square(int tempX, int tempY) : x(tempX), y(tempY), scannedFrom(scannedFrom) {
	for(int i = 0; i < 4; i++) {
		adjacent[i] = 0;
		}
	int numTimesScanned = numTimesFound = 0;
	}

void Square::scanned(bool found, Square* position) {
	cout << "in Square::scanned()" << endl;
	Node<Square>* newNode = new Node<Square>(position); // allocated on heap
	scannedFrom.add(newNode); // list takes over control of newNode
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
