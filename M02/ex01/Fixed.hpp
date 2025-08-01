#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

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
		int	  toInt() const;
};

/*
	si je veux faire std::cout << a << std::endl; c++ va pas comprendre
	car "a" c'est un objet donc la je suis entrain de dire comment
	imprimer lobjet.
	en gros il va retourner un trc

	std::ostream est le type général pour tous les flux de sortie (pas seulement le terminal, ça peut être un fichier, etc.).
	
	It sends std::cout as the first parameter (out).
	It sends your object a as the second parameter (value).
	Example: std::cout, a file, or any other output stream.
	When you write std::cout << a;, std::cout is passed as this parameter.
	*/
std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif