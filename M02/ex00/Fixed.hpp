#ifndef FIXED_HPP
#define FIXED_HPP


/*
	in cpp we use the underscore to tell that it is a private variable
*/
class Fixed {
	private:
		int _value;
		static const int _fractionalBits = 8;
	
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		float toFloat()  const;
		int toInt() const;
		~Fixed();
};