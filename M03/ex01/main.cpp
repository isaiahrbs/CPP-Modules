#include "ScavTrap.hpp"

int	main() {
	ClapTrap a("Bob");
	a.attack("Fanta");
	std::cout << "\n";

	ScavTrap b("Aymeric");
	b.attack("Poo");
	std::cout << "\n";

	ScavTrap c("Caillou");
	c.attack("Pierre");
	c.attack("Pierre");
	c.attack("Pierre");
	c.attack("Pierre");
	c.attack("Pierre");
	a = b;
	a.attack("poo");
	std::cout << "\n";

	ClapTrap d("Bully");
	d.takeDamage(100);
	std::cout << "\n";

	c.guardGate();
	std::cout << "\n";
}