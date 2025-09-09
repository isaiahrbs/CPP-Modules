#include "ClapTrap.hpp"

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " has been destroyed." << std::endl;
}

ClapTrap::ClapTrap() {
	this->name = "Default";
	this->energyPoints = 10;
	this->hitPoints = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap " << name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(const std::string name) {
	this->name = name;
	this->energyPoints = 10;
	this->hitPoints = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap " << name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    std::cout << "ClapTrap " << name << " copied!" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (hitPoints <= 0 || energyPoints <= 0) {
		std::cout << "ClapTrap " << name << " can't attack, not enough energyPoints" << std::endl;
		return;
	}
	energyPoints = energyPoints - 1;
	std::cout << "ClapTrap " << name << " attacks " << target << ", dealing " << attackDamage << " points of damage! HP: " << hitPoints << " | EP: " << energyPoints << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	hitPoints = hitPoints - amount;
	if (hitPoints < 0)
	hitPoints = 0;
	std::cout << "ClapTrap" << name << " takes " << amount << " points of damage! HP: " << hitPoints << " | EP: " << energyPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints <= 0 || energyPoints <= 0) {
		std::cout << "ClapTrap " << name << " can't repair itself, not enough energyPoints or hitPoints! HP: " << hitPoints << " | EP: " << energyPoints << std::endl;
		return ;
	}
	energyPoints = energyPoints - 1;
	hitPoints = hitPoints + amount;
	std::cout << "ClapTrap " << name << " healed for " << amount << " hitPoints! HP: " << hitPoints << " | EP: " << energyPoints << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap " << name << " copied!" << std::endl;
	return *this;
}
