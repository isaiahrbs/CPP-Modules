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
		Fixed(const Fixed& objcopy);

		/*
			Si je copie la valeur d'un objet a un autre mais les 2 existe deja
			ca appelle ca direction, ca s'appelle un operateur d'affectation
		*/
		Fixed &operator=(const Fixed& other);
		~Fixed();

		int getRawBits() const;
		void setRawBits(const int raw);
};

#endif