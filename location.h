#ifndef LOCATION_H
#define LOCATION_H

/**
 * Describes a location or coordinate on a plane. Values are fixed.
 */
class Location {
	public:
		/**
		 * intializes coordinates from parameters
		 *
		 * @param tempX the x coordinate
		 * @param tempY the y coordinate
		 */
		Location(int tempX, int tempY);
		/**
		 * accessor method for the x coordinate
		 * @return the x coordinate
		 */
		int getX();
		/**
		 * accessor method for the y coordinate
		 * @return the y coordinate
		 */
		int getY();
	private:
		const int x;
		const int y;
	};

#endif