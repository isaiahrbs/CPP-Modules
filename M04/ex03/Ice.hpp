#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const& copy);
		Ice &operator=(Ice const& other);
		~Ice();

		std::string const& getType() const;
		AMateria* clone() const;
		void use(ICharacter &target);
};
