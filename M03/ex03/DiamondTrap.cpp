#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_trap"), ScavTrap("Default"), FragTrap("Default") {
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	this->name = "Default";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap"), ScavTrap(name), FragTrap(name) {
	std::cout << "DiamondTrap name constructor called : " << name << std::endl;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	this->name = name;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	std::cout << "Copy DiamondTrap constructor copied from : " << other.name << std::endl;
	*this = other;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called." << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "I am : " << this->name << " Inheriting from : " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}
