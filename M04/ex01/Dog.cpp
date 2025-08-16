#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog has been constructed." << std::endl;
	this->brain = new Brain();	
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Copy Dog has been constructed." << std::endl;
	this->brain = new Brain(*other.brain);
	this->type = other.type;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "DOG: Copy assignment called." << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		this->type = other.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called." << std::endl;
	delete this->brain;
}

void	Dog::makeSound() const {
	std::cout << "Bark!" << std::endl;
}
