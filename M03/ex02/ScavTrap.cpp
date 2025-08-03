#include "ScavTrap.hpp"

/*
ici ce qu'on apprend c'est que quand tu herite dune class, c++ va automatiquement appeller
le constructeur de la class auquel jherite mais il appelle tjr le constructeur vide sans
arguments.
si je veux appeller un avec un argument, je vais devoir le faire moi meme a la fin de la ligne

exemple:
ScavTrap::ScavTrap() : ClapTrap("DefaultScavTrap") {
	
la jai donner un nom donc il va appeller le constructeur avec argument nom
*/

ScavTrap::ScavTrap() : ClapTrap("DefaultScavTrap") {
	this->attackDamage = 20;
	this->energyPoints = 50;
	this->hitPoints	   = 100;
	std::cout << "Default ScavTrap constructor called! HP: " << hitPoints << " | EP: " << energyPoints << std::endl;
}

// je donne un nom a scavtrap qui lui le passe a claptrap
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap "<< this->name << " constructed! HP: " << hitPoints << " | EP: " << energyPoints << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap " << this->name << " copied!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		std::cout << "ScavTrap " << this->name << " destructed!" << std::endl;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " destructed!" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (hitPoints <= 0 || energyPoints <= 0) {
		std::cout << "ScavTrap " << name << " doesn't have enough EP/HP to attack. HP: " << hitPoints << " | EP: " << energyPoints << std::endl;
		return;
	}
	energyPoints = energyPoints - 1;
	std::cout << "ScavTrap " << name << " attacked " << target << " dealing " << attackDamage << " damage. HP: " << hitPoints << " | EP: " << energyPoints << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "idk wtf i hae to insert here but guardgate is done" << std::endl;
}