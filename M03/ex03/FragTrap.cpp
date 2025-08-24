#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("DefaultFragTrap") {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "Default FragTrap constructor called! HP: " << hitPoints << " | EP: " << energyPoints << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " constructed! HP: " << hitPoints << " | EP: " << energyPoints << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	*this = other;
	std::cout << "FragTrap " << this->name << " copied!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap " << this->name << " assigned!" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " destructed!" << std::endl;
}

void FragTrap::attack(const std::string &target) {
	if (hitPoints <= 0 || energyPoints <= 0) {
		std::cout << "FragTrap " << name << " can't attack, not enough EP/HP. HP: " << hitPoints << " | EP: " << energyPoints << std::endl;
		return;
	}
	energyPoints--;
	std::cout << "FragTrap " << name << " attacks " << target << ", dealing " << attackDamage << " points of damage! HP: " << hitPoints << " | EP: " << energyPoints << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << " requests a high five! ✋" << std::endl;
}