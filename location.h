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
		/**
		 * checks to see if two Locations are equal by comparing their x and y coordinates
		 *
		 * @param other the Location to compare to this one
		 * @return true if they are equal, false otherwise
		 */
		bool operator==(const Location& other);
		/**
		 * checks to see if two Locations are unequal by taking the opposite of operator==
		 *
		 * @param other the Location to compare to this one
		 * @return true if they aren't equal, false otherwise
		 */
		bool operator!=(const Location& other);
		/**
		 * compares two Locations to determine which is larger. Rather arbitrary, since there is no "true" way to measure this. this implementation sorts by x value, and determines ties with y value
		 *
		 * @param other the Location to compare to this one
		 * @return true if Location invoked upon is smaller than `other`, false otherwise
		 */
		bool operator>(const Location& other);
		/**
		 * compares two Locations to determine which is larger. Rather arbitrary, since there is no "true" way to measure this. this implementation sorts by x value, and determines ties with y value
		 *
		 * @param other the Location to compare to this one
		 * @return true if Location invoked upon is larger than `other`, false otherwise
		 */
		bool operator<(const Location& other);
		/**
		 * compares two Locations to determine which is larger. Rather arbitrary, since there is no "true" way to measure this. this implementation sorts by x value, and determines ties with y value
		 *
		 * @param other the Square to compare to this one
		 * @return true if Square invoked upon is larger than or equal to `other`, false otherwise
		 */
		bool operator>=(const Location& other);
		/**
		 * compares two Locations to determine which is larger. Rather arbitrary, since there is no "true" way to measure this. this implementation sorts by x value, and determines ties with y value
		 *
		 * @param other the Location to compare to this one
		 * @return true if Location invoked upon is smaller than or equal to `other`, false otherwise
		 */
		bool operator<=(const Location& other);
	private:
		const int x;
		const int y;
	};

#endif