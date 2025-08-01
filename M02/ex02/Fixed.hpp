#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

/*
	in cpp we use the underscore to tell that it is a private variable
*/
class Fixed {
	private:
		int _value;
		static const int _fractionalBits = 8;
	
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& objcopy);
		Fixed &operator=(const Fixed& other);
		~Fixed();

		int getRawBits() const;
		void setRawBits(const int raw);
		float toFloat() const;
		int   toInt() const;

		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif