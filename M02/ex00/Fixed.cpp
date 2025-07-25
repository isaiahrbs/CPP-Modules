#include "Fixed.hpp"
#include <cmath>


/*
	equal to:

	Fixed::Fixed() {
    _value = 0;
}
*/
Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int n) {
	_value = n << _fractionalBits;
}

Fixed::Fixed(const float n) {
	_value = roundf(n * (1 << _fractionalBits));
}

float Fixed::toFloat() const {
	return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt() const {
	return _value >> _fractionalBits;
}

Fixed::~Fixed() {}