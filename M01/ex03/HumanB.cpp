#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : name(name), weapon(0) {} //sans arme en gros

void	HumanB::setWeapon(Weapon& newWeapon) {
	weapon = &newWeapon;
}

void	HumanB::attack() const {
	if (weapon)
		std::cout << name << " attacks is attacking with : " << weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon to attack with.." << std::endl;
}