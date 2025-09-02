#include "Character.hpp"

const std::string& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* power) {
	if (!power)
	return;
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = power;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4)
		return;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4)
		return;
	if (_inventory[idx])
		_inventory[idx]->use(target);
}

bool Character::inInventory(AMateria* ref) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == ref)
			return true;
	}
	return false;
}

Character::Character() {
	std::cout << "Character constructor called." << std::endl;
}

Character::Character(const std::string& name) {
	_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character constructor called with name: " << name << std::endl;
}

Character::Character(Character const &copy) : _inventory() {
	_name = copy._name;
	for (int i = 0; i < 4; i++) {
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	std::cout << "Character copied" << std::endl;
}

Character& Character::operator=(const Character& other) {
	std::cout << "Character assignment operator called." << std::endl;
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < 4; i++) {
			if (_inventory[i])
				delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
	std::cout << "Character destructor called." << std::endl;
}