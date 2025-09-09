#include "ScavTrap.hpp"

int main() {
	ClapTrap f("Fanta");
	ClapTrap b("Bob");

	std::cout << std::endl;

	f.attack("Bob");

	std::cout << std::endl;
	ScavTrap d("Dimicouille");
	ScavTrap i("Isa");
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	d.attack("Isa");
	std::cout << std::endl;
	std::cout << std::endl;
	i.takeDamage(20);
	i.beRepaired(10);
	i.guardGate();

}