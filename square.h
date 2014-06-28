#ifndef SQUARE_H
#define SQUARE_H

#include "list.h"
#include "node.h"
class Grid;

/**
 * Class to hold data about one square in grid. Descended from Node so that a List of `Square`'s can be made
 */
class Square: public Node {
	friend class Grid;
	public:
		/**
		 * initializes the new square object with itx coordinates
		 *
		 * @param tempX this square's x coordinate
		 * @param tempY this square's y coordinate
		 */
		Square(int tempX, int tempY);
		/**
		 * this function should be called after this square has been scanned by a ping sensor to store the relevent information
		 *
		 * @param found was an object found here?
		 * @param position the Square that the ping sensor was at when it scanned this Square
		 */
		void scanned(bool found, Square* position);
		/**
		 * returns the probability of there being an object here
		 * @return the probability as a decimal from 0 to 1
		 */
		float probability();
		const int x, y;

		bool operator==(const Square& other);
		bool operator!=(const Square& other);
		bool operator>(const Square& other);
		bool operator<(const Square& other);
		bool operator>=(const Square& other);
		bool operator<=(const Square& other);
	private:
		int numTimesScanned, numTimesFound;
		List scannedFrom;
		Square* adjacent[4];
	};

#endif