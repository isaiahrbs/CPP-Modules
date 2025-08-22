#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {
}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {
}

Point& Point::operator=(const Point& other) {
	(void)other;
	return *this;
}

Point::~Point() {
}

Fixed const Point::getX() const {
	return _x;
}

Fixed const Point::getY() const {
	return _y;
}
