#include "location.h"

Location::Location(int tempX, int tempY) : x(tempX), y(tempY) {
	// nothing to see here
	}

int Location::getX() {
	return x;
	}

int Location::getY() {
	return y;
	}

bool Location::operator==(const Location& other) {
	return(x == other.x && y == other.y);
	}

bool Location::operator!=(const Location& other) {
	return(!(operator==(other)));
	}

bool Location::operator>(const Location& other) {
	return((x > other.x) || (x == other.x && y > other.y));
	}

bool Location::operator<(const Location& other) {
	return((x < other.x) || (x == other.x && y < other.y));
	}

bool Location::operator>=(const Location& other) {
	return(!(operator<(other)));
	}

bool Location::operator<=(const Location& other) {
	return(!(operator>(other)));
	}