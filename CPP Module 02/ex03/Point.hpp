#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point(/* args */);
		~Point();
		Point(const Point& other);
		Point(const Fixed _x, const Fixed _y);
		Point& operator=(const Point& other);
		const Fixed& getX() const;
		const Fixed& getY() const;
	private:
		Fixed const x;
		Fixed const y;
};


#endif