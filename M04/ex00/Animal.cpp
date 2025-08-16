#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal has been created." << std::endl;
}

Animal::Animal(const Animal &other) {
	std::cout << "Animal copy has been created." << std::endl;
	if (this != &other)
		this->type = other.type;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << "Animal assignment." << std::endl;
	this->type = other.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor call." << std::endl;
}

std::string Animal::getType() const {
	return type;
}

void	Animal::makeSound() const {
	std::cout << "Animal SFX" << std::endl;
}