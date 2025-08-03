#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#include <iostream>
#include <ostream>


/*
 on apprend l'heritage en cpp ici, tout ce qui est public dans ClapTrap rest public dedans scavtrap.

 on apprend que protected c'est comme private sauf que protected il permet a les class enfants
 de pouvoir acceder a les informations qui sont dedans, si je les met en privé les class
 enfants (ceux qui herite) ne pourront pas acceder a ces informations
*/
class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();

		void guardGate();
		void attack(const std::string &target);
};

#endif