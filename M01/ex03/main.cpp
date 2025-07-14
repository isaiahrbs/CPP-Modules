#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main()
{
	Weapon club("crude spiked club");
	HumanA bob("Bob", club);
	HumanB jim("Jim");

	bob.attack();
	jim.attack();

	club.setType("Bigger club");

	bob.attack();
	jim.setWeapon(club);
	jim.attack();

	return 0;
}