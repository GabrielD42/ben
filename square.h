#ifndef SQUARE_H
#define SQUARE_H

#include "list.h"

/**
 * Class to hold data about one square in grid
 *
 */
class Square: public Node {
	public:
		Square(int tempX, int tempY);
		void scanned(bool found, Square* position);
		float probability();
		const int x, y;
	private:
		int numTimesScanned, numTimesFound;
		List scannedFrom;
		Square* adjacent[4];
	};

#endif