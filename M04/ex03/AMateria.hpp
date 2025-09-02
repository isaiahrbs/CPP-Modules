#pragma once
#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria();
		AMateria(AMateria const& copy);
		AMateria(std::string const& type);
		AMateria& operator=(AMateria const& other);
		virtual ~AMateria();

		std::string const& getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
