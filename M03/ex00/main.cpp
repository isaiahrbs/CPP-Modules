#include "ClapTrap.hpp"

int main() {
	//creating the 2 claptraps
	ClapTrap clapTrap1("ClapTrap1");
	ClapTrap clapTrap2;
	ClapTrap clapTrap3;

	
	// attacking test
	std::cout << std::endl;
	clapTrap1.attack("Claptrap2");
	clapTrap2.takeDamage(10);

	std::cout << std::endl;

	clapTrap2.attack("clapTrap1");
	clapTrap1.takeDamage(5);
	std::cout << std::endl;

	// repair test
	std::cout << std::endl;
	clapTrap2.beRepaired(3);
	std::cout << std::endl;
	
	// operator
	std::cout << std::endl;
	clapTrap3 = clapTrap1;
	std::cout << std::endl;

	std::cout << std::endl;
	clapTrap3.debug(clapTrap3);
	std::cout << std::endl;

	// spam attack test
	std::cout << std::endl;
	for (int i = 0; i < 10; i++) {
		clapTrap1.attack("ClapTrap2");
		std::cout << std::endl;
		clapTrap2.takeDamage(10);
	}
	std::cout << std::endl;

	std::cout << std::endl;
	clapTrap1.debug(clapTrap3);
	std::cout << std::endl;

	std::cout << std::endl;
	clapTrap2.debug(clapTrap3);
	std::cout << std::endl;
}